// ChessGame - by GitHub.com/RawbitDev
#ifndef KING_H
#define KING_H

#include <piece.h>
using namespace std;

class king : public piece
{
public:
    ~king() {}
    king(teamColor playerColor = X);
    bool validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY);
    position checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY);
};

#endif // KING_H
