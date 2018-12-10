// ChessGame - by GitHub.com/RawbitDev
#include "empty.h"

empty::empty(teamColor playerColor) : piece(playerColor)
{
    this->setName("__________");
    this->setType("empty");
}

bool empty::validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY)
{
    (void)fields;
    (void)oldPosX;
    (void)oldPosY;
    (void)newPosX;
    (void)newPosY;
    return false;
}

position empty::checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY)
{
    (void)fields;
    (void)oldPosX;
    (void)oldPosY;
    return position{-1,-1};
}
