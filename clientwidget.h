#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class Client;

class ClientWidget : public QWidget
{
    Q_OBJECT
public:
    ClientWidget(QWidget *parent = Q_NULLPTR, Client *client = 0);

    void setEtat(QString etat);
    QLabel *getEtat();

private slots:
    void checkSaisie();
    void startConnexion();
    void closeConnexion();

private:
    QLineEdit *pseudo;
    QLineEdit *ip_serveur, *port_serveur;
    QLabel *etat_connexion;
    QPushButton *connexion_bouton;
    Client *client;
};

#endif // CLIENTWIDGET_H
