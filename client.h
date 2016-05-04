#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpServer>
#include "connexion.h"
#include "gamewindow.h"

QT_BEGIN_NAMESPACE
class QNetworkSession;
class QTcpSocket;
QT_END_NAMESPACE

class ClientWidget;

class Client : public Connexion
{
Q_OBJECT
public:
    /**
     * @brief Client::Client
     * @param parent
     */
    Client(QObject *parent = 0);
    /**
     * @brief Client::~Client
     */
    ~Client();

    /**
     * @brief Client::start
     * @param address
     * @param port
     * @param pseudo
     * essaye de se connecter au serveur
     */
    void start(QString address, quint16 port, QString pseudo);

    /**
     * @brief Client::close
     */
    void close();

    /**
     * @brief Client::lancerPartie
     * @param numero
     */
    void lancerPartie(int numero);

    /**
     * @brief Client::analyserInstruction
     * @param instruction
     * traite une instruction
     */
    void analyserInstruction(QString instruction);

    /**
     * @brief Client::verifierConnexion
     * @param buffer
     * verifie le resultat de la connection
     */
    void verifierConnexion(const char* buffer);

    /**
     * @brief Client::envoyerDeplacement
     * @param numero
     * @param direction
     * envoi le numero du joueur et sa direction
     */
    void envoyerDeplacement(int numero, string direction);

public slots:
    /**
     * @brief Client::erreurConnexion
     */
    void erreurConnexion();
    /**
     * @brief Client::recevoirInstruction
     * recupere une instruction
     */
    void recevoirInstruction();

private:
    QTcpSocket *client;
    QString pseudo;
    ClientWidget *cw;

    quint16 blockSize;

    GameWindow *gw;
};

#endif // SERVER_H
