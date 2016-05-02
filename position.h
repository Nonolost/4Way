#ifndef POSITION_H
#define POSITION_H


class CartesianPosition
{
private:
    int _x,_y;
public:
    CartesianPosition();
    CartesianPosition(int,int);
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

    static const int SAUT = 0;
    static const int GCHE = 1;
    static const int DRTE = 2;

    CartesianPosition operator+ (const CartesianPosition cp);
};

#endif // POSITION_H
