#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * Constructeur pour la fenêtre principale
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
    setFixedSize(500,500);

    currGame = new Game(0);
    
    plateauWidget **p = new plateauWidget*[4];

    QGridLayout *gridLayout = new QGridLayout;
    for(int i = 0; i<4;i++){
        p[i]= new plateauWidget(this,currGame->getPlateau()->getMap(i),i);
        p[i]->setGeometry(i%2*205,i/2*205,200,200);
        gridLayout->addWidget(p[i]);
    }

    setLayout(gridLayout);
}

/**
 * @brief MainWindow::~MainWindow
 * Destructeur pour la fenêtre principale
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::keyPressEvent
 * Méthode appelée à chaque appui sur une touche du clavier
 * On transfère l'information à la partie pour qu'elle fasse le nécessaire
 * @param event
 */
void MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch (event->key()) {
    case Qt::Key_Down:
        currGame->use();
        break;
    case Qt::Key_Up:
        currGame->move(CartesianPosition::SAUT);
        break;
    case Qt::Key_Left:
        currGame->move(CartesianPosition::GCHE);
        break;
    case Qt::Key_Right:
        currGame->move(CartesianPosition::DRTE);
        break;
    default:
        // On ne fait rien si la touche utilisée n'est pas affectée à une action
        break;
    }
}
