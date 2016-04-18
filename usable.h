#ifndef USABLE_H
#define USABLE_H
#include <vector>
#include "tile.h"

class Usable : public Tile
{
public:
    Usable(std::vector<int> list, std::string couleur);
    Usable(std::string couleur);
    std::vector<int> getTarget();
    void setTarget(std::vector<int> t);
private:
    std::vector<int> target;
};

#endif // USABLE_H
