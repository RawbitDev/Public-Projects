#include "warehouse.h"

Warehouse::Warehouse()
{
    for (int i=0; i<maxBins; i++) {
        storageBins[i] = -1;
    }
}

void Warehouse::goodsReceipt()
{
    int inputMatNumber;
    do {
        inputMatNumber = 0;
        cout << "Bitte Materialnummer angeben: ";
        cin >> inputMatNumber;
    } while(inputMatNumber < 0);

    int foundMat = -1;
    for(int i=0; i<material.size(); i++) {
        if (material.at(i)->getMatNumber() == inputMatNumber) {
            foundMat = i;
            break;
        }
    }

    if (foundMat < 0) {
        cout << "Material konnte nicht gefunden werden!" << endl;
    } else {

        int input;
        do {
            input = 0;
            cout << "Bitte Menge der Paletten angeben: ";
            cin >> input;
        } while((input > 0 && input <= maxBins) == false);

        if (((material.at(foundMat)->getStock())+input)>maxBins) {
            cout << "Es sind nicht genuegen Plaetze im Lager frei!" << endl;
        } else {
            for(int i=0; i<input; i++) {

                struct Lagerplatz{int raw=0; int Regal=0; int Ebene=0; int Fach=0;} lagerplatz;

                do {
                    lagerplatz.raw = rand()%maxBins;
                } while(lagerplatz.raw == -1);

                storageBins[lagerplatz.raw] = material.at(foundMat)->getMatNumber();
                material.at(foundMat)->changeStock(+1);

                lagerplatz.Regal = lagerplatz.raw/(maxBins/14);
                lagerplatz.Ebene = (lagerplatz.raw%(maxBins/14))/10;
                lagerplatz.Fach = (lagerplatz.raw%(maxBins/14))%10;

                cout << i+1 << ". Palette eingelagert in Regal " << lagerplatz.Regal+1 << ", Fach " << lagerplatz.Fach+1 << ", Ebene " << lagerplatz.Ebene+1 << endl;

            }
        }

    }

}

void Warehouse::goodsIssue()
{
    int inputMatNumber;
    do {
        inputMatNumber = 0;
        cout << "Bitte Materialnummer angeben: ";
        cin >> inputMatNumber;
    } while(inputMatNumber < 0);

    int foundMat = -1;
    for(int i=0; i<material.size(); i++) {
        if (material.at(i)->getMatNumber() == inputMatNumber) {
            foundMat = i;
            break;
        }
    }

    if (foundMat < 0) {
        cout << "Material konnte nicht gefunden werden!" << endl;
    } else {

        int input;
        do {
            input = 0;
            cout << "Bitte Menge der Paletten angeben: ";
            cin >> input;
        } while((input > 0 && input <= maxBins) == false);

        if ((material.at(foundMat)->getStock()-input)<0) {
            cout << "Es sind nicht genuegen Paletten im Lager vorhanden!" << endl;
        } else {
            for(int j=0; j<input; j++) {
                for (int i=0; i<maxBins; i++) {
                    if (storageBins[i] != -1) {

                        struct Lagerplatz{int raw=0; int Regal=0; int Ebene=0; int Fach=0;} lagerplatz;
                        lagerplatz.raw = i;

                        lagerplatz.Regal = lagerplatz.raw/(maxBins/14);
                        lagerplatz.Ebene = (lagerplatz.raw%(maxBins/14))/10;
                        lagerplatz.Fach = (lagerplatz.raw%(maxBins/14))%10;

                        storageBins[i] = -1;
                        cout << j+1 << ". Palette ausgelagert aus Regal " << lagerplatz.Regal+1 << ", Fach " << lagerplatz.Fach+1 << ", Ebene " << lagerplatz.Ebene+1 << endl;

                        material.at(foundMat)->changeStock(-1);
                        break;
                    }
                }
            }
            cout << "Verbleibender Bestand: " << material.at(foundMat)->getStock() << endl;
        }

    }
}

void Warehouse::createMaterial()
{
    int inputMatNumber;
    do {
        inputMatNumber = 0;
        cout << "Bitte Materialnummer angeben: ";
        cin >> inputMatNumber;
    } while(inputMatNumber < 0);

    string inputMatText;
    do {
        inputMatText = "";
        cout << "Bitte Materialtext angeben: ";
        cin >> inputMatText;
    } while(inputMatText == "");

    material.push_back(new Material(inputMatNumber, inputMatText, 0));
}
