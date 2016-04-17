#ifndef USABLE_H
#define USABLE_H
#include <vector>
#include "tile.h"

class Usable : public Tile
{
public:
    Usable(std::vector<Tile> list);
    std::vector<Tile> getTarget();
private:
    std::vector<Tile> target;
};

#endif // USABLE_H
