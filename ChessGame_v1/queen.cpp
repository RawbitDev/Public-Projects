// ChessGame - by GitHub.com/RawbitDev
#include "queen.h"
#include <board.h>

queen::queen(teamColor playerColor) : piece(playerColor)
{
    this->setName("dame");
    this->setType("queen");
}

bool queen::validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY)
{
    int i=0, j=0;
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

    } else {

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

position queen::checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY)
{
    int i=0;
    piece *E = new empty;
    piece *K = new king();

    i=0;
    if (this->getColor() == W) {

        // Line

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


        // Diagonally

        for (int i=oldPosX-1, j=oldPosY-1; i>=0 && j>=0; i--, j--) {
            if (i<8 && i>=0) {
                if (fields[i][j]->getType() != E->getType()) {
                    if ((fields[i][j]->getColor() == B) && (fields[i][j]->getType() == K->getType())) {
                        return position{i, j};
                    }
                    break;
                }
            }
        }

        for (int i=oldPosX+1, j=oldPosY+1; i<8 && j<8; i++, j++) {
            if (i<8 && i>=0) {
                if (fields[i][j]->getType() != E->getType()) {
                    if ((fields[i][j]->getColor() == B) && (fields[i][j]->getType() == K->getType())) {
                        return position{i, j};
                    }
                    break;
                }
            }
        }

        for (int i=oldPosX-1, j=oldPosY+1; i>=0 && j<8; i--, j++) {
            if (i<8 && i>=0) {
                if (fields[i][j]->getType() != E->getType()) {
                    if ((fields[i][j]->getColor() == B) && (fields[i][j]->getType() == K->getType())) {
                        return position{i, j};
                    }
                    break;
                }
            }
        }

        for (int i=oldPosX+1, j=oldPosY-1; i<8 && j>=0; i++, j--) {
            if (i<8 && i>=0) {
                if (fields[i][j]->getType() != E->getType()) {
                    if ((fields[i][j]->getColor() == B) && (fields[i][j]->getType() == K->getType())) {
                        return position{i, j};
                    }
                    break;
                }
            }
        }



    } else if (this->getColor() == B) {

        // Line

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


        // Diagonally

        for (int i=oldPosX-1, j=oldPosY-1; i>=0 && j>=0; i--, j--) {
            if (i<8 && i>=0) {
                if (fields[i][j]->getType() != E->getType()) {
                    if ((fields[i][j]->getColor() == W) && (fields[i][j]->getType() == K->getType())) {
                        return position{i, j};
                    }
                    break;
                }
            }
        }

        for (int i=oldPosX+1, j=oldPosY+1; i<8 && j<8; i++, j++) {
            if (i<8 && i>=0) {
                if (fields[i][j]->getType() != E->getType()) {
                    if ((fields[i][j]->getColor() == W) && (fields[i][j]->getType() == K->getType())) {
                        return position{i, j};
                    }
                    break;
                }
            }
        }

        for (int i=oldPosX-1, j=oldPosY+1; i>=0 && j<8; i--, j++) {
            if (i<8 && i>=0) {
                if (fields[i][j]->getType() != E->getType()) {
                    if ((fields[i][j]->getColor() == W) && (fields[i][j]->getType() == K->getType())) {
                        return position{i, j};
                    }
                    break;
                }
            }
        }

        for (int i=oldPosX+1, j=oldPosY-1; i<8 && j>=0; i++, j--) {
            if (i<8 && i>=0) {
                if (fields[i][j]->getType() != E->getType()) {
                    if ((fields[i][j]->getColor() == W) && (fields[i][j]->getType() == K->getType())) {
                        return position{i, j};
                    }
                    break;
                }
            }
        }

    }


    return position{-1,-1};
}
