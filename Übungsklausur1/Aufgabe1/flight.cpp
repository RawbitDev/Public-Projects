#include "flight.h"

Flight::Flight()
{
    for (int i=0; i<22; i++) {
        for (int j=0; j<6; j++) {
            seats[i][j] = "frei";
        }
    }
}

void Flight::book()
{
    string vorname="", nachname="";
    char platz[6] = {'a','b','c','d','e','f'};
    bool found=false;

    for (int i=0; i<22; i++) {
        for (int j=0; j<6; j++) {
            if (seats[i][j] == "frei" && found==false) {
                //Wenn Platz frei ist

                cout << "Bitte Vornamen eingeben: ";
                cin >> vorname;
                cout << "Bitte Nachnamen eingeben: ";
                cin >> nachname;

                seats[i][j] = vorname + ", " + nachname;
                cout << "Wir haben Platz " << i+1 << platz[j] << " fuer Sie reserviert." << endl; //+1 weil array bei 0 startet

                found=true;
            }
        }
    }
    if (found==false) {
        cout << "Es ist leider kein Platz mehr frei." << endl;
    }

}

void Flight::cancel()
{
    int reihe=0, platzInt=0;
    char platz;

    cout << "Bitte Reihe eingeben (1-22): ";
    cin >> reihe;
    cout << "Bitte Platz eingeben (a-f): ";
    cin >> platz;

    reihe -= 1;
    platzInt = platz;
    if (platzInt>=97 && platzInt<=102) {
        platzInt -= 97;
    } else if (platzInt>=65 && platzInt<=70) {
        platzInt -= 65;
    } else {
        cout << "Fehlerhafte Eingabe!" << endl;
        return;
    }

    if (seats[reihe][platzInt] != "frei") {
        seats[reihe][platzInt] = "frei";
        cout << "Buchung vom ausgewahlten Platz wurde entfernt." << endl;
    } else {
        cout << "Ausgewahlter Platz ist nicht besetzt." << endl;
    }

}

void Flight::show_bookings()
{
    for (int i=0; i<22; i++) {
        cout << i+1 << ":\t";
        for (int j=0; j<6; j++) {
            if (seats[i][j] == "frei") {
                cout << "frei\t";
            } else {
                cout << "besetzt\t";
            }
        }
        cout << endl;
    }
}
