#include <iostream>
using namespace std;

int main()
{
    int n, f1=1, f2=1;
    cout << "n> ";
    cin >> n;

    for(int i=n; i>1; i--) {
        f1 *= i;
    }
    cout << "f1: " << f1 << endl;

    int j=n;
    do{
        f2*= j;
        j--;
    } while (j>1);
    cout << "f2: " << f2 << endl;

    return 0;
}
