#include "client.h"
#include <QHostAddress>
#include <QTcpSocket>
#include <iostream>
#include "clientwidget.h"

Client::Client(QObject* parent): Connexion(parent)
{
    client = new QTcpSocket(this);
    connect(client, SIGNAL(connected()),
            this, SLOT(verifierConnexion()));
    connect(client, SIGNAL(error(QAbstractSocket::SocketError))
            , this, SLOT(erreurConnexion()));
}

Client::~Client()
{
    client->close();
}

void Client::start(QString address, quint16 port, QString pseudo)
{
    QHostAddress addr(address);
    client->connectToHost(addr, port);
    this->pseudo = pseudo;
}

void Client::verifierConnexion() {
    char buffer[4] = {0};

    client->read(buffer, client->bytesAvailable());

    if (strcmp(buffer,"nop") == 0)
        cw->setEtat("Connexion refusée, trop de joueurs");
    else {
        client->write(this->pseudo.toStdString().c_str(),sizeof(this->pseudo.toStdString().c_str()));
        cw->setEtat("Connexion réussie, en attente du lancement");
    }
}

void Client::close()
{
    client->close();
}

void Client::erreurConnexion()
{
    std::cout << "erreur dans la connexion " << std::endl;
}
