#include "gamewindow.h"
#include "mapwidget.h"
#include "game.h"
#include "server.h"
#include "client.h"
#include <QGridLayout>

GameWindow::GameWindow(QWidget *parent, Connexion *connexion, int numero) : QWidget(parent)
{
    if (numero == 4)
        this->conn = (Server*) connexion;
    else
        this->conn = (Client*) connexion;

    this->numero = numero;

    game = new Game(numero);

    QGridLayout *gl= new QGridLayout(this);
    pws = new QList<plateauWidget*>();
    pws->append(new plateauWidget(0,game->getPlateau()->getMap(0),0,game->getPlayer(0)->getPos()));
    pws->append(new plateauWidget(0,game->getPlateau()->getMap(1),1,game->getPlayer(1)->getPos()));
    pws->append(new plateauWidget(0,game->getPlateau()->getMap(2),2,game->getPlayer(2)->getPos()));
    pws->append(new plateauWidget(0,game->getPlateau()->getMap(3),3,game->getPlayer(3)->getPos()));

    gl->addWidget(pws->at(0),0,0);
    gl->addWidget(pws->at(1),0,1);
    gl->addWidget(pws->at(2),1,0);
    gl->addWidget(pws->at(3),1,1);
/*
    for (int i = 0; i < 4; i++) {
        UpdatePosition *up = new UpdatePosition(this,i);
        up->start();
    }*/
}

Game* GameWindow::getGame()
{
    return this->game;
}

void GameWindow::keyPressEvent(QKeyEvent* event)
{
    std::cout << "test" << std::endl;

    switch (event->key()) {
    case Qt::Key_Down:
        /*
        if (this->numero = 4) {
            ((Server*)this->conn)->
        }
        else {

        }
        std::cout << "bas" << std::endl;
        */
        break;
    case Qt::Key_Up:
        if (this->numero == 4) {
            ((Server*)this->conn)->ajouterDeplacement(this->numero, "H");
        }
        else {
            ((Client*)this->conn)->envoyerDeplacement(this->numero, "H");
        }
        break;
    case Qt::Key_Left:
        if (this->numero == 4) {
            std::cout << "ici" << std::endl;
            ((Server*)this->conn)->ajouterDeplacement(this->numero, "G");
        }
        else {
            std::cout << "ou la" << std::endl;
            ((Client*)this->conn)->envoyerDeplacement(this->numero, "G");
        }
        break;
    case Qt::Key_Right:
        if (this->numero == 4) {
            ((Server*)this->conn)->ajouterDeplacement(this->numero, "R");
        }
        else {
            ((Client*)this->conn)->envoyerDeplacement(this->numero, "R");
        }
        break;
    default:
        // On ne fait rien si la touche utilisée n'est pas affectée à une action
        break;
    }
}

plateauWidget* GameWindow::getPW(int numero)
{
    return pws->at(numero);
}
