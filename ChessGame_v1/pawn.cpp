// ChessGame - by GitHub.com/RawbitDev
#include "pawn.h"
#include <board.h>

pawn::pawn(teamColor playerColor) : piece(playerColor)
{
    this->setName("bauer");
    this->setType("pawn");
}

bool pawn::validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY)
{

    piece *E = new empty;

    if (oldPosX == newPosX) {
        if (this->getColor() == W) {
            if (newPosY == oldPosY+1) {
                if (fields[newPosX][newPosY]->getType() == E->getType()) {
                    this->setMoved();
                    return true;
                }
            } else if (newPosY == oldPosY+2) {
                if (this->wasMoved() == false) {
                    if ((fields[oldPosX][oldPosY+1]->getType() == E->getType()) && (fields[newPosX][newPosY]->getType() == E->getType())) {
                        this->setMoved();
                        return true;
                    }
                }
            }
        } else if (this->getColor() == B) {
            if (newPosY == oldPosY-1) {
                if (fields[newPosX][newPosY]->getType() == E->getType()) {
                    this->setMoved();
                    return true;
                }
            } else if (newPosY == oldPosY-2) {
                if (this->wasMoved() == false) {
                    if ((fields[oldPosX][oldPosY-1]->getType() == E->getType()) && (fields[newPosX][newPosY]->getType() == E->getType())) {
                        this->setMoved();
                        return true;
                    }
                }
            }
        }
    } else {
        if (this->getColor() == W) {
            if (newPosY == oldPosY+1 && ((newPosX == oldPosX-1) || (newPosX == oldPosX+1))) {
                if (fields[newPosX][newPosY]->getColor() == B) {
                    this->setMoved();
                    return true;
                }
            }
        } else if (this->getColor() == B) {
            if (newPosY == oldPosY-1 && ((newPosX == oldPosX-1) || (newPosX == oldPosX+1))) {
                if (fields[newPosX][newPosY]->getColor() == W) {
                    this->setMoved();
                    return true;
                }
            }
        }
    }

    return false;
}

position pawn::checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY)
{
    int newPosX=0, newPosY=0;
    piece *K = new king();



    if (this->getColor() == W) {
        newPosY = oldPosY+1;

        newPosX = oldPosX+1;
        if (newPosX<=7 && newPosX>=0 && newPosY<=7 && newPosY>=0) {
            if ((fields[newPosX][newPosY]->getColor() == B) && (fields[newPosX][newPosY]->getType() == K->getType())) {
                return position{newPosX, newPosY};
            }
        }

        newPosX = oldPosX-1;
        if (newPosX<=7 && newPosX>=0 && newPosY<=7 && newPosY>=0) {
            if ((fields[newPosX][newPosY]->getColor() == B) && (fields[newPosX][newPosY]->getType() == K->getType())) {
                return position{newPosX, newPosY};
            }
        }


    } else if (this->getColor() == B) {
        newPosY = oldPosY-1;

        newPosX = oldPosX+1;
        if (newPosX<=7 && newPosX>=0 && newPosY<=7 && newPosY>=0) {
            if ((fields[newPosX][newPosY]->getColor() == W) && (fields[newPosX][newPosY]->getType() == K->getType())) {
                return position{newPosX, newPosY};
            }
        }

        newPosX = oldPosX-1;
        if (newPosX<=7 && newPosX>=0 && newPosY<=7 && newPosY>=0) {
            if ((fields[newPosX][newPosY]->getColor() == W) && (fields[newPosX][newPosY]->getType() == K->getType())) {
                return position{newPosX, newPosY};
            }
        }
    }

    return position{-1,-1};
}
