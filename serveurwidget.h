#ifndef SERVEURWIDGET_H
#define SERVEURWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Server;

class ServeurWidget : public QWidget
{
    Q_OBJECT
public:
    ServeurWidget(QWidget *parent = Q_NULLPTR, Server *serveur = 0);

    void setJoueur(QString pseudo, quint16 numero);
    void updateClients();

private slots:
    void lancerPartie();

private:
    QLabel *ip_serveur, *port_serveur;
    QList<QLabel*> joueurs;
    QPushButton *demarrer_bouton;
    Server *serveur;
};

#endif // SERVEURWIDGET_H
