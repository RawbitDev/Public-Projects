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
    Student Temp;
    int found;
    bool again, sort;
    char again_input;

    //Input
    do {
        cout << "Neuen Student anlegen:" << endl;

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


    //Bubblesort
    do {
        sort = true;
        for(int i=1; i<int(Teilnehmer.size()); i++) {
            if ((Teilnehmer.at(size_t(i)).matrikelnr)<(Teilnehmer.at(size_t(i-1)).matrikelnr)) {
                Temp = Teilnehmer.at(size_t(i-1));
                Teilnehmer.at(size_t(i-1)) = Teilnehmer.at(size_t(i));
                Teilnehmer.at(size_t(i)) = Temp;
                sort = false;
            }
        }
    } while (sort == false);


    //Search
    cout << endl << "Teilnehmersuche:" << endl;
    cout << "Nachname> ";
    cin >> input;

    found = -1;
    for(int i=1; i<int(Teilnehmer.size()); i++) {
        if (Teilnehmer.at(size_t(i)).name == input) {
            found = i;
            break;
        }
    }
    if (found >= 0) {
        cout << "Found:\t" << Teilnehmer.at(size_t(found)).vorname << ", " << Teilnehmer.at(size_t(found)).name << " (" << Teilnehmer.at(size_t(found)).matrikelnr << ")\t";
        if (Teilnehmer.at(size_t(found)).studiengang == 0) {
            cout << "[Bachelor]" << endl;
        } else if (Teilnehmer.at(size_t(found)).studiengang == 1) {
            cout << "[Kosi]" << endl;
        } else if (Teilnehmer.at(size_t(found)).studiengang == 2) {
            cout << "[Master]" << endl;
        } else if (Teilnehmer.at(size_t(found)).studiengang == 3) {
            cout << "[JIM]" << endl;
        }
    } else {
        cout << "Nothing found." << endl;
    }


    //Output
    cout << endl << "Teilnehmerliste:" << endl;
    for(int i=0, j=1; i<int(Teilnehmer.size()); i++) {
        if ((Teilnehmer.at(size_t(i)).studiengang == 2 || Teilnehmer.at(size_t(i)).studiengang == 3) && ((Teilnehmer.at(size_t(i)).name.at(0) == 'M') || (Teilnehmer.at(size_t(i)).name.at(0) == 'm'))) {
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
