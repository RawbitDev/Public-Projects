#include <iostream>
using namespace std;

void CombineToReference(string a, string b, string &r) {
    r = a + " " + b;
}

void CombineToPointer(string a, string b, string *r) {
    *r = a + " " + b;
}

int main()
{
    string s1,s2,e;
    s1 = "Hello";
    s2 = "World!";

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;

    CombineToReference(s1,s2,e);
    cout << "Reference: " << e << endl;

    CombineToPointer(s1,s2,&e);
    cout << "Pointer: " << e << endl;

    return 0;
}
