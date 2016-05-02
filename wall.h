#ifndef WALL_H
#define WALL_H
#include "tile.h"

class Wall : public Tile
{
public:
    Wall(std::string couleur);
};

#endif // WALL_H
