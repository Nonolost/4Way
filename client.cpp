#include "client.h"
#include <QHostAddress>
#include <QTcpSocket>
#include <iostream>
#include "clientwidget.h"

Client::Client(QObject* parent): Connexion(parent), blockSize(0)
{
    client = new QTcpSocket(this);
    //connect(client, SIGNAL(connected()),
    //        this, SLOT(verifierConnexion()));
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
    connect(client, SIGNAL(readyRead()), this, SLOT(recevoirInstruction()));

    this->pseudo = pseudo;
}

void Client::verifierConnexion(const char* buffer) {
    if (strcmp(buffer,"nop") == 0)
        cw->setEtat("Connexion refusée, trop de joueurs");
    else {

        char buffer[1020] = {0};
        strcpy(buffer,std::to_string(0).c_str());
        strcat(buffer,";");
        strcat(buffer,this->pseudo.toStdString().c_str());

        client->write(buffer,sizeof(buffer));

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

/*
void Client::recevoirInstruction()
{
    char buffer[1] = {0};
    client->read(buffer, client->bytesAvailable());


}*/

void Client::recevoirInstruction()
{
    char buffer[1020] = {0};

    client->read(buffer, client->bytesAvailable());

    analyserInstruction(QString::fromUtf8(buffer));
}

void Client::analyserInstruction(QString instruction)
{
    QStringList list = instruction.split(";");

    if (list.size() == 0)
        return;

    std::cout << "client reçoit " << instruction.toStdString() << std::endl;
    switch(list.at(0).toInt())
    {
        // instruction de connexion / envoie de pseudo
    case 0:
        verifierConnexion(list.at(1).toStdString().c_str());
        break;
        // instruction lancement partie / récupération numéro joueur
    case 1:
        std::cout << "je lance en " << list.at(1).toInt() << std::endl;
        lancerPartie(list.at(1).toInt());
        break;
        // instruction action levier / couleur levier
    case 2:
        break;
        // instruction déplacement joueur / id joueur / nouveau x / nouveau y
    case 3:
        gw->getGame()->getPositionJoueur(gw->getGame()->getPlayerNumero())->push(CartesianPosition(list.at(1).toInt(),list.at(2).toInt()));
        break;
    }
}

void Client::lancerPartie(int numero)
{
    gw = new GameWindow(0, this, numero);

    gw->show();
}


void Client::envoyerDeplacement(int numero, string direction)
{
    char buffer[1020] = {0};
    strcpy(buffer,std::to_string(1).c_str());
    strcat(buffer,";");
    strcat(buffer,direction.c_str());

    client->write(buffer,sizeof(buffer));
}
