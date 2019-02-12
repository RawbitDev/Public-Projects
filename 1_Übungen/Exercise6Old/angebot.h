#ifndef ANGEBOT_H
#define ANGEBOT_H

#include <iostream>
#include <vector>
using namespace std;

struct Kind {
    string vorname;
    string nachname;
    string geburtsdatum;
};

class Angebot
{
public:
    ~Angebot();
    Angebot(string Title, int Plaetze, int kw);
    void kindAufnehmen(Kind kind);
    void buchungslisteAnzeigen();
    int freiePlaetze();
    bool istVoll() const;
    int getPlaetze() const;
    string getTitel() const;
    int getId() const;
    int getKw() const;

private:
    int plaetze;
    string titel;
    int id;
    Kind *teilnehmer;
    bool voll;
    int kw;
};

#endif // ANGEBOT_H
