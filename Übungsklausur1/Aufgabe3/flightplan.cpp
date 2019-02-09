#include "flightplan.h"

Flightplan::Flightplan()
{
    initialize();
}

void Flightplan::book()
{
    string fromDestination="", toDestination="";

    cout << "Bitte Startort eingeben: ";
    cin >> fromDestination;
    cout << "Bitte Zielort eingeben: ";
    cin >> toDestination;

    if (fromDestination == "Hamburg") {
        if (toDestination == "Leipzig") {
            HamburgLeipzig.book();
        } else if (toDestination == "Muenchen") {
            HamburgMuenchen.book();
        } else {
            cout << "Fehlerhafte Eingabe!" << endl;
        }
    } else if (fromDestination == "Leipzig") {
        if (toDestination == "Hamburg") {
            LeipzigHamburg.book();
        } else {
            cout << "Fehlerhafte Eingabe!" << endl;
        }
    } else if (fromDestination == "Muenchen") {
        if (toDestination == "Hamburg") {
            MuenchenHamburg.book();
        } else {
            cout << "Fehlerhafte Eingabe!" << endl;
        }
    } else {
        cout << "Fehlerhafte Eingabe!" << endl;
    }

}

void Flightplan::cancel()
{
    string fromDestination="", toDestination="";

    cout << "Bitte Startort eingeben: ";
    cin >> fromDestination;
    cout << "Bitte Zielort eingeben: ";
    cin >> toDestination;

    if (fromDestination == "Hamburg") {
        if (toDestination == "Leipzig") {
            HamburgLeipzig.cancel();
        } else if (toDestination == "Muenchen") {
            HamburgMuenchen.cancel();
        } else {
            cout << "Fehlerhafte Eingabe!" << endl;
        }
    } else if (fromDestination == "Leipzig") {
        if (toDestination == "Hamburg") {
            LeipzigHamburg.cancel();
        } else {
            cout << "Fehlerhafte Eingabe!" << endl;
        }
    } else if (fromDestination == "Muenchen") {
        if (toDestination == "Hamburg") {
            MuenchenHamburg.cancel();
        } else {
            cout << "Fehlerhafte Eingabe!" << endl;
        }
    } else {
        cout << "Fehlerhafte Eingabe!" << endl;
    }
}

void Flightplan::show_bookings()
{
    string fromDestination="", toDestination="";

    cout << "Bitte Startort eingeben: ";
    cin >> fromDestination;
    cout << "Bitte Zielort eingeben: ";
    cin >> toDestination;

    if (fromDestination == "Hamburg") {
        if (toDestination == "Leipzig") {
            HamburgLeipzig.show_bookings();
        } else if (toDestination == "Muenchen") {
            HamburgMuenchen.show_bookings();
        } else {
            cout << "Fehlerhafte Eingabe!" << endl;
        }
    } else if (fromDestination == "Leipzig") {
        if (toDestination == "Hamburg") {
            LeipzigHamburg.show_bookings();
        } else {
            cout << "Fehlerhafte Eingabe!" << endl;
        }
    } else if (fromDestination == "Muenchen") {
        if (toDestination == "Hamburg") {
            MuenchenHamburg.show_bookings();
        } else {
            cout << "Fehlerhafte Eingabe!" << endl;
        }
    } else {
        cout << "Fehlerhafte Eingabe!" << endl;
    }
}

void Flightplan::initialize()
{
    HamburgLeipzig.setFromDestination("Hamburg");
    HamburgLeipzig.setToDestination("Leipzig");

    LeipzigHamburg.setFromDestination("Leipzig");
    LeipzigHamburg.setToDestination("Hamburg");

    HamburgMuenchen.setFromDestination("Hamburg");
    HamburgMuenchen.setToDestination("Muenchen");

    MuenchenHamburg.setFromDestination("Muenchen");
    MuenchenHamburg.setToDestination("Hamburg");
}

void Flightplan::overview()
{
    cout << "Hamburg-Leipzig: " << HamburgLeipzig.countBookedSeats() << " von 132 Plaetzen besetzt." << endl
         << "Leipzig-Hamburg: " << LeipzigHamburg.countBookedSeats() << " von 132 Plaetzen besetzt." << endl
         << "Hamburg-Muenchen: " << HamburgMuenchen.countBookedSeats() << " von 132 Plaetzen besetzt." << endl
         << "Muenchen-Hamburg: " << MuenchenHamburg.countBookedSeats() << " von 132 Plaetzen besetzt." << endl;
}
