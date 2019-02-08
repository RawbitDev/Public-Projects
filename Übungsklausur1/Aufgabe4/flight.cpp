#include "flight.h"

Flight::Flight(string fromDest, string toDest)
{
    fromDestination = fromDest;
    toDestination = toDest;

    for (int i=0; i<22; i++) {
        for (int j=0; j<6; j++) {
            seats[i][j] = "frei";
        }
    }
}

void Flight::book()
{
    string vorname="", nachname="";
    char platzwunsch;
    char platz[6] = {'a','b','c','d','e','f'};
    bool found=false, noF=false, noG=false;

    cout << "Bitte Vornamen eingeben: ";
    cin >> vorname;
    cout << "Bitte Nachnamen eingeben: ";
    cin >> nachname;
    cout << "Waehlen Sie G fuer einen Gangplatz oder F fuer einen Fensterplatz: ";
    cin >> platzwunsch;

    if ((platzwunsch == 'F' || platzwunsch == 'f') && found==false) {
        for (int i=0; i<22; i++) {
            for (int j=0; j<=5; j+=5) {
                if (seats[i][j] == "frei" && found==false) {
                    //Freier Fensterplatz
                    seats[i][j] = vorname + ", " + nachname;
                    cout << "Wir haben Platz " << i+1 << platz[j] << " fuer Sie reserviert." << endl; //+1 weil array bei 0 startet
                    found=true;
                }
            }
        }
        if (found==false) {
            noF=true;
        }

    } else if ((platzwunsch == 'G' || platzwunsch == 'g') && found==false) {
        for (int i=0; i<22; i++) {
            for (int j=2; j<=3; j++) {
                if (seats[i][j] == "frei" && found==false) {
                    //Freier Gangplatz
                    seats[i][j] = vorname + ", " + nachname;
                    cout << "Wir haben Platz " << i+1 << platz[j] << " fuer Sie reserviert." << endl; //+1 weil array bei 0 startet
                    found=true;
                }
            }
        }
        if (found==false) {
            noG=true;
        }

    }

    if (found==false && noF==false) {
        for (int i=0; i<22; i++) {
            for (int j=0; j<=5; j+=5) {
                if (seats[i][j] == "frei" && found==false) {
                    //Freier Fensterplatz
                    seats[i][j] = vorname + ", " + nachname;
                    cout << "Wir haben Platz " << i+1 << platz[j] << " fuer Sie reserviert." << endl; //+1 weil array bei 0 startet
                    found=true;
                }
            }
        }
    }

    if (found==false && noG==false) {
        for (int i=0; i<22; i++) {
            for (int j=2; j<=3; j++) {
                if (seats[i][j] == "frei" && found==false) {
                    //Freier Gangplatz
                    seats[i][j] = vorname + ", " + nachname;
                    cout << "Wir haben Platz " << i+1 << platz[j] << " fuer Sie reserviert." << endl; //+1 weil array bei 0 startet
                    found=true;
                }
            }
        }
    }

    if (found==false) {
        for (int i=0; i<22; i++) {
            for (int j=1; j<=4; j+=3) {
                if (seats[i][j] == "frei" && found==false) {
                    //Übrige Plätze
                    seats[i][j] = vorname + ", " + nachname;
                    cout << "Wir haben Platz " << i+1 << platz[j] << " fuer Sie reserviert." << endl; //+1 weil array bei 0 startet
                    found=true;
                }
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

int Flight::countBookedSeats()
{
    int counter=0;
    for (int i=0; i<22; i++) {
        for (int j=0; j<6; j++) {
            if (seats[i][j] != "frei") {
                counter++;
            }
        }
    }
    return counter;
}

string Flight::getFromDestination() const
{
    return fromDestination;
}

string Flight::getToDestination() const
{
    return toDestination;
}
