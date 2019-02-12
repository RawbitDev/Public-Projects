#include <iostream>
#include <flight.h>

using namespace std;

int main()
{
    int input=0;
    Flight HamburgMuenchen;

    cout << "1:  Platz buchen" << endl
         << "2:  Platz stornieren" << endl
         << "3:  Belegung anzeigen" << endl
         << "0:  Programm beenden" << endl;

    do {

        cout << "Auswahl> ";
        cin >> input;

        switch (input) {
            case 1: {HamburgMuenchen.book();} break;
            case 2: {HamburgMuenchen.cancel();} break;
            case 3: {HamburgMuenchen.show_bookings();} break;
            case 0: break;
            default: {cout << "Fehlerhafte Eingabe!" << endl;} break;
        }

    } while (input!=0);

    return 0;
}
