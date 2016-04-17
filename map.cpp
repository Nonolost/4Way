#include "map.h"

using namespace std;



map::map()
{
    tiles = new Tile*[10*10];
    ifstream fichier("plateau.txt",ios::in);
    if(fichier){
        // TODO : assert ?
        int n;
        for(int i = 0; i<10*10; i++){
            fichier >> n;
            switch(n){
                case 0 :
                    tiles[i] = new Empty();
                break;
                case 1 :
                    tiles[i] = new Wall();
                break;
                case 2 :
                    tiles[i] = new Objectif();
                break;

                default :
                    //TODO Usable et wall/Empty correspondant
                    tiles[i] = new Empty();
                break;
            }

        }



        fichier.close();
    }
    else { cerr << "fichier introuvable !" << endl; }
}



void action(Tile t){

}


