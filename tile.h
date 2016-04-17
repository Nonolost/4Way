#ifndef TILE_H
#define TILE_H
#include <string>

class Tile
{
public:
    Tile();
    Tile(bool m, bool u, std::string t);
    bool canUse();
    bool canMove();
private:
    std::string type;
    bool move;
    bool use;
};

#endif // TILE_H
