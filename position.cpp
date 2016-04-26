#include "position.h"

/**
 * @brief Position::Position
 * Crée une position vide (0;0)
 */
CartesianPosition::CartesianPosition():_x(0),_y(0){}

/**
 * @brief Position::Position
 * Crée la position placée en (x;y)
 * @param x Entier donnant le placement sur l'axe horizontal
 * @param y Entier donnant le placement sur l'axe vertical
 */
CartesianPosition::CartesianPosition(int x,int y):_x(x),_y(y){}

/**
 * @brief CartesianPosition::operator +
 * Additionne deux positions entre elles
 * @param cp Position à ajouter (Vecteur à appliquer)
 * @return La somme des deux positions données
 */
CartesianPosition CartesianPosition::operator+ (const CartesianPosition cp)
{
    return CartesianPosition(_x+cp._x,_y+cp._y);
}
