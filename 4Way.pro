QT += widgets

SOURCES += \
    main.cpp \
    map.cpp \
    tile.cpp \
    wall.cpp \
    empty.cpp \
    usable.cpp \
    objectif.cpp \
    mainwindow.cpp \
    game.cpp \
    position.cpp \
    player.cpp

HEADERS += \
    map.h \
    tile.h \
    wall.h \
    empty.h \
    usable.h \
    objectif.h \
    mainwindow.h \
    game.h \
    position.h \
    player.h

DISTFILES += \
    plateau0.txt \
    plateau1.txt \
    plateau2.txt \
    plateau3.txt

FORMS += \
    mainwindow.ui
