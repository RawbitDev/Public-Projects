#include <iostream>

using namespace std;

int main()
{
    string Text = "";

    cout << "Text eingeben> ";
    //cin >> Text;
    getline(cin, Text);

    if (Text == "") {
        cout << "Error: Die Eingabe war leer!" << endl;
    } else {
        cout << "Die Eingabe war '" << Text << "'" << endl;
    }

    return 0;
}
