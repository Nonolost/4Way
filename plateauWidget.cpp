#include <QPainter>

#include "plateauWidget.h"


/**
 * @brief plateauWidget::plateauWidget
 * @param parent
 * @param map plateau pour le joueur i
 * @param i
 * @param cp position du joueur
 */
plateauWidget::plateauWidget(QWidget *parent, Tile **map,int i, CartesianPosition cp)
    : QWidget(parent),player(i)
{
    tmap = map;
    dico["noir"] = 0;
    dico["vert"] = 1;
    dico["rouge"] = 2;
    dico["jaune"] = 3;
    dico["bleu"] = 4;
    pos = cp;
    setPalette(QPalette(QColor(250, 250, 250)));
    setAutoFillBackground(true);
}
/**
 * @brief plateauWidget::changeCase
 * @param list liste des coord' des cases a changer
 * actualise les cases de la liste
 */
void plateauWidget::changeCase(std::vector<int> list)
{
    int taille = 20;
    QPainter painter(this);

    for(int i : list){
        switch(dico[tmap[i]->getCouleur()]){
        case 1 :
            painter.setPen(Qt::green);
            painter.setBrush(Qt::darkGreen);

            break;
        case 2 :
            painter.setPen(Qt::red);
            painter.setBrush(Qt::darkRed);

            break;
        case 3 :
            painter.setPen(Qt::yellow);
            painter.setBrush(Qt::darkYellow);

            break;
        case 4 :
            painter.setPen(Qt::blue);
            painter.setBrush(Qt::darkBlue);

            break;
        default :
            painter.setPen(Qt::darkGray);
            painter.setBrush(Qt::black);
            break;
        }
        if(tmap[i]->canMove()){
            painter.setBrush(Qt::NoBrush);
        }


        painter.drawRect(QRect(i%10*taille,i/10*taille,taille-1,taille-1));
    }


}

/**
 * @brief plateauWidget::paintEvent
 * peind l'ensemble du tableau + le joueur
 */
void plateauWidget::paintEvent(QPaintEvent * /* event */)
{
    int taille = 20;
    QPainter painter(this);
    QPen pen(Qt::black,3);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);



    for(int i = 0; i < 100; i++){
        switch(dico[tmap[i]->getCouleur()]){
        case 1 :
            painter.setPen(Qt::green);
            painter.setBrush(Qt::darkGreen);

            break;
        case 2 :
            painter.setPen(Qt::red);
            painter.setBrush(Qt::darkRed);

            break;
        case 3 :
            painter.setPen(Qt::yellow);
            painter.setBrush(Qt::darkYellow);

            break;
        case 4 :
            painter.setPen(Qt::blue);
            painter.setBrush(Qt::darkBlue);

            break;
        default :
            painter.setPen(Qt::darkGray);
            painter.setBrush(Qt::black);
            break;
        }
        if(tmap[i]->canMove()){
            if(tmap[i]->getType()=="Useable"){
                painter.drawRect(i%10*taille+taille/4,i/10*taille+taille/4,taille/2-1,taille/2-1);
            }else if(tmap[i]->getType()=="Objectif"){
                painter.drawEllipse(i%10*taille+taille/4,i/10*taille+taille/4,taille/2-1,taille/2-1);
            }
            painter.setBrush(Qt::NoBrush);

        }


        painter.drawRect(QRect(i%10*taille,i/10*taille,taille-1,taille-1));
    }

    paintPlayer();


}

/**
 * @brief plateauWidget::movePlayer
 * actualise la position du joueur
 */
void plateauWidget::movePlayer(){
    QRegion region = playerRect();

    QRect playerR = playerRect();


    update(region);
}

/**
 * @brief plateauWidget::paintPlayer
 * peind le joueur
 */
void plateauWidget::paintPlayer(){
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);
    painter.drawRect(playerRect());
}
/**
 * @brief plateauWidget::playerRect
 * @return la zone du joueur
 */
QRect plateauWidget::playerRect() {
    int taille = 20;

    QRect res(pos.getX(),pos.getY(),taille/2-1,taille-1);
    return res;
}

void plateauWidget::changePos(CartesianPosition pos)
{
    this->pos = pos;
}
