#include <iostream>
using namespace std;

bool isPrim(int n) {
    if(n>1) {
        for(int i=n-1; i>1; i--) {
            if(n%i == 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int nextPrim(int n) {
    n++;
    if(isPrim(n) == true) {
        return n;
    }
    return nextPrim(n);
}

void printPrims(int n) {
    for(int i=0, j=1; i<n; i++) {
        j = nextPrim(j);
        cout << j << endl;
    }
    return;
}

void toPrims(int n, int i=2) {
    if(n>1) {
        if(n%i == 0) {
            n /= i;
            cout << i << " * ";
            toPrims(n, i);
        } else {
            toPrims(n, nextPrim(i));
        }
    } else {
        cout << "\b\b " << endl;
    }
    return;
}

int main()
{
    toPrims(234);
    return 0;
}
