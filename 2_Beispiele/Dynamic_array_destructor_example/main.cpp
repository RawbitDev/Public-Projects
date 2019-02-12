#include <iostream>
#include <test.h>
using namespace std;

int main()
{
    const int size = 10;
    Test *p = new Test[size];

    p[0] = *new Test("A");
    p[1] = *new Test("B");

    cout << "*Deleting p..." << endl;
    delete[] p;

    cout << "*End" << endl;

    return 0;
}
