#include "gamewindow.h"
#include "mapwidget.h"
#include "game.h"
#include "server.h"
#include "client.h"

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
    game = new Game();
}
