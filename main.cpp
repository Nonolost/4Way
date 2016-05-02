#include <QApplication>
#include <QtCore>

#include <stdlib.h>
#include "menuwindow.h"
#include "server.h"
#include "client.h"

int main(int argc, char *argv[])
{


    QApplication app(argc, argv);
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
