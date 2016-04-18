#include "usable.h"

Usable::Usable(std::vector<int> list, std::string couleur)
    : Tile(true,true,"Useable",couleur)
{
    for(int i = 0; i < list.size(); i++)
        target[i] = list[i];
}
Usable::Usable(std::string couleur)
    : Tile(true,true,"Useable",couleur)
{}
std::vector<int> Usable::getTarget(){ return target;}

void Usable::setTarget(std::vector<int> t){
    target = t;
}
