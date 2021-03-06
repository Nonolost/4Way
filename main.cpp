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

          for (int i = 0; i < 1000000; i++) {
              test.push(i);
          }

      }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    MenuWindow menu_window;
    menu_window.show();

    return app.exec();

}
