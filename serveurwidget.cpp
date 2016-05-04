#include "serveurwidget.h"
#include "server.h"

#include <QBoxLayout>
#include <string>

#include "menuwindow.h"
/**
 * @brief ServeurWidget::ServeurWidget
 * @param parent
 * @param serveur pointeur sur l'objet Server du programme
 */
ServeurWidget::ServeurWidget(QWidget *parent, Server *serveur)
    : QWidget(parent)
{
    this->serveur = serveur;

    serveur->setServeurWidget(this);

    QBoxLayout *vlay = new QHBoxLayout(this);

    ip_serveur = new QLabel(this);
    ip_serveur->setText("Votre addresse ip : " + serveur->getAdresseIP());

    port_serveur = new QLabel(this);
    port_serveur->setText("Votre port : " + QString::number(serveur->getPort()));

    joueurs.append(new QLabel("Pas de joueur 1"));
    joueurs.append(new QLabel("Pas de joueur 2"));
    joueurs.append(new QLabel("Pas de joueur 3"));

    demarrer_bouton = new QPushButton("Lancer partie");
    demarrer_bouton->setEnabled(false);
    connect(demarrer_bouton, SIGNAL(clicked(bool)), this, SLOT(lancerPartie()));

    vlay->addWidget(ip_serveur);
    vlay->addWidget(port_serveur);
    vlay->addWidget(joueurs.at(0));
    vlay->addWidget(joueurs.at(1));
    vlay->addWidget(joueurs.at(2));
    vlay->addWidget(demarrer_bouton);

    setLayout(vlay);
}
/**
 * @brief ServeurWidget::setJoueur
 * @param pseudo nom du joueur
 * @param numero numero du joueur
 * affiche que le joueur est connecté et active le bouton "Lancer partie" si 3 joueurs sont connectés
 */
void ServeurWidget::setJoueur(QString pseudo, quint16 numero)
{
    joueurs.at(numero)->setText(pseudo + " connecté");

    demarrer_bouton->setEnabled(serveur->getPseudosClients()->size() == 3);
}

/**
 * @brief ServeurWidget::updateClients
 */
void ServeurWidget::updateClients()
{
    int i;
    for (i =0; i < serveur->getPseudosClients()->size(); i++) {
        joueurs.at(i)->setText(serveur->getPseudosClients()->at(i)+ " connecté");
    }

    for (;i<3;i++) {
        joueurs.at(i)->setText("Pas de joueur " + QString::fromStdString(std::to_string(i+1)));
    }

    demarrer_bouton->setEnabled(serveur->getPseudosClients()->size() == 3);
}
/**
 * @brief ServeurWidget::lancerPartie
 * initialise la partie en ouvre la fenetre GameWindow
 */
void ServeurWidget::lancerPartie()
{
    gw = new GameWindow(0, serveur, 4);
    serveur->envoyerInstructionDemarrerPartie();

    gw->show();
    serveur->initGame(gw->getGame());
    serveur->initThreads();
}

