#ifndef TILE_H
#define TILE_H
#include <string>

class Tile
{
public:
    Tile();
    Tile(bool m, bool u, std::string t,std::string couleur);
    bool canUse();
    bool canMove();
private:
    std::string type;
    std::string couleur;
    bool move;
    bool use;
};

#endif // TILE_H
