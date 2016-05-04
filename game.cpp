#include "game.h"

/**
 * @brief Game::Game
 * Crée une partie
 */
Game::Game(int numero)
{

    myPlayer = numero;
    players[0] = new Player();
    players[1] = new Player();
    players[2] = new Player();
    players[3] = new Player();
    plateaux = new tilemap();
    positions = new QList<concurrency::concurrent_queue<CartesianPosition>*>();
    positions->append(new concurrency::concurrent_queue<CartesianPosition>());
    positions->append(new concurrency::concurrent_queue<CartesianPosition>());
    positions->append(new concurrency::concurrent_queue<CartesianPosition>());
    positions->append(new concurrency::concurrent_queue<CartesianPosition>());


}

/**
 * @brief move
 * Déplace le joueur
 * @param pos Code indiquant le type de décalage à appliquer
 */
void Game::move(int pos)
{

    switch (pos){
    case CartesianPosition::SAUT:

        break;
    case CartesianPosition::GCHE:

        break;
    case CartesianPosition::DRTE:

        break;
    default:
        break;
    }
    pushMove(pos);
}

/**
 * @brief use
 * Utilise l'élément situé au niveau du joueur s'il y en a un
 */
void Game::use()
{


}

void Game::pushMove(int move)
{

}

