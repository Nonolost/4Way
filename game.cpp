#include "game.h"

/**
 * @brief Game::Game
 * Crée une partie
 */
Game::Game(int numero)
{
    // FIXME : Initialize what's needed
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

    //positions.push(CartesianPosition(1,0));
}

/**
 * @brief move
 * Déplace le joueur
 * @param pos Code indiquant le type de décalage à appliquer
 */
void Game::move(int pos)
{
    // TODO : Effectuer le déplacement
    switch (pos){
    case CartesianPosition::SAUT:
        cout << "Saut" << endl;
        break;
    case CartesianPosition::GCHE:
        cout << "Vers la gauche" << endl;
        break;
    case CartesianPosition::DRTE:
        cout << "Vers la droite" << endl;
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
    // TODO : Effectuer l'action
    cout << "Action" << endl;
}

void Game::pushMove(int move)
{
    /*
    // TODO : Ajouter le mouvement sur la pile
    cout << positions.size() << "éléments dans la file" << endl;
    static int lastXChange;
    static auto lastChange = system_clock::now();
    cout << "Avant switch" << endl;
    switch (move){
    case CartesianPosition::SAUT:
        nextPosition = positions.back()+CartesianPosition(1,(duration_cast<milliseconds>(system_clock::now()-lastChange).count()<DELAI_SIMULTANE) ? lastXChange : 0);
        lastXChange=0;
        break;
    case CartesianPosition::GCHE:
        nextPosition = positions.back()+CartesianPosition(0,-1);
        lastXChange = -1;
        break;
    case CartesianPosition::DRTE:
        nextPosition = positions.back()+CartesianPosition(0,1);
        lastXChange = 1;
        break;
    default:
        break;
    }
    cout << "Après switch" << endl;
    cout << "(" << nextPosition.getX() << ";" << nextPosition.getY() << ")" << endl;
    if (plateaux->at(myPlayer,nextPosition)->canMove())
        positions.push(nextPosition);
    cout << "Après push" << endl;
    lastChange=system_clock::now();*/
}

