#include <QApplication>
#include <QPushButton>
#include "map.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QPushButton button("Tout");
    button.show();

    map m = map();

    return app.exec();
}
