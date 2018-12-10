// ChessGame - by GitHub.com/RawbitDev
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <iomanip>
#include <string>

#include <teamcolor.h>
#include <player.h>
#include <piece.h>

#include <king.h>
#include <queen.h>
#include <bishop.h>
#include <knight.h>
#include <rook.h>
#include <pawn.h>
#include <empty.h>
using namespace std;

class board
{

public:
    board();
    void print();
    piece *getField(int posX, int posY);
    bool isEmpty(int posX, int posY);
    bool validateMove(string moveInput, player currentPlayer);
    void makeMove(int oldPosX, int oldPosY, int newPosX, int newPosY);
    teamColor isWon();
    string getKingUnderAttack(teamColor kingColor);

private:
    piece *fields[8][8];
    teamColor won = E;
    string kingUnderAttackW = "";
    string kingUnderAttackB = "";
    void setEmpty(int posX, int posY);
    void setField(int posX, int posY, piece *pieceInit);
    void setWon(teamColor winnerColor);
    void setKingUnderAttack(teamColor kingColor, string message);
    int selectNewPiece();

};

#endif // BOARD_H
