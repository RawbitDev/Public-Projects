// ChessGame - by GitHub.com/RawbitDev
#include "knight.h"
#include <board.h>
bool checkKnightField(piece *fields[8][8], int i, int j, teamColor pieceColor);

knight::knight(teamColor playerColor) : piece(playerColor)
{
    this->setName("springer");
    this->setType("knight");
}

bool knight::validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY)
{
    piece *E = new empty;

    if ( ((newPosX==oldPosX+1) && (newPosY==oldPosY+2)) ||
         ((newPosX==oldPosX+1) && (newPosY==oldPosY-2)) ||
         ((newPosX==oldPosX+2) && (newPosY==oldPosY+1)) ||
         ((newPosX==oldPosX+2) && (newPosY==oldPosY-1)) ||
         ((newPosX==oldPosX-1) && (newPosY==oldPosY+2)) ||
         ((newPosX==oldPosX-1) && (newPosY==oldPosY-2)) ||
         ((newPosX==oldPosX-2) && (newPosY==oldPosY+1)) ||
         ((newPosX==oldPosX-2) && (newPosY==oldPosY-1))
       ) {

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

position knight::checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY)
{
    int i=0, j=0;

    if (this->getColor() == W) {

        i=oldPosX+1;
        j=oldPosY+2;
        if (checkKnightField(fields, i, j, B)) {
            return position{i, j};
        }

        i=oldPosX+1;
        j=oldPosY-2;
        if (checkKnightField(fields, i, j, B)) {
            return position{i, j};
        }

        i=oldPosX+2;
        j=oldPosY+1;
        if (checkKnightField(fields, i, j, B)) {
            return position{i, j};
        }

        i=oldPosX+2;
        j=oldPosY-1;
        if (checkKnightField(fields, i, j, B)) {
            return position{i, j};
        }

        i=oldPosX-1;
        j=oldPosY+2;
        if (checkKnightField(fields, i, j, B)) {
            return position{i, j};
        }

        i=oldPosX-1;
        j=oldPosY-2;
        if (checkKnightField(fields, i, j, B)) {
            return position{i, j};
        }

        i=oldPosX-2;
        j=oldPosY+1;
        if (checkKnightField(fields, i, j, B)) {
            return position{i, j};
        }

        i=oldPosX-2;
        j=oldPosY-1;
        if (checkKnightField(fields, i, j, B)) {
            return position{i, j};
        }

    } else if (this->getColor() == B) {

        i=oldPosX+1;
        j=oldPosY+2;
        if (checkKnightField(fields, i, j, W)) {
            return position{i, j};
        }

        i=oldPosX+1;
        j=oldPosY-2;
        if (checkKnightField(fields, i, j, W)) {
            return position{i, j};
        }

        i=oldPosX+2;
        j=oldPosY+1;
        if (checkKnightField(fields, i, j, W)) {
            return position{i, j};
        }

        i=oldPosX+2;
        j=oldPosY-1;
        if (checkKnightField(fields, i, j, W)) {
            return position{i, j};
        }

        i=oldPosX-1;
        j=oldPosY+2;
        if (checkKnightField(fields, i, j, W)) {
            return position{i, j};
        }

        i=oldPosX-1;
        j=oldPosY-2;
        if (checkKnightField(fields, i, j, W)) {
            return position{i, j};
        }

        i=oldPosX-2;
        j=oldPosY+1;
        if (checkKnightField(fields, i, j, W)) {
            return position{i, j};
        }

        i=oldPosX-2;
        j=oldPosY-1;
        if (checkKnightField(fields, i, j, W)) {
            return position{i, j};
        }

    }

    return position{-1,-1};
}


bool checkKnightField(piece *fields[8][8], int i, int j, teamColor pieceColor) {

    piece *E = new empty;
    piece *K = new king();

    if (i<8 && i>=0 && j<8 && j>=0) {
        if (fields[i][j]->getType() != E->getType()) {
            if ((fields[i][j]->getColor() == pieceColor) && (fields[i][j]->getType() == K->getType())) {
                return true;
            }
        }
    }

    return false;
}
