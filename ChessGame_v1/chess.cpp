// ChessGame - by GitHub.com/RawbitDev
#include "chess.h"
using namespace std;

chess::chess()
{
    board *chessBoard = new board();
    string name1 = "", name2 = "";

    system("cls"); // Only works on windows

    cout << "ChessGame v.1.0" << endl
         << "===============" << endl << endl
         << "**************************************************************************" << endl
         << "*                                                                        *" << endl
         << "*  Willkommen zum Schachspiel!                                           *" << endl
         << "*  Bitte geben Sie nachfolgend die Namen der beiden Spieler an.          *" << endl
         << "*  Wer Weiss spielt, und damit beginnen darf, wird per Zufall bestimmt.  *" << endl
         << "*                                                                        *" << endl
         << "*  Es gelten die offiziellen Schachregel, mit der Ausnahme, dass das     *" << endl
         << "*  Schlagen eines Bauers 'en passante' sowie die 'Rochade' in der        *" << endl
         << "*  aktuellen Version noch nicht implementiert wurden.                    *" << endl
         << "*                                                                        *" << endl
         << "*  Spielzuege bitte im Format 'xy-xy' (z.B. b1-c3) eingeben.             *" << endl
         << "*  Zum Beenden einfach 'exit' eingeben.                                  *" << endl
         << "*                                                                        *" << endl
         << "*  Wir wuenschen viel Spass :)                                           *" << endl
         << "*                                                                        *" << endl
         << "**************************************************************************" << endl << endl;

    cout << "Name des 1. Spielers: ";
    getline(cin, name1);

    cout << "Name des 2. Spielers: ";
    getline(cin, name2);

    // Initialize randomizer
    srand(static_cast<unsigned int>(time(nullptr))); // Alternativly to srand(time(NULL));

    if ((rand()%2) == 0) {
        string tempName = name1;
        name1 = name2;
        name2 = tempName;
    }

    player Player1(name1, W);
    player Player2(name2, B);

    chessBoard->print();
    player currentPlayer = Player1;
    cout << endl << currentPlayer.getName() << " spielt Weiss und darf den ersten Zug machen." << endl;

    do {

        string input = "";
        cout << "Zug> ";
        getline(cin, input);

        if (input == "exit" || input == "EXIT" || input == "Exit") {
            exit(0);

        } else if ((input == "") || (input.length() != 5) || (input.find("-") != 2)) {
            cout << "Hinweis: Fehlerhafte Eingabe. Bitte erneut versuchen." << endl;
            continue;

        } else if (chessBoard->validateMove(input, currentPlayer)) {

            if (currentPlayer.getColor() == Player1.getColor()) {
                currentPlayer = Player2;
            } else {
                currentPlayer = Player1;
            }

            chessBoard->print();

            cout << endl << currentPlayer.getName() << " (";
            (currentPlayer.getColor() == W) ? (cout << "Weiss") : (cout << "Schwarz");
            cout << ") ist an der Reihe." << endl;

            if (chessBoard->getKingUnderAttack(W) != "") {
                cout << chessBoard->getKingUnderAttack(W) << endl;
            }
            if (chessBoard->getKingUnderAttack(B) != "") {
                cout << chessBoard->getKingUnderAttack(B) << endl;
            }

        } else {
            cout << "Hinweis: Dieser Zug ist nicht moeglich. Bitte erneut versuchen." << endl;
        }

    } while(chessBoard->isWon() == E);

    system("cls"); // Only works on windows

    cout << "ChessGame v.1.0" << endl
         << "===============" << endl << endl << endl
         << "Herzlichen Glueckwunsch!" << endl << endl;

    if (chessBoard->isWon() == Player1.getColor()) {
        cout << Player1.getName() << " (";
        (Player1.getColor() == W) ? (cout << "Weiss") : (cout << "Schwarz");
    } else if (chessBoard->isWon() == Player2.getColor()) {
        cout << Player2.getName() << " (";
        (Player2.getColor() == W) ? (cout << "Weiss") : (cout << "Schwarz");
    }
    cout << ") gewinnt die Partie." << endl << endl << endl;

}
