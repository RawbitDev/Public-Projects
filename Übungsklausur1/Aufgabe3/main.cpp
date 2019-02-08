#include <iostream>
#include <flightplan.h>

using namespace std;

int main()
{
    int input=0;
    Flightplan Fluege;

    cout << "1:  Platz buchen" << endl
         << "2:  Platz stornieren" << endl
         << "3:  Belegung anzeigen" << endl
         << "4:  Auslastungsuebersicht" << endl
         << "0:  Programm beenden" << endl;

    do {

        cout << "Auswahl> ";
        cin >> input;

        switch (input) {
            case 1: {Fluege.book();} break;
            case 2: {Fluege.cancel();} break;
            case 3: {Fluege.show_bookings();} break;
            case 4: {Fluege.overview();} break;
            case 0: break;
            default: {cout << "Fehlerhafte Eingabe!" << endl;} break;
        }

    } while (input!=0);

    return 0;
}
