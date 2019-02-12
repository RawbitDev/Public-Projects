#ifndef NUMOBJ_H
#define	NUMOBJ_H
#include <iostream>
#include <cassert>
using namespace std;

class NummeriertesObjekt {
public:
    NummeriertesObjekt();
    NummeriertesObjekt(const NummeriertesObjekt&);
    ~NummeriertesObjekt();
    unsigned long nextNumber();

    unsigned long seriennummer() const {
        return serienNr;
    }

    static int anzahl() {
        return anz;
    }
    static bool testmodus;
private:
    static int anz;
    static unsigned long maxNummer;
    const unsigned long serienNr;
};
#endif	/* NUMOBJ_H */

