#include <iostream>

using namespace std;

class TestObject
{
public:
    string text;
};

void printFunction(TestObject testArray[5][5], int posX, int posY)
{
    cout << testArray[posX][posY].text << endl;
}

int main()
{
    TestObject testArray[5][5];
    TestObject testOutput;

    testOutput.text = "Dies ist ein Test.";
    testArray[2][4] = testOutput;

    printFunction(testArray, 2, 4);

    return 0;
}
