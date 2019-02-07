#include "material.h"

Material::Material(int number, string text, int new_stock)
{
    matNumber = number;
    matText = text;
    stock = new_stock;
}

void Material::changeStock(int number)
{
    stock += number;
}

void Material::addLocation(int loc)
{
    locations.push_back(loc);
}

int Material::getLastLocation()
{
    int tempLoc = locations.at(locations.size()-1);
    locations.pop_back();
    return tempLoc;
}

int Material::getMatNumber() const
{
    return matNumber;
}

int Material::getStock() const
{
    return stock;
}
