// ChessGame - by GitHub.com/RawbitDev
#include "piece.h"

piece::piece(teamColor playerColor)
{
    this->color = playerColor;
}

bool piece::wasMoved() const
{
    return moved;
}

teamColor piece::getColor() const
{
    return color;
}

string piece::getName() const
{
    string fullName = this->name;
    if ( (this->getColor())==0 ) {
        fullName += "_w";
    } else if ( (this->getColor())==1 ) {
        fullName += "_s";
    }
    return fullName;
}

string piece::getType()
{
    return type;
}

bool piece::validateMove(piece *fields[8][8], int oldPosX, int oldPosY, int newPosX, int newPosY)
{
    (void)fields;
    (void)oldPosX;
    (void)oldPosY;
    (void)newPosX;
    (void)newPosY;
    return false;
}

position piece::checkKingAttack(piece *fields[8][8], int oldPosX, int oldPosY)
{
    (void)fields;
    (void)oldPosX;
    (void)oldPosY;
    return position{-1,-1};
}

void piece::setName(string pieceName)
{
    name = pieceName;
}

void piece::setType(string pieceType)
{
    type = pieceType;
}

void piece::setMoved()
{
    moved = true;
}
