// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include <iostream>
#include <iomanip>
using namespace std;

double dist(string a, string b) {
    if(a.length()==0 || b.length()==0) return 0; // If the lenght is 0, the dist is gonna be 0 too

    // Create a 2D Array with the lenght of string a and b
    int** m = new int*[b.length()+1];
    for(unsigned int i=0; i<=b.length(); i++) m[i] = new int[a.length()+1];

    // Fill the first column and row
    for(unsigned int i=0; i<=a.length(); i++) m[0][i]=static_cast<int>(i);
    for(unsigned int i=0; i<=b.length(); i++) m[i][0]=static_cast<int>(i);

    // Calculate the other fields of the matrix
    for(unsigned int i=1; i<=b.length(); i++)
        for(unsigned int j=1; j<=a.length(); j++) {
            int diag = (tolower(a[j-1])==tolower(b[i-1]) ? m[i-1][j-1] : m[i-1][j-1]+1);
            m[i][j] = min(diag, min(m[i][j-1]+1, m[i-1][j]+1));
        }

    // Return the final dist
    return static_cast<double>(m[b.length()][a.length()]) / static_cast<double>(a.length()+b.length());
}
