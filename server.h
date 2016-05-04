#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>
#include "connexion.h"
#include "game.h"
#include "concurrent_queue.h"
#include <QThread>
#include "windows.h"
#include <mutex>

QT_BEGIN_NAMESPACE
class QNetworkSession;
class QTcpSocket;
class QSignalMapper;
QT_END_NAMESPACE

class ServeurWidget;
class CalculPosition;

class Server : public Connexion
{
Q_OBJECT
public:


    Server(QObject *parent = 0);
    ~Server();

    QString getAdresseIP();
    quint16 getPort();

    void setServeurWidget(ServeurWidget *sw);

    /**
     * @brief Server::getPseudosClients
     * @return liste des noms des clients
     */
    QList<QString>* getPseudosClients();

    /**
     * @brief Server::envoyerInstructionDemarrerPartie
     * informe les clients que la partie commence
     */
    void envoyerInstructionDemarrerPartie();

    /**
     * @brief Server::ajouterDeplacement
     * @param numero numero du joueur
     * @param direction nouvelle direction du joueur
     */
    void ajouterDeplacement(int numero, string direction);

    /**
     * @brief Server::initThreads
     * initialise les Threads de calcul de position
     */
    void initThreads();
    void Server::initGame(Game* game);

    std::mutex* getMutex(int numero) { return mutexes->at(numero); }

public slots:
    /**
     * @brief Server::acceptConnection
     * accepte une connection si il reste de la place
     */
    void acceptConnection();

    /**
     * @brief Server::startRead
     * @param index
     * traite les instructions
     */
    void startRead(int index);

    /**
     * @brief Server::closeConnection
     * ferme la connection avec un client
     */
    void closeConnection();
    void sendNouvellePosition(int numero, const char* pos);
    void atest(int numero, const char* buffer);

private:
    QTcpServer *server;
    QList<QTcpSocket*> *clients;
    QList<QString> *clients_pseudos;
    ServeurWidget *sw;
    Game *game;
    QList<concurrency::concurrent_queue<string>*> *deplacements;

    QSignalMapper *mapper;
    QList<std::mutex*> *mutexes;
};


class CalculPosition : public QThread
{
    Q_OBJECT
public:
    CalculPosition(Game *game, Server *serveur, concurrency::concurrent_queue<string> *deplacements, int numero) {
        this->game = game;
        this->serveur = serveur;
        this->deplacements = deplacements;
        this->numero = numero;

        connect(this, SIGNAL(Write(int, const char*)), (const QObject*)this->serveur, SLOT(atest(int, const char*)));
    }

signals:
    void Write(int numero, const char* buffer);

private:
    Game *game;
    Server *serveur;
    concurrency::concurrent_queue<string> *deplacements;
    int numero;

    void run()
    {

        while(true) {
            string deplacement;
            if (deplacements->unsafe_size()==0)
                serveur->getMutex(numero)->lock();

            deplacements->try_pop(deplacement);

            CartesianPosition lastPos;
            CartesianPosition pos = this->game->getPlayer(this->numero)->getPos();

            if (this->game->getPositionJoueur(this->numero)->unsafe_size() > 0) {
                lastPos = *(this->game->getPositionJoueur(numero)->unsafe_end());

            }
            else
                lastPos = pos;



            for (int i =0; i < 60; i++) {
                // on vérifie que la position est bonne
                CartesianPosition nouvellePosition = this->game->getPlateau()->nextPos(numero, pos, lastPos, deplacement.at(0));
                if(this->game->getPlateau()->isValide(numero, nouvellePosition)) {
                    this->game->getPositionJoueur(this->numero)->push(nouvellePosition);
                    for (int i =0; i < 3; i++) {
                            char buffer[1020] = {0};
                            strcpy(buffer,std::to_string(3).c_str());
                            strcat(buffer,";");
                            strcat(buffer,std::to_string(nouvellePosition.getX()).c_str());
                            strcat(buffer,";");
                            strcat(buffer,std::to_string(nouvellePosition.getY()).c_str());


                            emit Write(i, buffer);
                    }
                    lastPos = nouvellePosition;
                }
                else
                    break;
            }
        }
    }
};


#endif // SERVER_H
