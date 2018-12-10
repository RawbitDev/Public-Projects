// ChessGame - by GitHub.com/RawbitDev
#include "bishop.h"
#include <board.h>

bishop::bishop(teamColor playerColor) : piece(playerColor)
{
    this->setName("laeufer");
    this->setType("bishop");
}

bool bishop::validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY)
{

    int i=0, j=0;
    piece *E = new empty;

    if (oldPosX != newPosX && oldPosY != newPosY) {

        if (oldPosX > newPosX && oldPosY > newPosY) {
            for (i=oldPosX-1, j=oldPosY-1; i>newPosX; i--, j--) {
                if (fields[i][j]->getType() != E->getType()) {
                    return false;
                }
            }
        } else if (oldPosX < newPosX && oldPosY < newPosY) {
            for (i=oldPosX+1, j=oldPosY+1; i<newPosX; i++, j++) {
                if (fields[i][j]->getType() != E->getType()) {
                    return false;
                }
            }
        } else if (oldPosX > newPosX && oldPosY < newPosY) {
            for (i=oldPosX-1, j=oldPosY+1; i>newPosX; i--, j++) {
                if (fields[i][j]->getType() != E->getType()) {
                    return false;
                }
            }
        } else if (oldPosX < newPosX && oldPosY > newPosY) {
            for (i=oldPosX+1, j=oldPosY-1; i<newPosX; i++, j--) {
                if (fields[i][j]->getType() != E->getType()) {
                    return false;
                }
            }
        }

        if(i != newPosX || j!= newPosY) {
            return false;
        } else {
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

    }

    return false;
}

position bishop::checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY)
{
    piece *E = new empty;
    piece *K = new king();

    if (this->getColor() == W) {

        for (int i=oldPosX-1, j=oldPosY-1; i>=0 && j>=0; i--, j--) {
            if (fields[i][j]->getType() != E->getType()) {
                if ((fields[i][j]->getColor() == B) && (fields[i][j]->getType() == K->getType())) {
                    return position{i, j};
                }
                break;
            }
        }

        for (int i=oldPosX+1, j=oldPosY+1; i<8 && j<8; i++, j++) {
            if (fields[i][j]->getType() != E->getType()) {
                if ((fields[i][j]->getColor() == B) && (fields[i][j]->getType() == K->getType())) {
                    return position{i, j};
                }
                break;
            }
        }

        for (int i=oldPosX-1, j=oldPosY+1; i>=0 && j<8; i--, j++) {
            if (fields[i][j]->getType() != E->getType()) {
                if ((fields[i][j]->getColor() == B) && (fields[i][j]->getType() == K->getType())) {
                    return position{i, j};
                }
                break;
            }
        }

        for (int i=oldPosX+1, j=oldPosY-1; i<8 && j>=0; i++, j--) {
            if (fields[i][j]->getType() != E->getType()) {
                if ((fields[i][j]->getColor() == B) && (fields[i][j]->getType() == K->getType())) {
                    return position{i, j};
                }
                break;
            }
        }



    } else if (this->getColor() == B) {

        for (int i=oldPosX-1, j=oldPosY-1; i>=0 && j>=0; i--, j--) {
            if (fields[i][j]->getType() != E->getType()) {
                if ((fields[i][j]->getColor() == W) && (fields[i][j]->getType() == K->getType())) {
                    return position{i, j};
                }
                break;
            }
        }

        for (int i=oldPosX+1, j=oldPosY+1; i<8 && j<8; i++, j++) {
            if (fields[i][j]->getType() != E->getType()) {
                if ((fields[i][j]->getColor() == W) && (fields[i][j]->getType() == K->getType())) {
                    return position{i, j};
                }
                break;
            }
        }

        for (int i=oldPosX-1, j=oldPosY+1; i>=0 && j<8; i--, j++) {
            if (fields[i][j]->getType() != E->getType()) {
                if ((fields[i][j]->getColor() == W) && (fields[i][j]->getType() == K->getType())) {
                    return position{i, j};
                }
                break;
            }
        }

        for (int i=oldPosX+1, j=oldPosY-1; i<8 && j>=0; i++, j--) {
            if (fields[i][j]->getType() != E->getType()) {
                if ((fields[i][j]->getColor() == W) && (fields[i][j]->getType() == K->getType())) {
                    return position{i, j};
                }
                break;
            }
        }

    }

    return position{-1,-1};
}
