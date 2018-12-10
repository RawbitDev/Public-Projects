// ChessGame - by GitHub.com/RawbitDev
#include "player.h"
using namespace std;

static int playerCount = 1;

player::player(string playerName, teamColor playerColor)
{
    if (playerName != "") {
        this->name = playerName;
    } else {
        this->name = "Spieler " + to_string(playerCount);
    }
    this->color = playerColor;
    playerCount++;
}

string player::getName() const
{
    return name;
}

teamColor player::getColor() const
{
    return color;
}
