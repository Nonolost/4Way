#include "client.h"
#include <QHostAddress>
#include <QTcpSocket>
#include <iostream>
#include "clientwidget.h"
/**
 * @brief Client::Client
 * @param parent
 */
Client::Client(QObject* parent): Connexion(parent), blockSize(0)
{
    client = new QTcpSocket(this);
    connect(client, SIGNAL(error(QAbstractSocket::SocketError))
            , this, SLOT(erreurConnexion()));
}

/**
 * @brief Client::~Client
 */
Client::~Client()
{
    client->close();
}

/**
 * @brief Client::start
 * @param address
 * @param port
 * @param pseudo
 * essaye de se connecter au serveur
 */
void Client::start(QString address, quint16 port, QString pseudo)
{
    QHostAddress addr(address);
    client->connectToHost(addr, port);
    connect(client, SIGNAL(readyRead()), this, SLOT(recevoirInstruction()));

    this->pseudo = pseudo;
}

/**
 * @brief Client::verifierConnexion
 * @param buffer
 * verifie le resultat de la connection
 */
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
/**
 * @brief Client::close
 */
void Client::close()
{
    client->close();
}

/**
 * @brief Client::erreurConnexion
 */
void Client::erreurConnexion()
{
    std::cout << "erreur dans la connexion " << std::endl;
}

/**
 * @brief Client::recevoirInstruction
 * recupere une instruction
 */
void Client::recevoirInstruction()
{
    char buffer[1020] = {0};

    client->read(buffer, client->bytesAvailable());

    analyserInstruction(QString::fromUtf8(buffer));
}

/**
 * @brief Client::analyserInstruction
 * @param instruction
 * traite une instruction
 */
void Client::analyserInstruction(QString instruction)
{
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
    case 4:
        break;
    }
}
/**
 * @brief Client::lancerPartie
 * @param numero
 */
void Client::lancerPartie(int numero)
{
    gw = new GameWindow(0, this, numero);

    gw->show();
}

/**
 * @brief Client::envoyerDeplacement
 * @param numero
 * @param direction
 * envoi le numero du joueur et sa direction
 */
void Client::envoyerDeplacement(int numero, string direction)
{
    char buffer[1020] = {0};
    strcpy(buffer,std::to_string(1).c_str());
    strcat(buffer,";");
    strcat(buffer,direction.c_str());

    client->write(buffer,sizeof(buffer));
}
