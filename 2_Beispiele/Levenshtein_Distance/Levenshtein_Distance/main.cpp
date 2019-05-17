// Simple implementation example for the levenshtein distance by Ramon Walther
#include <iostream>
using namespace std;
double dist(string a, string b, bool debug=0);

int main()
{
    string tmp[2];
    double distance;
    do {
        for (unsigned int i=0; i<2; i++) {
            cout << i+1 << ". Input> ";
            getline(cin, tmp[i]);
        }
        distance = dist(tmp[0], tmp[1], 1);
        cout << "Distance: " << distance << endl << endl;
    } while (distance != 0.0);
    return 0;
}
