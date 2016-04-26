#include "map.h"




tilemap::tilemap()
{
    tiles = new Tile*[10*10];
    std::ifstream fichier("plateau.txt",std::ios::in);
    std::vector<int> vert,rouge,bleu,jaune;
    std::map<int,std::vector<int>> dico;
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
                vert.push_back(i);
            break;
            case 3 :
                tiles[i] = new Wall("vert");
                vert.push_back(i);
            break;
            case 4 :
                tiles[i] = new Usable("vert");
                dico[i] = vert;
            break;
            case 5 :
                tiles[i] = new Objectif("vert");
            break;
            case 6 :
                tiles[i] = new Empty("rouge");
                rouge.push_back(i);
            break;
            case 7 :
                tiles[i] = new Wall("rouge");
                rouge.push_back(i);
            break;
            case 8 :
                tiles[i] = new Usable("rouge");
                dico[i] = rouge;
            break;
            case 9 :
                tiles[i] = new Objectif("rouge");
            break;
            case 10 :
                tiles[i] = new Empty("bleu");
                bleu.push_back(i);
            break;
            case 11 :
                tiles[i] = new Wall("bleu");
                bleu.push_back(i);
            break;
            case 12 :
                tiles[i] = new Usable("bleu");
                dico[i] = bleu;
            break;
            case 13 :
                tiles[i] = new Objectif("bleu");
            break;
            case 14 :
                tiles[i] = new Empty("jaune");
                jaune.push_back(i);
            break;
            case 15 :
                tiles[i] = new Wall("jaune");
                jaune.push_back(i);
            break;
            case 16 :
                tiles[i] = new Usable("jaune");
                dico[i] = jaune;
            break;
            case 17 :
                tiles[i] = new Objectif("jaune");
            break;

            default :
                tiles[i] = new Empty("noir");
            break;
            }
            std::map<int,std::vector<int>>::iterator it = dico.begin();
            while(it != dico.end()){
                reinterpret_cast<Usable*>(tiles[it->first])->setTarget(it->second);
                it++;
            }
        }


        fichier.close();
    }
    else { std::cerr << "fichier introuvable !" << std::endl; }
}



void tilemap::action(Tile* t){
    std::string couleur = t->getCouleur();
    std::vector<int> tar = reinterpret_cast<Usable*>(t)->getTarget();
    std::vector<int>::iterator it = tar.begin();
    while(it != tar.end()){
        if (tiles[*it]->canMove()){
            tiles[*it] = new Wall(couleur);
        }else{
            tiles[*it] = new Empty(couleur);
        }
        it++;
    }
}
Tile** tilemap::getMap(){
    return tiles;
}

Tile* tilemap::at(CartesianPosition cp)
{
    return tiles[(10-cp.getY())*10+cp.getX()];
}
