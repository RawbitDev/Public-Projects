#ifndef FERIENPROGRAMM_H
#define FERIENPROGRAMM_H

#include <iostream>
#include <vector>
#include <angebot.h>
using namespace std;

class Ferienprogramm
{
public:
    Ferienprogramm();
    void mainDialog();
    void angebotEintragen();
    void angeboteAnzeigen();
    void angebotLoeschen();
    void kindAnmelden();
    void buchungslisteAnzeigen();
private:
    vector<Angebot> angebotsListe;
    int start;
    int ende;
};

#endif // FERIENPROGRAMM_H
