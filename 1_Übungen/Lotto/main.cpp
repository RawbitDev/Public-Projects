#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    bool ls[7][7];

    for (int i=0; i<7; i++) {
        for (int j=0; j<7; j++) {
            ls[i][j] = false;
        }
    }

    for (int i=1, x; i<=6; i++) {
        do {
            cout << i << ". Zahl> ";
            cin >> x;
            x -= 1;
        } while (ls[x/7][x%7] == true || x>48 || x<0);
        ls[x/7][x%7] = true;
    }

    for (int i=0; i<7; i++) {
        for (int j=0; j<7; j++) {
            if (ls[i][j] == false) {
                cout << "O ";
            } else {
                cout << "X ";
            }
        }
        cout << endl;
    }

    return 0;
}
