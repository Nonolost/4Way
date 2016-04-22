#include "game.h"

/**
 * @brief Game::Game
 * Crée une partie
 */
Game::Game()
{

}

/**
 * @brief move
 * Déplace le joueur
 * @param pos Décalage
 */
void Game::move(Position pos)
{
    // TODO : Effectuer le déplacement
    if (pos.getX()==0 && pos.getY()==1) cout << "Saut" << endl;
    if (pos.getY()==0){
        if (pos.getX()==-1) cout << "Vers la gauche" << endl;
        if (pos.getX()==1) cout << "Vers la droite" << endl;
    }
}

/**
 * @brief use
 * Utilise l'élément situé au niveau du joueur s'il y en a un
 */
void Game::use()
{
    // TODO : Effectuer l'action
    cout << "Action" << endl;
}

