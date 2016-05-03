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
    Client(QObject *parent = 0);
    ~Client();

    void start(QString address, quint16 port, QString pseudo);
    void close();
    void lancerPartie(int numero);
    void analyserInstruction(QString instruction);
    void verifierConnexion(const char* buffer);
    void envoyerDeplacement(int numero, string direction);

public slots:
    void erreurConnexion();
    void recevoirInstruction();

private:
    QTcpSocket *client;
    QString pseudo;
    ClientWidget *cw;

    quint16 blockSize;

    GameWindow *gw;
};

#endif // SERVER_H
