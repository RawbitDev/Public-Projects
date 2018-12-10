TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    board.cpp \
    piece.cpp \
    player.cpp \
    pawn.cpp \
    empty.cpp \
    chess.cpp \
    queen.cpp \
    king.cpp \
    bishop.cpp \
    knight.cpp \
    rook.cpp

HEADERS += \
    board.h \
    piece.h \
    player.h \
    chess.h \
    pawn.h \
    empty.h \
    queen.h \
    king.h \
    bishop.h \
    knight.h \
    rook.h \
    teamcolor.h
