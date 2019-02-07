#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <vector>
using namespace std;

class Material
{
public:
    Material(int number, string text, int stock);
    void changeStock(int number);
    void addLocation(int loc);
    int getLastLocation();
    int getMatNumber() const;
    int getStock() const;

private:
    int matNumber;
    string matText;
    int stock;
    vector <int> locations;
};

#endif // MATERIAL_H
