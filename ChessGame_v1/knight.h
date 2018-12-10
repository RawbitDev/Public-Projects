// ChessGame - by GitHub.com/RawbitDev
#ifndef KNIGHT_H
#define KNIGHT_H

#include <piece.h>
using namespace std;

class knight : public piece
{
public:
    ~knight() {}
    knight(teamColor playerColor = X);
    bool validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY);
    position checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY);
};

#endif // KNIGHT_H
