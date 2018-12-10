// ChessGame - by GitHub.com/RawbitDev
#include <iostream>
#include <chess.h>
using namespace std;
bool anotherGame();


int main()
{

    do {
        chess(); // Start a game of chess
    } while(anotherGame());

    return 0;
}


bool anotherGame() {

    int input=0;

    cout << "Moechten Sie eine weitere Partie spielen?" << endl
         << "1 - Neue Partie starten" << endl
         << "0 - Beenden" << endl << endl
         << "Auswahl> ";
    cin >> input;

    cin.clear(); // Clearing the error flag of cin
    cin.ignore(10000, '\n'); // Clearing the buffer up to 10000 characters or until it encounters the next newline

    if (input==1) {
        return true;
    }

    return false;
}
