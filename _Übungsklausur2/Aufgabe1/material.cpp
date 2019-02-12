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

int Material::getMatNumber() const
{
    return matNumber;
}

int Material::getStock() const
{
    return stock;
}
