#ifndef TRAVEL_H
#define TRAVEL_H
#include <booking.h>
#include <vector>
using namespace std;

class Travel{
private:
    //TravelAgency *tA;
    //Customer *cus;
    long id;
    long customerId;
    vector <Booking*> travelBookings;

public:
    Travel();
    void addBooking(Booking* booking);
    long getId() const;
    void setId(long value);
    long getCustomerId() const;
    void setCustomerId(long value);
};

#endif // TRAVEL_H
