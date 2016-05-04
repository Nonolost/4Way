#include <QtNetwork>
#include <QHostAddress>

#include <stdlib.h>
#include "serveurwidget.h"
#include "server.h"
#include <iostream>

Server::Server(QObject* parent)
    : Connexion(parent)
{
    server = new QTcpServer(this);
    clients = new QList<QTcpSocket*>;
    clients_pseudos = new QList<QString>;

    // init pour les déplacements
    deplacements = new QList<concurrency::concurrent_queue<string>*>();
    deplacements->append(new concurrency::concurrent_queue<string>());
    deplacements->append(new concurrency::concurrent_queue<string>());
    deplacements->append(new concurrency::concurrent_queue<string>());
    deplacements->append(new concurrency::concurrent_queue<string>());


    mapper = new QSignalMapper(this);

    connect(server, &QTcpServer::newConnection,
            this, &Server::acceptConnection);

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(startRead(int)));

    server->listen();

    mutexes = new QList<std::mutex*>();

    mutexes->append(new std::mutex());
    mutexes->append(new std::mutex());
    mutexes->append(new std::mutex());
    mutexes->append(new std::mutex());

    mutexes->at(0)->lock();
    mutexes->at(1)->lock();
    mutexes->at(2)->lock();
    mutexes->at(3)->lock();
}

Server::~Server()
{
    server->close();
}

void Server::acceptConnection()
{
    QTcpSocket *sock = server->nextPendingConnection();

    if (clients->size() < 3) {
        clients->append(sock);
        mapper->setMapping(clients->last(), clients->length()-1);

        connect(clients->last(), SIGNAL(readyRead()), mapper, SLOT(map()));

        connect(clients->last(), SIGNAL(disconnected()),
                this, SLOT(closeConnection()));
        sock->write("0;ok",5);

        //sock->write((const char*) clients->length()-1,sizeof(clients->length()-1));
    }
    else {
        sock->write("0;nop",6);
        sock->close();
    }
}

void Server::closeConnection()
{
    QTcpSocket *sock = (QTcpSocket*) sender();

    clients_pseudos->removeAt(clients->indexOf(sock));
    clients->removeAt(clients->indexOf(sock));
    sw->updateClients();
}

void Server::startRead(int index)
{
    char buffer[1020] = {0};

    clients->at(index)->read(buffer, clients->at(index)->bytesAvailable());

    QString instruction = QString::fromUtf8(buffer);

    QStringList list = instruction.split(";");


    std::cout << "serveur viens la avec : " << instruction.toStdString() << std::endl;
    switch(list.at(0).toInt())
    {
    case 0:
        clients_pseudos->append(buffer);
        sw->setJoueur(list.at(1), index);
        break;
        // instruction déplacement : G/H/B
    case 1:
        this->ajouterDeplacement(index,list.at(1).toStdString());
        break;
        // instruction action gemme
    case 2:
        break;
        // instruction action levier : couleur
    case 3:
        break;
    }
}

QString Server::getAdresseIP()
{
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    return ipAddress;
}

quint16 Server::getPort()
{
    return server->serverPort();
}

void Server::setServeurWidget(ServeurWidget *sw)
{
    this->sw = sw;
}

QList<QString>* Server::getPseudosClients() {
    return clients_pseudos;
}


void Server::envoyerInstructionDemarrerPartie()
{
    for (int i = 0; i < clients->size(); i++) {
        char buffer[1020] = {0};
        strcpy(buffer,std::to_string(1).c_str());
        strcat(buffer,";");
        strcat(buffer,std::to_string(i).c_str());
        clients->at(i)->write(buffer,sizeof(buffer));
    }
}

void Server::atest(int numero, const char*buffer)
{
    clients->at(numero)->write(buffer, sizeof(buffer));
}

void Server::sendNouvellePosition(int numero, const char* buffer)
{
    std::cout << "serveur envoie pos " << buffer << " a " << numero << std::endl;

    clients->at(numero)->write(buffer,sizeof(buffer));
}

void Server::ajouterDeplacement(int numero, string direction)
{
    std::cout << "j'ajoute pour " << numero << " le déplacement : " << direction << std::endl;
    this->deplacements->at(numero)->push(direction);
    this->mutexes->at(numero)->unlock();
}

void Server::initThreads()
{
    for (int i = 0; i < 4; i++) {
        CalculPosition *cp = new CalculPosition(this->game, this, this->deplacements->at(i), i);
        cp->start();
    }

    std::cout << "j'ai tout init les threads" << std::endl;
}

void Server::initGame(Game* game)
{
    this->game = game;
}
