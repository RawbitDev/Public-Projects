#include "warehouse.h"

Warehouse::Warehouse()
{
    material = new Material(1, "Daemmstoff_16cm", 0);

    for (int i=0; i<maxBins; i++) {
        storageBins[i] = -1;
    }
}

void Warehouse::goodsReceipt()
{
    int input;
    do {
        input = 0;
        cout << "Bitte Menge der Paletten angeben: ";
        cin >> input;
    } while((input > 0 && input <= maxBins) == false);

    if ((material->getStock()+input)>maxBins) {
        cout << "Es sind nicht genuegen Plaetze im Lager frei!" << endl;
    } else {
        for(int i=0; i<input; i++) {

            struct Lagerplatz{int raw=0; int Regal=0; int Ebene=0; int Fach=0;} lagerplatz;

            do {
                lagerplatz.raw = rand()%maxBins;
            } while(lagerplatz.raw == -1);

            storageBins[lagerplatz.raw] = material->getMatNumber();
            material->changeStock(+1);

            lagerplatz.Regal = lagerplatz.raw/(maxBins/14);
            lagerplatz.Ebene = (lagerplatz.raw%(maxBins/14))/10;
            lagerplatz.Fach = (lagerplatz.raw%(maxBins/14))%10;

            cout << i+1 << ". Palette eingelagert in Regal " << lagerplatz.Regal+1 << ", Fach " << lagerplatz.Fach+1 << ", Ebene " << lagerplatz.Ebene+1 << endl;

        }
    }

}

void Warehouse::goodsIssue()
{
    int input;
    do {
        input = 0;
        cout << "Bitte Menge der Paletten angeben: ";
        cin >> input;
    } while((input > 0 && input <= maxBins) == false);

    if ((material->getStock()-input)<0) {
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

                    material->changeStock(-1);
                    break;
                }
            }
        }
        cout << "Verbleibender Bestand: " << material->getStock() << endl;
    }
}
