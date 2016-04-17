#include "usable.h"

Usable::Usable(std::vector<Tile> list) : Tile(true,true,"Useable")
{
    for(int i = 0; i < list.size(); i++)
        target[i] = list[i];
}
std::vector<Tile> Usable::getTarget(){ return target;}
