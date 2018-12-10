// ChessGame - by GitHub.com/RawbitDev
#ifndef QUEEN_H
#define QUEEN_H

#include <piece.h>
using namespace std;

class queen : public piece
{
public:
    ~queen() {}
    queen(teamColor playerColor = X);
    bool validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY);
    position checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY);
};

#endif // QUEEN_H
