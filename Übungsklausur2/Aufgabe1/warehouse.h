#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <material.h>

class Warehouse
{
public:
    Warehouse();
    void goodsReceipt();
    void goodsIssue();
private:
    static const int maxBins = 840;
    int storageBins[maxBins];
    Material *material;
};

#endif // WAREHOUSE_H
