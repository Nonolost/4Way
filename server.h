#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>
#include "connexion.h"

QT_BEGIN_NAMESPACE
class QNetworkSession;
class QTcpSocket;
class QSignalMapper;
QT_END_NAMESPACE

class ServeurWidget;

class Server : public Connexion
{
Q_OBJECT
public:
    Server(QObject *parent = 0);
    ~Server();

    QString getAdresseIP();
    quint16 getPort();

    void setServeurWidget(ServeurWidget *sw);
    QList<QString>* getPseudosClients();

public slots:
    void acceptConnection();
    void startRead(int index);
    void closeConnection();

private:
    QTcpServer *server;
    QList<QTcpSocket*> *clients;
    QList<QString> *clients_pseudos;
    ServeurWidget *sw;

    QSignalMapper *mapper;
};

#endif // SERVER_H
