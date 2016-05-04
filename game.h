#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <queue>
#include <chrono>
#include "position.h"
#include "player.h"
#include "map.h"
#include "concurrent_queue.h"

#define NB_PLAYERS 4
#define DELAI_SIMULTANE 200

#include <QList>

using namespace std;
using namespace std::chrono;



class Game
{
private:
    int myPlayer;
    Player* players[NB_PLAYERS];
    QList<concurrency::concurrent_queue<CartesianPosition>*> *positions;
    CartesianPosition nextPosition;
    tilemap* plateaux;

public:
    Game(int numero);
    /**
     * @brief move
     * Déplace le joueur selon le code reçu
     */
    void move(int);
    /**
     * @brief use
     * Utilise l'objet proche du joueur s'il y en a un
     */
    void use();
    void pushMove(int);

    inline tilemap* getPlateau() { return plateaux; }
    inline concurrency::concurrent_queue<CartesianPosition> *getPositionJoueur(int numero) { return positions->at(numero); }
    inline Player* getPlayer(int numero) { return players[numero]; }
    inline int getPlayerNumero() { return myPlayer; }

    void ajouterDeplacement(int numero, string direction);

};

#endif // GAME_H
