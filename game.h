#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "position.h"

using namespace std;

class Game
{
private:
    int myPlayer;
    /*
     * Player[] players;
     * Plateau[] plateaux;
     */
    Game();
public:
    static void move(Position);
    static void use();
    //void pushMove(Move),
};

#endif // GAME_H
