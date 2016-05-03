#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>
#include "map.h"
#include "connexion.h"
#include "game.h"

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    GameWindow(QWidget *parent = 0, Connexion *connexion = 0, int numero = -1);

    Game* getGame();
private:
    tilemap *map;
    Connexion *conn;
    int numero;
    Game *game;
};

#endif // GAMEWINDOW_H
