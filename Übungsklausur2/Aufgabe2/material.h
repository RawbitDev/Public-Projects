#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
using namespace std;

class Material
{
public:
    Material(int number, string text, int stock);
    void changeStock(int number);
    int getMatNumber() const;
    int getStock() const;

private:
    int matNumber;
    string matText;
    int stock;
};

#endif // MATERIAL_H
