#ifndef TEST_H
#define TEST_H

#include <iostream>
using namespace std;

class Test
{
public:
    Test();
    Test(string Name);
    ~Test();
private:
    string name;
};

#endif // TEST_H
