#ifndef MAP_H
#define MAP_H
#include "tile.h"
#include "wall.h"
#include "empty.h"
#include "usable.h"
#include "objectif.h"
#include <fstream>
#include <iostream>
#include <map>

class map
{
public:
    map();
    void action(Tile t);
private:
    Tile **tiles;
};

#endif // MAP_H
