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
    bool isValide(int joueur, CartesianPosition cp);
    bool isOnFloor(int joueur, CartesianPosition cp);
private:
    std::map<int,Tile **> tiles;
};

#endif // MAP_H
