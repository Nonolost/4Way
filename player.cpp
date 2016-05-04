#include "player.h"

/**
 * @brief Player::Player
 */
Player::Player()
{
    pos = CartesianPosition(0,0);
}

CartesianPosition Player::getPos()
{
    return pos;
}
