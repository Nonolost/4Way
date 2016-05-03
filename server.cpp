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

    mapper = new QSignalMapper(this);

    connect(server, &QTcpServer::newConnection,
            this, &Server::acceptConnection);

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(startRead(int)));

    server->listen();
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
        sock->write("1;ok",5);

        //sock->write((const char*) clients->length()-1,sizeof(clients->length()-1));
    }
    else {
        sock->write("1;nop",6);
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
    std::cout << buffer << std::endl;
    clients_pseudos->append(buffer);
    sw->setJoueur(buffer, index);
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
        /*
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_6);
    //! [4] //! [6]
        out << (quint16)0;
        out << "coucou";

        out.device()->seek(0);
        out << (quint16)(block.size() - sizeof(quint16));

        clients->at(i)->write(block);
        */

        std::cout << "ohohoho" << std::endl;
        char buffer[1020] = {0};
        strcpy(buffer,std::to_string(0).c_str());
        strcat(buffer,";");
        strcat(buffer,std::to_string(i).c_str());
        std::cout << "ohohoho" << std::endl;
        clients->at(i)->write(buffer,sizeof(buffer));
    }
}
