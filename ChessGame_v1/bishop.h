// ChessGame - by GitHub.com/RawbitDev
#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>
using namespace std;

class bishop : public piece
{
public:
    ~bishop() {}
    bishop(teamColor playerColor = X);
    bool validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY);
    position checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY);
};

#endif // BISHOP_H
