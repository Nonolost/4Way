#include <QApplication>
#include <QPushButton>
#include "map.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    QPushButton button("Tout");
    //w.setCentralWidget(&button);

    w.show();

    tilemap m = tilemap();

    return app.exec();
}
