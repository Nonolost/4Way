#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>
#include "map.h"
#include "connexion.h"
#include "game.h"
#include "plateauWidget.h"
#include <QThread>
#include <chrono>
#include <atomic>

#include <QKeyEvent>

class GameWindow;



class GameWindow : public QWidget
{
    Q_OBJECT
    class UpdatePosition : public QThread
    {
    public:
        UpdatePosition(GameWindow *gw, int numero) {
            this->numero = numero;
            this->gw = gw;
            this->poss = this->gw->getGame()->getPositionJoueur(numero);
        }
    private:
        int numero;
        GameWindow* gw;
        concurrency::concurrent_queue<CartesianPosition>* poss;

        void run() {
            while(true) {
                CartesianPosition pos;


                while(!poss->try_pop(pos)) {};
                high_resolution_clock::time_point t1 = high_resolution_clock::now();

                if (gw->getGame()->getPlateau()->isValide(this->numero,pos)) {
                    // move player
                    gw->getPW(numero)->changePos(pos);
                    high_resolution_clock::time_point t2 = high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
                    msleep(18-duration);
                }
            }
        }
    };

public:
    GameWindow(QWidget *parent = 0, Connexion *connexion = 0, int numero = -1);

    Game* getGame();
    plateauWidget *getPW(int numero);

public slots:
    void keyPressEvent(QKeyEvent* event);

private:
    tilemap *map;
    Connexion *conn;
    int numero;
    Game *game;
    QList<plateauWidget*> *pws;
};

#endif // GAMEWINDOW_H
