#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <iostream>
#include "game.h"
#include "plateauWidget.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::MainWindow *ui;
    Game *currGame;
};

#endif // MAINWINDOW_H
