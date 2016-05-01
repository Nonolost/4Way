#include "usable.h"

Usable::Usable(std::vector<std::pair<int,int>> list, std::string couleur)
    : Tile(true,true,"Useable",couleur)
{
    for(int i = 0; i < list.size(); i++)
        target[i] = list[i];
}
Usable::Usable(std::string couleur)
    : Tile(true,true,"Useable",couleur)
{}
std::vector<std::pair<int,int>> Usable::getTarget(){ return target;}

void Usable::setTarget(std::vector<std::pair<int,int>> t){
    target = t;
}
