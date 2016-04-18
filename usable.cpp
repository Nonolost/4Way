#include "usable.h"

Usable::Usable(std::vector<Tile> list, std::string couleur)
    : Tile(true,true,"Useable",couleur)
{
    for(int i = 0; i < list.size(); i++)
        target[i] = list[i];
}
Usable::Usable(std::string couleur)
    : Tile(true,true,"Useable",couleur)
{}
std::vector<Tile> Usable::getTarget(){ return target;}
