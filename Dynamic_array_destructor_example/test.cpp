#include "test.h"

Test::Test()
{

}

Test::Test(string Name)
{
    name = Name;
    cout << "Born " << name << endl;
}

Test::~Test()
{
    cout << "Killed " << name << endl;
}
