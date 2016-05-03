#include <QApplication>
#include <QtCore>
#include <QPushButton>
#include <stdlib.h>
#include "menuwindow.h"
#include "server.h"
#include "client.h"
#include "map.h"
#include "mainwindow.h"
#include "gamewindow.h"
#include <direct.h>
#include <stdio.h>
#include <concurrent_queue.h>
#include <windows.h>

#define GetCurrentDir _getcwd


concurrency::concurrent_queue<int> test;

class MonThreadCustom : public QThread
{
   private:
      void run()
      {
          std::cout << "test" << std::endl;
          for (int i = 0; i < 1000000; i++) {
              test.push(i);
          }
          std::cout << "test2" << std::endl;
      }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    //MainWindow w;
    QPushButton button("Tout");
    //w.setCentralWidget(&button);

    //w.show();

    //tilemap m = tilemap();


    MenuWindow menu_window;
    menu_window.show();

   // GameWindow gw;
   // gw.show();


    return app.exec();

}
