#include <iostream>
#include <warehouse.h>
#include <ctime>

using namespace std;

int main()
{
    srand(time_t(nullptr));
    Warehouse Lager;
    int input;

    cout << "1: Wareneingang buchen" << endl
         << "2: Warenausgang buchen" << endl
         << "0: Programmende" << endl;
    do {
        input = 0;
        cout << "Auswahl> ";
        cin >> input;

        switch (input) {
        case 1: Lager.goodsReceipt(); break;
        case 2: Lager.goodsIssue(); break;
        case 0: break;
        default: cout << "Fehlerhafte Eingabe!" << endl; break;
        }
    } while(input != 0);


    return 0;
}
