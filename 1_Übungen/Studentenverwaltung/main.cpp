#include <iostream>
#include <vector>
using namespace std;

int main()
{
    enum Studiengang{Bachelor = 0, Kosi, Master, JIM};

    struct Student{
      string vorname;
      string name;
      long matrikelnr;
      Studiengang studiengang;
    };

    vector <Student> Teilnehmer;
    string input;
    bool again;
    char again_input;

    do {
        cout << "Neuen Student anlegen:" << endl;
        Student Temp;

        cout << "Vorname> ";
        cin >> Temp.vorname;

        cout << "Name> ";
        cin >> Temp.name;

        cout << "Matrikelnummer> ";
        cin >> Temp.matrikelnr;

        do {
            cout << "Studiengang> ";
            cin >> input;
            if (input == "Bachelor") {
                Temp.studiengang = Bachelor;
                break;
            } else if (input == "Kosi") {
                Temp.studiengang = Kosi;
                break;
            } else if (input == "Master") {
                Temp.studiengang = Master;
                break;
            } else if (input == "JIM") {
                Temp.studiengang = JIM;
                break;
            }
        } while (true);

        Teilnehmer.push_back(Temp);

        do {
            cout << endl << "Weiteren Studenten anlegen (j/n)? ";
            cin >> again_input;
            if (again_input == 'n') {
                again = false;
                break;
            } else if (again_input == 'j') {
                again = true;
                break;
            }
        } while (true);

    } while (again == true);

    cout << endl << "Teilnehmerliste:" << endl;
    for(int i=0, j=1; i<int(Teilnehmer.size()); i++) {
        if ((Teilnehmer.at(size_t(i)).studiengang == 2 || Teilnehmer.at(size_t(i)).studiengang == 3) && Teilnehmer.at(size_t(i)).name.at(0) == 'M') {
            cout << j << ":\t" << Teilnehmer.at(size_t(i)).vorname << ", " << Teilnehmer.at(size_t(i)).name << " (" << Teilnehmer.at(size_t(i)).matrikelnr << ")\t";
            if (Teilnehmer.at(size_t(i)).studiengang == 2) {
                cout << "[Master]" << endl;
            } else if (Teilnehmer.at(size_t(i)).studiengang == 3) {
                cout << "[JIM]" << endl;
            }
            j++;
        }
    }

    return 0;
}
