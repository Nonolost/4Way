#ifndef SERVEURWIDGET_H
#define SERVEURWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "gamewindow.h"

class Server;

class ServeurWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief ServeurWidget::ServeurWidget
     * @param parent
     * @param serveur pointeur sur l'objet Server du programme
     */
    ServeurWidget(QWidget *parent = Q_NULLPTR, Server *serveur = 0);

    /**
     * @brief ServeurWidget::setJoueur
     * @param pseudo nom du joueur
     * @param numero numero du joueur
     * affiche que le joueur est connecté et active le bouton "Lancer partie" si 3 joueurs sont connectés
     */
    void setJoueur(QString pseudo, quint16 numero);
    void updateClients();

    inline GameWindow* getGW() { return gw; }

private slots:
    /**
     * @brief ServeurWidget::lancerPartie
     * initialise la partie en ouvre la fenetre GameWindow
     */
    void lancerPartie();

private:
    QLabel *ip_serveur, *port_serveur;
    QList<QLabel*> joueurs;
    QPushButton *demarrer_bouton;
    Server *serveur;

    GameWindow *gw;
};

#endif // SERVEURWIDGET_H
