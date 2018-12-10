// ChessGame - by GitHub.com/RawbitDev
#ifndef ROOK_H
#define ROOK_H

#include <piece.h>
using namespace std;

class rook : public piece
{
public:
    ~rook() {}
    rook(teamColor playerColor = X);
    bool validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY);
    position checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY);
};

#endif // ROOK_H
