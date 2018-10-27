//Vigenère Chiffre Entschlüsselung - by GitHub.com/RawbitDev
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string chiffre, schluessel;
    int error = 0;
    unsigned int x = 0;

    cout << "VIGENERE CHIFFRE - ENTSCHLUESSELUNG" << endl;
    cout << "===================================" << endl;
    cout << "Achtung: Bitte nur Grossbuchstaben und keine Leerzeichen verwenden!" << endl << endl;

    cout << "Bitte Chiffre eingeben: ";
    getline (cin, chiffre);
    cout << "Bitte Schluessel eingeben (kein Wiederholen notwendig): ";
    getline (cin, schluessel);

    char chiffrechar[chiffre.size()];
    char inputschluesselchar[chiffre.size()];
    char schluesselchar[chiffre.size()];
    int caesarverschiebung[chiffre.size()];
    char klartext[chiffre.size()];

    chiffre.copy(chiffrechar, chiffre.size());
    schluessel.copy(inputschluesselchar, chiffre.size());

    for (unsigned int i=0; i < chiffre.size(); i++) {

        if (x > schluessel.size()-1) {
            x = 0;
        }
        schluesselchar[i] = inputschluesselchar[x];

        int tempschluessel = schluesselchar[i];
        int tempchiffre = chiffrechar[i];

        if ((error != 0) || (tempchiffre < 65) || (tempchiffre > 90) || (tempschluessel < 65) || (tempschluessel > 90)) {
            error = 1;
        } else {
            caesarverschiebung[i] = tempschluessel - 65;
            char tempklartext = tempchiffre - caesarverschiebung[i];
            klartext[i] = tempklartext;
            x++;
        }

    }

    if (error == 0) {

        cout << endl << "Chiffre \t\t";
        for (unsigned int i=0; i < chiffre.size(); i++) {
            cout << chiffrechar[i];
        }
        cout << endl << "Schluessel \t\t";
        for (unsigned int i=0; i < chiffre.size(); i++) {
            cout << schluesselchar[i];
        }
        cout << endl << "CAESAR Verschiebung \t";
        for (unsigned int i=0; i < chiffre.size(); i++) {
            cout << caesarverschiebung[i];
        }
        cout << endl << "Klartext \t\t";
        for (unsigned int i=0; i < chiffre.size(); i++) {
            cout << klartext[i];
        }
        cout << endl << endl;

    } else {
        cerr << "Fehler bei der Eingabe!" << endl;
    }

    return 0;
}
