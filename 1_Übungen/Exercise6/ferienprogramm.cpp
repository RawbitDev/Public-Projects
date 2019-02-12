#include "ferienprogramm.h"

Ferienprogramm::Ferienprogramm()
{
    start=26;
    ende=32;
}

void Ferienprogramm::mainDialog()
{
    cout << "Willkommen zum Kinderferienprogramm der Stadt Darmstadt." << endl
         << "Ihnen stehen folgende Funktionen zur Verfuegung:" << endl
         << "1: Neues Angebot eintragen" << endl
         << "2: Alle Angebote anzeigen" << endl
         << "3: Kind fuer ein Angebot anmelden" << endl
         << "4: Buchungsliste fuer ein Angebot anzeigen" << endl
         << "5: Angebot loeschen" << endl << endl
         << "0: Zum Beenden des Programmes" << endl << endl;

    int input=0;
    do{
        cout << "Auswahl> ";
        cin >> input;
    } while(input < 0 || input > 5);

    switch (input) {
        case 1: angebotEintragen(); break;
        case 2: angeboteAnzeigen(); break;
        case 3: kindAnmelden(); break;
        case 4: buchungslisteAnzeigen(); break;
        case 5: angebotLoeschen(); break;
        case 0: exit(0);
    }
}

void Ferienprogramm::angebotEintragen()
{
    string titel="";
    cout << "Titel des Angebotes? ";
    cin >> titel;

    int anzahl=0;
    do {
        cout << "Anzahl der Plaetze? ";
        cin >> anzahl;
    } while(anzahl<1);

    int kw=0;
    do {
        cout << "Kalenderwoche (" << start << "-" << ende << ")? ";
        cin >> kw;
        if (kw<start || kw>ende) {
            cout << "Eingegebene Kalenderwoche liegt ausserhalb der Dauer des Ferienprogrammes!" << endl;
        }
    } while(kw<start || kw>ende);

    cout << endl;

    angebotsListe.push_back(Angebot(titel, anzahl, kw));
}

void Ferienprogramm::angeboteAnzeigen()
{
    if (int(angebotsListe.size()) <= 0) {
        cout << "Aktuell sind noch keine Angebote vorhanden. Legen Sie bitte zuerst ein Angebot an." << endl;
        angebotEintragen();
        return;
    } else {
        for(int i=0; i<int(angebotsListe.size()); i++) {
            cout << angebotsListe.at(i).getId() << ":\t" << angebotsListe.at(i).getTitel() << "\tKW " << angebotsListe.at(i).getKw() << "\t" << angebotsListe.at(i).getPlaetze() << " Plaetze\t" << "Noch " << angebotsListe.at(i).freiePlaetze() << " freie Plaetze" << endl;
        }
        cout << endl;
    }
}

void Ferienprogramm::angebotLoeschen()
{
    int pos = InputIdPosDialog();

    if (pos >= 0) {
        if(angebotsListe.at(pos).freiePlaetze() == angebotsListe.at(pos).getPlaetze()) {
            angebotsListe.erase(angebotsListe.begin()+pos);
            cout << "Ausgewaehltes Angebot erfolgreich geloescht." << endl;
        } else {
            cout << "Loeschen nicht moeglich! Es sind noch Kinder fuer das ausgewaehltes Angebot angemeldet." << endl;
        }
    }
    cout << endl;
}

void Ferienprogramm::kindAnmelden()
{
    int pos = InputIdPosDialog();

    if(angebotsListe.at(pos).istVoll()) {
        cout << "Das ausgewaehlte Angebot is bereits voll." << endl;
    } else {
        string Vorname="", Nachname="", Geburtsdatum="";
        cout << "Vorname: ";
        cin >> Vorname;
        cout << "Nachname: ";
        cin >> Nachname;
        cout << "Geburtsdatum: ";
        cin >> Geburtsdatum;
        cout << endl;

        angebotsListe.at(pos).kindAufnehmen(Kind{Vorname, Nachname, Geburtsdatum});
        cout << endl;
    }
}

void Ferienprogramm::buchungslisteAnzeigen()
{
    int pos = InputIdPosDialog();
    if (pos >= 0) {
        angebotsListe.at(pos).buchungslisteAnzeigen();
    }
    cout << endl;
}

int Ferienprogramm::InputIdPosDialog()
{
    if(int(angebotsListe.size()) <= 0) {
        cout << "Aktuell sind noch keine Angebote vorhanden. Legen Sie bitte zuerst ein Angebot an." << endl;
        angebotEintragen();
        return -1;
    }

    int id=0;
    cout << "Waehlen Sie ein Angebot: ";
    cin >> id;

    if(id <= 0) {
        cout << "Eigegebene ID muss groesser als 0 sein!" << endl;
    } else {
        for(int i=0; i<int(angebotsListe.size()); i++) {
            if (angebotsListe.at(i).getId() == id) {
                return i;
            }
        }
        cout << "Eigegebene ID wurde nicht gefunden." << endl;
    }
    return -1;
}
