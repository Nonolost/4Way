#include "tile.h"



Tile::Tile():move(false), use(false), type("Tile")
{

}
Tile::Tile(bool m, bool u, std::string t) : move(m),use(u),type(t){

}

bool Tile::canUse(){
    return use;
}
bool Tile::canMove(){
    return move;
}


