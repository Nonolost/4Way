#include "tile.h"



Tile::Tile():move(false), use(false), type("Tile"), couleur("noir")
{

}
Tile::Tile(bool m, bool u, std::string t,std::string c)
    : move(m),use(u),type(t),couleur(c){

}

bool Tile::canUse(){
    return use;
}
bool Tile::canMove(){
    return move;
}


