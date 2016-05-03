#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>
#include "map.h"
#include "connexion.h"
#include "game.h"

#include <QKeyEvent>

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    GameWindow(QWidget *parent = 0, Connexion *connexion = 0, int numero = -1);

    Game* getGame();

public slots:
    void keyPressEvent(QKeyEvent* event);

private:
    tilemap *map;
    Connexion *conn;
    int numero;
    Game *game;
};

#endif // GAMEWINDOW_H
