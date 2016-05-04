#include "tile.h"


/**
 * @brief Tile::Tile
 */
Tile::Tile():move(false), use(false), type("Tile"), couleur("noir")
{

}
/**
 * @brief Tile::Tile
 * @param m peut on bouger dans cette case?
 * @param u est elle activable?
 * @param t type de la case
 * @param c couleur de la case
 */
Tile::Tile(bool m, bool u, std::string t,std::string c)
    : move(m),use(u),type(t),couleur(c){

}

bool Tile::canUse(){
    return use;
}
bool Tile::canMove(){
    return move;
}
std::string Tile::getCouleur(){
    return couleur;
}
std::string Tile::getType(){
    return type;
}


