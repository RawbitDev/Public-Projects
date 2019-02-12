#include <iostream>
using namespace std;

int main()
{
    double r,f,u;
    const double pi = 3.1416;

    cout << "Radius> ";
    cin >> r;

    f=pi*r*r;
    u=2*pi*r;

    cout << "Flaeche: " << f << endl;
    cout << "Umfang: " << u << endl;
    return 0;
}
