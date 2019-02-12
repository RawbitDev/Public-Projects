#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <material.h>
#include <vector>

class Warehouse
{
public:
    Warehouse();
    void goodsReceipt();
    void goodsIssue();
    void createMaterial();
private:
    static const int maxBins = 840;
    int storageBins[maxBins];
    vector <Material*> material;
};

#endif // WAREHOUSE_H
