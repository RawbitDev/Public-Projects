// ChessGame - by GitHub.com/RawbitDev
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <teamcolor.h>
using namespace std;

class player
{
public:
    player(string playerName, teamColor playerColor);
    string getName() const;
    teamColor getColor() const;

private:
    string name;
    teamColor color; //W=0; B=1
};

#endif // PLAYER_H
