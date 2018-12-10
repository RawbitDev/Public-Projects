// ChessGame - by GitHub.com/RawbitDev
#ifndef PAWN_H
#define PAWN_H

#include <piece.h>
using namespace std;

class pawn : public piece
{
public:
    ~pawn() {}
    pawn(teamColor playerColor = X);
    bool validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY);
    position checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY);
};

#endif // PAWN_H
