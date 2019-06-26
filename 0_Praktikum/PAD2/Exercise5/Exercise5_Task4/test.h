// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef TEST_H
#define TEST_H

#include <QtTest/QTest>
#include <travelagency.h>
using namespace std;

class Test : public QObject
{
    Q_OBJECT
private slots:
    void testReadFile();
    void testRoundtrip();
    void testNeedlessHotel();
    void testMissingHotel();
private:
    TravelAgency ta;
};

#endif // TEST_H
