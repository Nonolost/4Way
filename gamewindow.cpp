#include "gamewindow.h"
#include "mapwidget.h"
#include "game.h"
#include "server.h"
#include "client.h"
#include "plateauWidget.h"
#include <QGridLayout>

GameWindow::GameWindow(QWidget *parent, Connexion *connexion, int numero) : QWidget(parent)
{
   /* this->numero = numero;
    if (numero == 0) {
        conn = (Server*) connexion;
    }
    else {
        conn = (Client*) connexion;
    }

    game = new Game();
    QGridLayout *gl= new QGridLayout(this);
    gl->addWidget(new MapWidget(this,game->getPlateaux()->getMap(0)),0,0);
    gl->addWidget(new MapWidget(this,game->getPlateaux()->getMap(2)),0,1);
    gl->addWidget(new MapWidget(this,game->getPlateaux()->getMap(3)),1,0);
    gl->addWidget(new MapWidget(this,game->getPlateaux()->getMap(4)),1,1);
*/
    if (numero == 4)
        this->conn = (Server*) connexion;
    else
        this->conn = (Client*) connexion;

    this->numero = numero;

    game = new Game(numero);

    QGridLayout *gl= new QGridLayout(this);
    gl->addWidget(new plateauWidget(0,game->getPlateau()->getMap(0)),0,0);
    gl->addWidget(new plateauWidget(0,game->getPlateau()->getMap(1)),0,1);
    gl->addWidget(new plateauWidget(0,game->getPlateau()->getMap(2)),1,0);
    gl->addWidget(new plateauWidget(0,game->getPlateau()->getMap(3)),1,1);
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
        //currGame->use();
        break;
    case Qt::Key_Up:
        if (this->numero == 4) {
            ((Server*)this->conn)->ajouterDeplacement(this->numero, "H");
        }
        else {
            ((Client*)this->conn)->envoyerDeplacement(this->numero, "H");
        }
        //this->game->move(CartesianPosition::SAUT);
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
        //this->game->move(CartesianPosition::GCHE);
        break;
    case Qt::Key_Right:
        if (this->numero == 4) {
            ((Server*)this->conn)->ajouterDeplacement(this->numero, "R");
        }
        else {
            ((Client*)this->conn)->envoyerDeplacement(this->numero, "R");
        }
        //this->game->move(CartesianPosition::DRTE);
        break;
    default:
        // On ne fait rien si la touche utilisée n'est pas affectée à une action
        break;
    }
}
