#include "clientwidget.h"
#include "client.h"
#include <QBoxLayout>
#include <QLabel>
#include <iostream>

/**
 * @brief ClientWidget::ClientWidget
 * @param parent
 * @param client objet Client lié au Widget
 */
ClientWidget::ClientWidget(QWidget *parent, Client *client)
    : QWidget(parent)
{
    this->client = client;

    QBoxLayout *vlay = new QVBoxLayout(this);

    QBoxLayout *vlay_pseudo = new QHBoxLayout();
    pseudo = new QLineEdit();
    connect(pseudo, SIGNAL(textEdited(QString)), this, SLOT(checkSaisie()));

    vlay_pseudo->addWidget(new QLabel("Votre pseudo : "));
    vlay_pseudo->addWidget(pseudo);

    QBoxLayout *vlay_ip = new QHBoxLayout;
    ip_serveur = new QLineEdit();
    connect(ip_serveur, SIGNAL(textEdited(QString)), this, SLOT(checkSaisie()));

    vlay_ip->addWidget(new QLabel("IP hôte : "));
    vlay_ip->addWidget(ip_serveur);

    QBoxLayout *vlay_port = new QHBoxLayout();
    port_serveur = new QLineEdit();
    connect(port_serveur, SIGNAL(textEdited(QString)), this, SLOT(checkSaisie()));

    vlay_ip->addWidget(new QLabel("Port hôte : "));
    vlay_ip->addWidget(port_serveur);

    connexion_bouton = new QPushButton("Connexion à l'hôte");
    connexion_bouton->setEnabled(false);
    connect(connexion_bouton, SIGNAL(clicked(bool)), this, SLOT(startConnexion()));

    vlay->addLayout(vlay_pseudo);
    vlay->addLayout(vlay_ip);
    vlay->addLayout(vlay_port);
    vlay->addWidget(connexion_bouton);
    // test
    QPushButton *close = new QPushButton("ferme connexion");
    connect(close, SIGNAL(clicked(bool)), this, SLOT(closeConnexion()));
    vlay->addWidget(close);

    etat_connexion = new QLabel("Pas connecté");
    vlay->addWidget(etat_connexion);

    setLayout(vlay);
}

/**
 * @brief ClientWidget::checkSaisie
 * verifie si les information on été rentré pour activer le bouton de validation
 */
void ClientWidget::checkSaisie()
{
    if (ip_serveur->text() != "" && port_serveur->text() != "" && pseudo->text() != "")
        connexion_bouton->setEnabled(true);
    else
        connexion_bouton->setEnabled(false);
}

/**
 * @brief ClientWidget::startConnexion
 * essaye de se connecter au serveur
 */
void ClientWidget::startConnexion()
{
    client->start(ip_serveur->text(), port_serveur->text().toUInt(), pseudo->text());
}

/**
 * @brief ClientWidget::closeConnexion
 */
void ClientWidget::closeConnexion()
{
    client->close();
}

/**
 * @brief ClientWidget::setEtat
 * @param etat
 */
void ClientWidget::setEtat(QString etat)
{
}
