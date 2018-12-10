// ChessGame - by GitHub.com/RawbitDev
#include "board.h"
using namespace std;

board::board()
{

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            setEmpty(i,j);
        }
    }

    setField(0, 0, new rook(W));
    setField(1, 0, new knight(W));
    setField(2, 0, new bishop(W));
    setField(3, 0, new queen(W));
    setField(4, 0, new king(W));
    setField(5, 0, new bishop(W));
    setField(6, 0, new knight(W));
    setField(7, 0, new rook(W));

    setField(0, 7, new rook(B));
    setField(1, 7, new knight(B));
    setField(2, 7, new bishop(B));
    setField(3, 7, new queen(B));
    setField(4, 7, new king(B));
    setField(5, 7, new bishop(B));
    setField(6, 7, new knight(B));
    setField(7, 7, new rook(B));

    for (int i=0; i<8; i++) {
        setField(i, 1, new pawn(W));
        setField(i, 6, new pawn(B));
    }

}

void board::print()
{
    char columns[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    system("cls"); // Only works on windows

    cout << "ChessGame v.1.0" << endl
         << "===============" << endl << endl;

    cout << setw(6) << " ";
    for (int i=0; i<8; i++) {
        cout << setw(10) << "" << columns[i] << "";
    }
    cout << endl << endl;

    for (int i=0; i<8; i++) {
        cout << setw(10) << i+1 << " ";
        for (int j=0; j<8; j++) {
            cout << setw(10) << fields[j][i]->getName() << " ";
        }
        cout << endl << endl;
    }
}

piece *board::getField(int posX, int posY)
{
    return fields[posX][posY];
}

bool board::isEmpty(int posX, int posY)
{
    piece *E = new empty;
    if ((fields[posX][posY]->getType()) == (E->getType())) {
        return true;
    } else {
        return false;
    }
}

void board::setEmpty(int posX, int posY)
{
    fields[posX][posY] = new empty();
}


void board::setField(int posX, int posY, piece *pieceInit)
{
    fields[posX][posY] = pieceInit;
}

int board::selectNewPiece()
{
    piece *tempQueen = new queen();
    piece *tempBishop = new bishop();
    piece *tempKnight = new knight();
    piece *tempRook = new rook();

    int input=0;
    do {
        input=0;
        cout << endl << "Neue Figur auswaehlen: " << endl;
        cout << "1 - " << tempQueen->getName() << endl;
        cout << "2 - " << tempBishop->getName() << endl;
        cout << "3 - " << tempKnight->getName() << endl;
        cout << "4 - " << tempRook->getName() << endl;
        cout << endl << "Auswahl> ";
        cin >> input;
    } while(input>4 || input<1);

    cin.clear(); // Clearing the error flag of cin
    cin.ignore(10000, '\n'); // Clearing the buffer up to 10000 characters or until it encounters the next newline

    return input;
}

teamColor board::isWon()
{
    return won;
}

string board::getKingUnderAttack(teamColor kingColor)
{
    if (kingColor == W) {
        return kingUnderAttackW;
    } else if (kingColor == B) {
        return kingUnderAttackB;
    }
    return "";
}

void board::setKingUnderAttack(teamColor kingColor, string message)
{
    if (kingColor == W) {
        kingUnderAttackW = message;
    } else if (kingColor == B) {
        kingUnderAttackB = message;
    }
}

void board::setWon(teamColor winnerColor)
{
    won = winnerColor;
}

void board::makeMove(int oldPosX, int oldPosY, int newPosX, int newPosY)
{
    setField(newPosX, newPosY, fields[oldPosX][oldPosY]);
    setEmpty(oldPosX,oldPosY);
}

bool board::validateMove(string moveInput, player currentPlayer)
{

            // Splits input to ints
            int oldPosX = (moveInput.at(0));
            int oldPosY = (moveInput.at(1)-49);
            int newPosX = (moveInput.at(3));
            int newPosY = (moveInput.at(4)-49);

            if (oldPosX>=65 && oldPosX<=90) {
                oldPosX += 32;
            }
            oldPosX -= 97;

            if (newPosX>=65 && newPosX<=90) {
                newPosX += 32;
            }
            newPosX -= 97;

            // Check if input is correct
            if (oldPosX>7 || oldPosX<0 || oldPosY>7 || oldPosY<0 || newPosX>7 || newPosX<0 || newPosY>7 || newPosY<0) {
                cout << "Hinweis: Die eingegebenen Koordinaten befinden sich ausserhalb des Spielfelds." << endl;
                return false;
            }

            piece *selectedPiece = getField(oldPosX,oldPosY);

            // Check if selected piece is of the correct team (also checks that field isn't empty)
            if (selectedPiece->getColor() != currentPlayer.getColor()) {
                cout << "Hinweis: Die ausgewaehlte Spielfigur gehoert ihrem Gegner." << endl;
                return false;
            }

            if (selectedPiece->validateMove(fields, oldPosX, oldPosY, newPosX, newPosY)) {

                piece *K = new king();
                if (fields[newPosX][newPosY]->getType() == K->getType()) {
                    if (fields[newPosX][newPosY]->getColor() == W) {
                        setWon(B);
                    } else if (fields[newPosX][newPosY]->getColor() == B) {
                        setWon(W);
                    }
                }

                makeMove(oldPosX, oldPosY, newPosX, newPosY);

                bool warningW = false;
                bool warningB = false;
                for (int i=0; i<8; i++) {
                    for (int j=0; j<8; j++) {

                        position KingAttack = fields[i][j]->checkKingAttack(fields, i, j);
                        if (KingAttack.posX<=7 && KingAttack.posX>=0 && KingAttack.posY<=7 && KingAttack.posY>=0) {

                            char columns[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
                            string warning = "";
                            string kingAttackPosY = to_string(KingAttack.posY+1);

                            warning = "Achtung: Der ";
                            (fields[KingAttack.posX][KingAttack.posY]->getColor() == W) ? (warning += "weisse") : (warning += "schwarze");
                            warning += " Koenig in ";
                            warning.push_back(columns[KingAttack.posX]);
                            warning += kingAttackPosY + " steht im Schach!";

                            if (fields[i][j]->getColor() == W) {
                                setKingUnderAttack(W, warning);
                                warningW = true;
                            } else if (fields[i][j]->getColor() == B) {
                                setKingUnderAttack(B, warning);
                                warningB = true;
                            }

                        }

                        if (warningW == false) {
                            setKingUnderAttack(W, "");
                        }
                        if (warningB == false) {
                            setKingUnderAttack(B, "");
                        }

                    }
                }

                if ((selectedPiece->getType() == "pawn")) {
                    if ((selectedPiece->getColor() == W) && (newPosY==7)) {

                        int newPieceSelected = selectNewPiece();
                        piece *newPiece = new empty();
                        switch(newPieceSelected) {
                        case 1 : newPiece = new queen(W); break;
                        case 2 : newPiece = new bishop(W); break;
                        case 3 : newPiece = new knight(W); break;
                        case 4 : newPiece = new rook(W); break;
                        }
                        setField(newPosX, newPosY, newPiece);

                    } else if ((selectedPiece->getColor() == B) && (newPosY==0)) {

                        int newPieceSelected = selectNewPiece();
                        piece *newPiece = new empty();
                        switch(newPieceSelected) {
                        case 1 : newPiece = new queen(B); break;
                        case 2 : newPiece = new bishop(B); break;
                        case 3 : newPiece = new knight(B); break;
                        case 4 : newPiece = new rook(B); break;
                        }
                        setField(newPosX, newPosY, newPiece);
                    }
                }

                return true;
            }

            return false;
}
