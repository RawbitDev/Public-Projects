#include <iostream>

using namespace std;

char* toChar(string s) {
    char* r = new char[s.size()];
    for(int i=0; i<int(s.size()); i++) {
        r[i] = s.at(size_t(i));
    }
    return r;
}

int main()
{
    string s;
    char* c;

    //Input
    cout << "Eingabe> ";
    cin >> s;

    //Convert to char array
    c = toChar(s);

    //Output
    for(int i=0; i<int(s.size()); i++) {
        cout << i << ": " << c[i] << endl;
    }

    //Delete dynamic array
    delete[] c;

    return 0;
}
