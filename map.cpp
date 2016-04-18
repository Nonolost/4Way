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
                tiles[i] = new Empty("noir");
            break;
            case 1 :
                tiles[i] = new Wall("noir");
            break;
            case 2 :
                tiles[i] = new Empty("vert");
            break;
            case 3 :
                tiles[i] = new Wall("vert");
            break;
            case 4 :
                tiles[i] = new Usable("vert");
            break;
            case 5 :
                tiles[i] = new Objectif("vert");
            break;
            case 6 :
                tiles[i] = new Empty("rouge");
            break;
            case 7 :
                tiles[i] = new Wall("rouge");
            break;
            case 8 :
                tiles[i] = new Usable("rouge");
            break;
            case 9 :
                tiles[i] = new Objectif("rouge");
            break;
            case 10 :
                tiles[i] = new Empty("bleu");
            break;
            case 11 :
                tiles[i] = new Wall("bleu");
            break;
            case 12 :
                tiles[i] = new Usable("bleu");
            break;
            case 13 :
                tiles[i] = new Objectif("bleu");
            break;
            case 14 :
                tiles[i] = new Empty("jaune");
            break;
            case 15 :
                tiles[i] = new Wall("jaune");
            break;
            case 16 :
                tiles[i] = new Usable("jaune");
            break;
            case 17 :
                tiles[i] = new Objectif("jaune");
            break;

            default :
                tiles[i] = new Empty("noir");
            break;
            }

        }



        fichier.close();
    }
    else { cerr << "fichier introuvable !" << endl; }
}



void action(Tile t){

}


