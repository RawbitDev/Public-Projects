#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
using namespace std;

class Flight
{
public:
    Flight();
    void book();
    void cancel();
    void show_bookings();
private:
    string seats[22][6];
};

#endif // FLIGHT_H
