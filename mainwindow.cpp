#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    // TODO : Effectuer l'action nécessaire pour chaque touche
    switch (event->key()) {
    case Qt::Key_Down:
        Game::use();
        break;
    case Qt::Key_Up:
        Game::move(Position(0,1));
        break;
    case Qt::Key_Left:
        Game::move(Position(-1,0));
        break;
    case Qt::Key_Right:
        Game::move(Position(1,0));
        break;
    default:
        // On ne fait rien si la touche utilisée n'est pas affectée à une action
        break;
    }
}
