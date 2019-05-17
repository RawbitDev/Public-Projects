// Simple implementation example for the levenshtein distance by Ramon Walther
#include <iostream>
#include <iomanip>
using namespace std;

double dist(string a, string b, bool debug=0) {
    if(a.length()==0 || b.length()==0) return 0;
    int** m = new int*[b.length()+1];
    for(unsigned int i=0; i<=b.length(); i++) m[i] = new int[a.length()+1];
    for(unsigned int i=0; i<=a.length(); i++) m[0][i]=static_cast<int>(i);
    for(unsigned int i=0; i<=b.length(); i++) m[i][0]=static_cast<int>(i);

    for(unsigned int i=1; i<=b.length(); i++)
        for(unsigned int j=1; j<=a.length(); j++) {
            int diag = (tolower(a[j-1])==tolower(b[i-1]) ? m[i-1][j-1] : m[i-1][j-1]+1);
            m[i][j] = min(diag, min(m[i][j-1]+1, m[i-1][j]+1));
        }
    double dist = static_cast<double>(m[b.length()][a.length()]) / static_cast<double>(a.length()+b.length());

    if (debug) {
        int padding=static_cast<int>(to_string(m[0][a.length()]).length());
        a=" "+a;
        b=" "+b;
        cout << endl << "  " ;
        for(unsigned int i=0; i<a.length(); i++)
            cout << fixed << setfill(' ') << setw(padding) << a[i] << " ";
        for(unsigned int i=0; i<b.length(); i++) {
            cout << endl << b[i] << " ";
            for(unsigned int j=0; j<a.length(); j++)
                cout << fixed << setfill('0') << setw(padding) << m[i][j] << " ";
        }
        cout << endl << endl;
    }

    return dist;
}
