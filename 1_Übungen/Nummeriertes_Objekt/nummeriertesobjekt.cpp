#include "nummeriertesobjekt.h"

// Initialisierung der klassenspezifischen Attribute:
int NummeriertesObjekt::anz = 0;
unsigned long NummeriertesObjekt::maxNummer = 11L;
bool NummeriertesObjekt::testmodus = false;


//Nächste Seriennummer (Seriennummern, die auf 13 enden überspringen)
unsigned long NummeriertesObjekt::nextNumber()
{
    if(maxNummer%100 == 12) {
        maxNummer+=2;
    } else {
        maxNummer++;
    }
    return maxNummer;
}

// Standard-Konstruktor
NummeriertesObjekt::NummeriertesObjekt()
: serienNr(nextNumber()) {
    ++anz;
    if (testmodus) {
        if (serienNr == 1)
            cout << "Start der Objekterzeugung!\n";
        cout << " Objekt Nr. "
                << serienNr << " erzeugt" << endl;
    }
}

// Kopierkonstruktor
NummeriertesObjekt::NummeriertesObjekt(const NummeriertesObjekt& X)
: serienNr(nextNumber()) {
    ++anz;
    if (testmodus)
        cout << " Objekt Nr. " << serienNr
            << " mit Nr. " << X.seriennummer()
        << " initialisiert" << endl;
    ;
}

// Destruktor
NummeriertesObjekt::~NummeriertesObjekt() {
    anz--;
    if (testmodus) {
        cout << " Objekt Nr. "
                << serienNr << " geloescht" << endl;
        if (anz == 0)
            cout << "letztes Objekt geloescht!" << endl;
        if (anz < 0) // deshalb int und nicht unsigned int
            cout << " FEHLER! zu oft delete aufgerufen!"
                << endl;
    } else assert(anz >= 0);
}
