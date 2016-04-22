#include "position.h"

/**
 * @brief Position::Position
 * Crée une position vide (0;0)
 */
Position::Position():_x(0),_y(0){}

/**
 * @brief Position::Position
 * Crée la position placée en (x;y)
 * @param x Entier donnant le placement sur l'axe horizontal
 * @param y Entier donnant le placement sur l'axe vertical
 */
Position::Position(int x,int y):_x(x),_y(y){}
