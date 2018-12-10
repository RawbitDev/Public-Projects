// ChessGame - by GitHub.com/RawbitDev
#include "rook.h"
#include <board.h>

rook::rook(teamColor playerColor) : piece(playerColor)
{
    this->setName("turm");
    this->setType("rook");
}

bool rook::validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY)
{

    piece *E = new empty;

    if (oldPosX == newPosX) {

        if (oldPosY > newPosY) {
            for (int i=oldPosY-1; i>newPosY; i--) {
                if (fields[oldPosX][i]->getType() != E->getType()) {
                    return false;
                }
            }
        } else if (oldPosY < newPosY) {
            for (int i=oldPosY+1; i<newPosY; i++) {
                if (fields[oldPosX][i]->getType() != E->getType()) {
                    return false;
                }
            }
        }

        if (fields[newPosX][newPosY]->getType() == E->getType()) {
            this->setMoved();
            return true;
        } else {
            if (this->getColor() == W) {
                if (fields[newPosX][newPosY]->getColor() == B) {
                    this->setMoved();
                    return true;
                }
            } else if (this->getColor() == B) {
                if (fields[newPosX][newPosY]->getColor() == W) {
                    this->setMoved();
                    return true;
                }
            }
        }


    } else if (oldPosY == newPosY) {

        if (oldPosX > newPosX) {
            for (int i=oldPosX-1; i>newPosX; i--) {
                if (fields[i][oldPosY]->getType() != E->getType()) {
                    return false;
                }
            }
        } else if (oldPosX < newPosX) {
            for (int i=oldPosX+1; i<newPosX; i++) {
                if (fields[i][oldPosY]->getType() != E->getType()) {
                    return false;
                }
            }
        }

        if (fields[newPosX][newPosY]->getType() == E->getType()) {
            this->setMoved();
            return true;
        } else {
            if (this->getColor() == W) {
                if (fields[newPosX][newPosY]->getColor() == B) {
                    this->setMoved();
                    return true;
                }
            } else if (this->getColor() == B) {
                if (fields[newPosX][newPosY]->getColor() == W) {
                    this->setMoved();
                    return true;
                }
            }
        }

    }

    return false;
}

position rook::checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY)
{
    int i=0;
    piece *E = new empty;
    piece *K = new king();

    i=0;
    if (this->getColor() == W) {

        i=oldPosY;
        do {
            i++;
            if (i<8 && i>=0) {
                if ((fields[oldPosX][i]->getColor() == B) && (fields[oldPosX][i]->getType() == K->getType())) {
                    return position{oldPosX, i};
                }
            }
        } while (i<8 && fields[oldPosX][i]->getType() == E->getType());

        i=oldPosY;
        do {
            i--;
            if (i<8 && i>=0) {
                if ((fields[oldPosX][i]->getColor() == B) && (fields[oldPosX][i]->getType() == K->getType())) {
                    return position{oldPosX, i};
                }
            }
        } while (i>=0 && fields[oldPosX][i]->getType() == E->getType());

        i=oldPosX;
        do {
            i++;
            if (i<8 && i>=0) {
                if ((fields[i][oldPosY]->getColor() == B) && (fields[i][oldPosY]->getType() == K->getType())) {
                    return position{i, oldPosY};
                }
            }
        } while (i<8 && fields[i][oldPosY]->getType() == E->getType());

        i=oldPosX;
        do {
            i--;
            if (i<8 && i>=0) {
                if ((fields[i][oldPosY]->getColor() == B) && (fields[i][oldPosY]->getType() == K->getType())) {
                    return position{i, oldPosY};
                }
            }
        } while (i>=0 && fields[i][oldPosY]->getType() == E->getType());


    } else if (this->getColor() == B) {

        i=oldPosY;
        do {
            i++;
            if (i<8 && i>=0) {
                if ((fields[oldPosX][i]->getColor() == W) && (fields[oldPosX][i]->getType() == K->getType())) {
                    return position{oldPosX, i};
                }
            }
        } while (i<8 && fields[oldPosX][i]->getType() == E->getType());

        i=oldPosY;
        do {
            i--;
            if (i<8 && i>=0) {
                if ((fields[oldPosX][i]->getColor() == W) && (fields[oldPosX][i]->getType() == K->getType())) {
                    return position{oldPosX, i};
                }
            }
        } while (i>=0 && fields[oldPosX][i]->getType() == E->getType());

        i=oldPosX;
        do {
            i++;
            if (i<8 && i>=0) {
                if ((fields[i][oldPosY]->getColor() == W) && (fields[i][oldPosY]->getType() == K->getType())) {
                    return position{i, oldPosY};
                }
            }
        } while (i<8 && fields[i][oldPosY]->getType() == E->getType());

        i=oldPosX;
        do {
            i--;
            if (i<8 && i>=0) {
                if ((fields[i][oldPosY]->getColor() == W) && (fields[i][oldPosY]->getType() == K->getType())) {
                    return position{i, oldPosY};
                }
            }
        } while (i>=0 && fields[i][oldPosY]->getType() == E->getType());

    }

    return position{-1,-1};
}
