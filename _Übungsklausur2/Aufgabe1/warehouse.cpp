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
    struct Lagerplatz{int raw=0; int Regal=0; int Ebene=0; int Fach=0;} lagerplatz;

    do {
        lagerplatz.raw = rand()%maxBins;
    } while(lagerplatz.raw == -1);

    storageBins[lagerplatz.raw] = material->getMatNumber();
    material->changeStock(+1);

    lagerplatz.Regal = lagerplatz.raw/(maxBins/14);
    lagerplatz.Ebene = (lagerplatz.raw%(maxBins/14))/10;
    lagerplatz.Fach = (lagerplatz.raw%(maxBins/14))%10;

    cout << "Palette eingelagert in Regal " << lagerplatz.Regal+1 << ", Fach " << lagerplatz.Fach+1 << ", Ebene " << lagerplatz.Ebene+1 << endl;
}

void Warehouse::goodsIssue()
{
    for (int i=0; i<maxBins; i++) {
        if (storageBins[i] != -1) {

            struct Lagerplatz{int raw=0; int Regal=0; int Ebene=0; int Fach=0;} lagerplatz;
            lagerplatz.raw = i;

            lagerplatz.Regal = lagerplatz.raw/(maxBins/14);
            lagerplatz.Ebene = (lagerplatz.raw%(maxBins/14))/10;
            lagerplatz.Fach = (lagerplatz.raw%(maxBins/14))%10;

            storageBins[i] = -1;
            cout << "Palette ausgelagert aus Regal " << lagerplatz.Regal+1 << ", Fach " << lagerplatz.Fach+1 << ", Ebene " << lagerplatz.Ebene+1 << endl;

            material->changeStock(-1);
            cout << "Verbleibender Bestand: " << material->getStock() << endl;

            return;
        }
    }
    cout << "Es wurde keine Palette gefunden!" << endl;
}
