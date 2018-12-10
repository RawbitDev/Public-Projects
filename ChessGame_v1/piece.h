// ChessGame - by GitHub.com/RawbitDev
#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
#include <teamcolor.h>
using namespace std;

class piece
{
public:
    virtual ~piece() {}
    piece(teamColor playerColor);

    bool wasMoved() const;
    teamColor getColor() const;
    string getName() const;
    string getType();
    virtual bool validateMove(piece *fields[8][8], int oldPosX, int oldPosY=0, int newPosX=0, int newPosY=0);
    virtual position checkKingAttack(piece *fields[8][8], int newPosX, int newPosY);

    void setMoved();

private:
    bool moved = false;
    string name;
    string type;
    teamColor color;

protected:
    void setName(string pieceName);
    void setType(string pieceType);
};

#endif // PIECE_H
