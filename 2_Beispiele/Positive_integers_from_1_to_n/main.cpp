#include <iostream>
using namespace std;

// Outputs every positive integer from 1 to n
int main()
{
    int n, i = 1;
    cout << "Geben Sie eine positive ganze Zahl ein: ";
    cin >> n;
    if ((n%2 == 0) && (n > 1)) {
        do {
            if (i%2 == 0) {
                cout << i << endl;
            }
            i++;
        } while (i <= n);
    } else {
        cerr << "Fehler bei der Eingabe!" << endl;
    }
    return 0;
}
