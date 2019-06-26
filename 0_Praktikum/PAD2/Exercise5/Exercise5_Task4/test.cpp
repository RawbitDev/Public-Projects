// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "test.h"

void Test::testReadFile()
{
    ta.readFile();
    QCOMPARE(ta.getNumBookings(), 87);
    QCOMPARE(ta.getPercentSmokerHotels(), 32);
}

void Test::testRoundtrip()
{
    QCOMPARE(ta.findTravel(16)->checkRoundtrip(), false);
}

void Test::testNeedlessHotel()
{
    QCOMPARE(ta.findTravel(6)->checkNeedlessHotel(), false);
}

void Test::testMissingHotel()
{
    QCOMPARE(ta.findTravel(2)->checkMissingHotel(), false);
}
