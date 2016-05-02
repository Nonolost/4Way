QT += network widgets

SOURCES += \
    main.cpp \
    server.cpp \
    menuwindow.cpp \
    serveurwidget.cpp \
    client.cpp \
    clientwidget.cpp \
    connexion.cpp

HEADERS += \
    server.h \
    menuwindow.h \
    serveurwidget.h \
    client.h \
    clientwidget.h \
    connexion.h

target.path = test
INSTALLS += target
