#include <iostream>

using namespace std;

int main()
{
    int i, diff;
    int *p = &i;

    cout << "Eingabe> ";
    cin >> *p;

    diff = (int(&i) - int(&p));

    cout << "Adresse &i: " << &i << endl;
    cout << "Adresse &p: " << &p << endl;

    cout << "Wert i: " << i << endl;
    cout << "Differenz: " << diff << endl;
    cout << "Ergebnis: " << i+diff << endl;

    return 0;
}
