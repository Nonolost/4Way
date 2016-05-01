#ifndef USABLE_H
#define USABLE_H
#include <vector>
#include <utility>
#include "tile.h"

class Usable : public Tile
{
public:
    Usable(std::vector<std::pair<int,int>> list, std::string couleur);
    Usable(std::string couleur);
    std::vector<std::pair<int,int>> getTarget();
    void setTarget(std::vector<std::pair<int,int>> t);
private:
    std::vector<std::pair<int,int>> target;
};

#endif // USABLE_H
