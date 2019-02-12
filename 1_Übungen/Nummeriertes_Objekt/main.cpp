#include "nummeriertesobjekt.h"
#include<iostream>
using namespace std;

int main() {
    // Testmodus fuer alle Objekte der Klasse einschalten
    NummeriertesObjekt::testmodus = true;
    NummeriertesObjekt erstesNumObjekt; // ... wird erzeugt
    cout << "Die Seriennummer von erstesNumObjekt ist: "
            << erstesNumObjekt.seriennummer() << endl;

    // Anfang eines neuen Blocks
    {
        NummeriertesObjekt zweitesNumObjekt; // ... wird erzeugt

        cout << NummeriertesObjekt::anzahl()
                << " Objekte aktiv" << endl;

        // *p wird dynamisch erzeugt:
        NummeriertesObjekt* p = new NummeriertesObjekt;

        cout << NummeriertesObjekt::anzahl()
                << " Objekte aktiv" << endl;
        delete p; // *p wird geloescht

        cout << NummeriertesObjekt::anzahl()
                << " Objekte aktiv" << endl;

       // cout << "Fehler: ein  delete zuviel:" << endl;
       // delete p;
    } // Blockende: zweitesNumObjekt wird geloescht

    cout << NummeriertesObjekt::anzahl()
            << " Objekte aktiv" << endl;

    cout << " Kopierkonstruktor: " << endl;
    NummeriertesObjekt kopiertesNumObjekt = erstesNumObjekt;

    cout << "Die Seriennummer von kopiertesNumObjekt ist: "
            << kopiertesNumObjekt.seriennummer() << endl;

    // Zuweisung wird wegen Konstanz der serienNr vom Compiler verboten
    //kopiertesNumObjekt = erstesNumObjekt; // Fehler

    return 0;
}
