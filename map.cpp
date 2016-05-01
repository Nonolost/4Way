#include "map.h"




tilemap::tilemap()
{
    //tiles = new Tile*[10*10];
    std::string file;
    std::string p = "plateau";
    std::string f = ".txt";
    std::vector<std::pair<int,int>> vert,rouge,bleu,jaune;
    std::map<int,std::vector<std::pair<int,int>>> dico;
    for(int j = 0; j <4; j++){
        tiles[j] = new Tile*[10*10];
        file = p+ std::to_string(j) + f;
        std::ifstream fichier(file,std::ios::in);
        if(fichier){

            int n;
            for(int i = 0; i<10*10; i++){
                fichier >> n;
                switch(n){
                case 0 :
                    tiles[j][i] = new Empty("noir");
                break;
                case 1 :
                    tiles[j][i] = new Wall("noir");
                break;
                case 2 :
                    tiles[j][i] = new Empty("vert");
                    vert.push_back(std::make_pair(j,i));
                break;
                case 3 :
                    tiles[j][i] = new Wall("vert");
                    vert.push_back(std::make_pair(j,i));
                break;
                case 4 :
                    tiles[j][i] = new Usable("vert");
                    dico[i] = vert;
                break;
                case 5 :
                    tiles[j][i] = new Objectif("vert");
                break;
                case 6 :
                    tiles[j][i] = new Empty("rouge");
                    rouge.push_back(std::make_pair(j,i));
                break;
                case 7 :
                    tiles[j][i] = new Wall("rouge");
                    rouge.push_back(std::make_pair(j,i));
                break;
                case 8 :
                    tiles[j][i] = new Usable("rouge");
                    dico[i] = rouge;
                break;
                case 9 :
                    tiles[j][i] = new Objectif("rouge");
                break;
                case 10 :
                    tiles[j][i] = new Empty("bleu");
                    bleu.push_back(std::make_pair(j,i));
                break;
                case 11 :
                    tiles[j][i] = new Wall("bleu");
                    bleu.push_back(std::make_pair(j,i));
                break;
                case 12 :
                    tiles[j][i] = new Usable("bleu");
                    dico[i] = bleu;
                break;
                case 13 :
                    tiles[j][i] = new Objectif("bleu");
                break;
                case 14 :
                    tiles[j][i] = new Empty("jaune");
                    jaune.push_back(std::make_pair(j,i));
                break;
                case 15 :
                    tiles[j][i] = new Wall("jaune");
                    jaune.push_back(std::make_pair(j,i));
                break;
                case 16 :
                    tiles[j][i] = new Usable("jaune");
                    dico[i] = jaune;
                break;
                case 17 :
                    tiles[j][i] = new Objectif("jaune");
                break;

                default :
                    tiles[j][i] = new Empty("noir");
                break;
                }

            }
            fichier.close();

        }else { std::cerr << "fichier introuvable !" << std::endl; }




    }
    std::map<int,std::vector<std::pair<int,int>>>::iterator it = dico.begin();
    while(it != dico.end()){
        reinterpret_cast<Usable*>(tiles[it->first])->setTarget(it->second);
        it++;
    }
}



void tilemap::action(Tile* t){
    std::string couleur = t->getCouleur();
    std::vector<std::pair<int,int>> tar = reinterpret_cast<Usable*>(t)->getTarget();
    std::vector<std::pair<int,int>>::iterator it = tar.begin();
    while(it != tar.end()){
        if (tiles[it->first][it->second]->canMove()){
            tiles[it->first][it->second] = new Wall(couleur);
        }else{
            tiles[it->first][it->second] = new Empty(couleur);
        }
        it++;
    }
}
std::map<int, Tile **> tilemap::getMap(){
    return tiles;
}

Tile* tilemap::at(int joueur,CartesianPosition cp)
{
    return tiles[joueur][(10-cp.getY())*10+cp.getX()];
}
