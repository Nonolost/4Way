#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpServer>
#include "connexion.h"

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

public slots:
    void verifierConnexion();
    void erreurConnexion();

private:
    QTcpSocket *client;
    QString pseudo;
    ClientWidget *cw;
};

#endif // SERVER_H
