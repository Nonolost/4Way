#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <queue>
#include <chrono>
#include "position.h"
#include "player.h"
#include "map.h"

#define NB_PLAYERS 4
#define DELAI_SIMULTANE 200

using namespace std;
using namespace std::chrono;

class Game
{
private:
    int myPlayer;
    Player* players[NB_PLAYERS];
    queue<CartesianPosition> positions;
    CartesianPosition nextPosition;
    tilemap* plateaux;
public:
    Game();
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
};

#endif // GAME_H
