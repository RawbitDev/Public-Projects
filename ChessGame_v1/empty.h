// ChessGame - by GitHub.com/RawbitDev
#ifndef EMPTY_H
#define EMPTY_H

#include <piece.h>
using namespace std;

class empty : public piece
{
public:
    ~empty() {}
    empty(teamColor playerColor = E);
    bool validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY);
    position checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY);
};

#endif // EMPTY_H
