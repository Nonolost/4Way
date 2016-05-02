#include <QApplication>
#include <QtCore>
#include <QPushButton>
#include <stdlib.h>
#include "menuwindow.h"
#include "server.h"
#include "client.h"
#include "map.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    QPushButton button("Tout");
    //w.setCentralWidget(&button);

    w.show();

    tilemap* m = new tilemap();

    MenuWindow menu_window;
    menu_window.show();

    return app.exec();
/*
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(QTclient::tr("Fortune Client"));
    QTclient client;
    client.show();
    return app.exec();

    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(QTserver::tr("Fortune Server"));
    QTserver server;
    server.show();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return app.exec();*/
}
