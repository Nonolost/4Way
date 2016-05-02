#ifndef MAP_H
#define MAP_H
#include "tile.h"
#include "wall.h"
#include "empty.h"
#include "usable.h"
#include "objectif.h"
#include "position.h"
#include <fstream>
#include <iostream>
#include <utility>
#include <map>

class tilemap
{
public:
    tilemap();
    void action(Tile* t);
    std::map<int,Tile **> getMap();
    Tile ** getMap(int joueur);
    Tile* at(int joueur, CartesianPosition);
private:
    std::map<int,Tile **> tiles;
};

#endif // MAP_H
