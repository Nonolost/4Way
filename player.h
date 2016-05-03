#ifndef PLAYER_H
#define PLAYER_H

#include "position.h"

class Player
{
private:
    CartesianPosition pos;

public:
    Player();
    CartesianPosition getPos();
};

#endif // PLAYER_H
