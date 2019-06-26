#include "angebot.h"

static int id = 0;
int angebotsID() {
    return ++id;
}

Angebot::Angebot(string Title, int Plaetze, int Kw)
{
    id = angebotsID();
    titel = Title;
    plaetze = Plaetze;
    kw = Kw;
    voll = false;
    teilnehmer = new Kind[plaetze];
    for (int i=0; i<plaetze; i++) {
        teilnehmer[i].vorname = "";
        teilnehmer[i].nachname = "";
        teilnehmer[i].geburtsdatum = "";
    }
}

Angebot::~Angebot()
{
    delete teilnehmer;
}

void Angebot::kindAufnehmen(Kind kind)
{
    teilnehmer[plaetze-freiePlaetze()] = kind;
    cout << "Kind erfolgreich angemeldet." << endl;

    if(freiePlaetze() <= 1) {
        voll = true;
    }
}

void Angebot::buchungslisteAnzeigen()
{
    if (plaetze != freiePlaetze()) {
        for(int i=0; i<(plaetze-freiePlaetze()); i++) {
            cout << i+1 << ": " << teilnehmer[i].nachname << ", " << teilnehmer[i].vorname << "\t(Geb. " << teilnehmer[i].geburtsdatum << ")" << endl;
        }
    } else {
        cout << "Keine Teilnehmer angemeldet." << endl;
    }
}

int Angebot::freiePlaetze()
{
    int counter=0;
    for(int i=0; i<plaetze; i++) {
        if(teilnehmer[i].vorname == "" && teilnehmer[i].nachname == "" && teilnehmer[i].geburtsdatum == "") {
            counter++;
        }
    }
    return counter;
}

bool Angebot::istVoll() const
{
    return voll;
}

int Angebot::getPlaetze() const
{
    return plaetze;
}

string Angebot::getTitel() const
{
    return titel;
}

int Angebot::getId() const
{
    return id;
}

int Angebot::getKw() const
{
    return kw;
}
