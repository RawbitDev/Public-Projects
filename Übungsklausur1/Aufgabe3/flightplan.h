#ifndef FLIGHTPLAN_H
#define FLIGHTPLAN_H

#include <iostream>
#include <flight.h>
using namespace std;

class Flightplan
{
public:
    Flightplan();
    void book();
    void cancel();
    void show_bookings();
    void initialize();
    void overview();
private:
    Flight HamburgLeipzig;
    Flight LeipzigHamburg;
    Flight HamburgMuenchen;
    Flight MuenchenHamburg;
};

#endif // FLIGHTPLAN_H
