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

    for (int i=0; i < Flights.size(); i++) {
        if (Flights.at(i).getFromDestination() == fromDestination && Flights.at(i).getToDestination() == toDestination) {
            Flights.at(i).book();
            return;
        }
    }
    cout << "Fehlerhafte Eingabe!" << endl;
}

void Flightplan::cancel()
{
    string fromDestination="", toDestination="";

    cout << "Bitte Startort eingeben: ";
    cin >> fromDestination;
    cout << "Bitte Zielort eingeben: ";
    cin >> toDestination;

    for (int i=0; i < Flights.size(); i++) {
        if (Flights.at(i).getFromDestination() == fromDestination && Flights.at(i).getToDestination() == toDestination) {
            Flights.at(i).cancel();
            return;
        }
    }
    cout << "Fehlerhafte Eingabe!" << endl;
}

void Flightplan::show_bookings()
{
    string fromDestination="", toDestination="";

    cout << "Bitte Startort eingeben: ";
    cin >> fromDestination;
    cout << "Bitte Zielort eingeben: ";
    cin >> toDestination;

    for (int i=0; i < Flights.size(); i++) {
        if (Flights.at(i).getFromDestination() == fromDestination && Flights.at(i).getToDestination() == toDestination) {
            Flights.at(i).show_bookings();
            return;
        }
    }
    cout << "Fehlerhafte Eingabe!" << endl;
}

void Flightplan::initialize()
{
    string fromDestination="", toDestination="";
    int again=0;

    do {
        cout << "Neuer Flug wird eingerichtet." << endl;

        fromDestination="";
        toDestination="";

        cout << "Bitte Startort eingeben: ";
        cin >> fromDestination;
        cout << "Bitte Zielort eingeben: ";
        cin >> toDestination;

        Flights.push_back(Flight(fromDestination, toDestination));

        cout << "Moechten Sie einen weiteren Flug hinzufuegen?" << endl << "(Beliebige Zahl fuer JA, 0 zum Abbrechen): ";
        cin >> again;
    } while (again != 0);


}

void Flightplan::overview()
{
    //Sorting the array (Bubblesort)
    bool IsSorted = false;
    if (Flights.size() > 1) {
        do {
            IsSorted = true;
            for (int i=1; i < Flights.size(); i++) {
                if (Flights.at(i).countBookedSeats() > Flights.at(i-1).countBookedSeats()) {
                    Flight tempFlight = Flights.at(i-1);
                    Flights.at(i-1) = Flights.at(i);
                    Flights.at(i) = tempFlight;
                    IsSorted = false;
                }
            }
        } while (IsSorted == false);
    }


    for (int i=0; i < Flights.size(); i++) {
        cout << Flights.at(i).getFromDestination() << "-" << Flights.at(i).getToDestination() << ": " << Flights.at(i).countBookedSeats() << " von 132 Plaetzen besetzt." << endl;
    }
}
