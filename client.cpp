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

/*
void Client::recevoirInstruction()
{
    char buffer[1] = {0};
    client->read(buffer, client->bytesAvailable());


}*/

void Client::recevoirInstruction()
{
/*
    std::cout << "ici alors que non..." << std::endl;
    QDataStream in(client);
    in.setVersion(QDataStream::Qt_5_6);

    if (blockSize == 0) {
        if (client->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }


    std::cout << "et là" << std::endl;
    if (client->bytesAvailable() < blockSize)
        return;


    std::cout << "et encore..." << std::endl;
    QString instruction;
    in >> instruction;
*/

    char buffer[1020] = {0};

    client->read(buffer, client->bytesAvailable());
    std::cout << buffer << std::endl;

    analyserInstruction(QString::fromUtf8(buffer));
}

void Client::analyserInstruction(QString instruction)
{
    std::cout << "client arrive ici avec : " << instruction.toStdString() << std::endl;
    QStringList list = instruction.split(";");

    if (list.size() == 0)
        return;

    switch(list.at(0).toInt())
    {
        // instruction de connexion / envoie de pseudo
    case 0:
        verifierConnexion(list.at(1).toStdString().c_str());
        break;
        // instruction lancement partie / récupération numéro joueur
    case 1:
        lancerPartie(list.at(1).toInt());
        break;
        // instruction action levier / couleur levier
    case 2:
        break;
        // instruction déplacement joueur / id joueur / nouveau x / nouveau y
    case 3:

        break;
    }
}

void Client::lancerPartie(int numero)
{
    //gw = new GameWindow(0, this, numero);

    //gw->show();
}
