#ifndef POSITION_H
#define POSITION_H


class Position
{
private:
    int _x,_y;
public:
    Position();
    Position(int,int);
    /**
     * @brief getX
     * @return La position sur l'axe horizontal (entier)
     */
    inline int getX(){return _x;}
    /**
     * @brief getY
     * @return La position sur l'axe vertical (entier)
     */
    inline int getY(){return _y;}
};

#endif // POSITION_H
