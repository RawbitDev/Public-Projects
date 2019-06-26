// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "travel.h"

Travel::Travel(long id, long customerId) : id(id), customerId(customerId)
{
    // Constructor
}

Travel::~Travel()
{
    // Destructor
}

void Travel::addBooking(Booking *booking)
{
    travelBookings.push_back(booking);
}

long Travel::getId() const
{
    return id;
}

size_t Travel::countTravelBookings() const
{
    return travelBookings.size();
}

bool Travel::checkRoundtrip()
{
        if(travelBookings.size()>0) {
            FlightBooking* minFlight = new FlightBooking(LONG_MAX, 0.0, "", "", 0, "", "", "", '0'); // Just two dummy flights for the first compare
            FlightBooking* maxFlight = new FlightBooking(0, 0.0, "", "", 0, "", "", "", '0');

            // Get the min and max booking by their id
            for(unsigned int i=0; i<travelBookings.size(); i++) {
                if (FlightBooking* flight = dynamic_cast<FlightBooking*> (travelBookings.at(i))) { // Check if the booking is a flight
                    if (flight->getId() < minFlight->getId())
                        minFlight = flight;
                    if (flight->getId() > maxFlight->getId())
                         maxFlight = flight;
                }
            }
            return(minFlight->getFromDest()==maxFlight->getToDest()); // Compare the bookings
        }
        return(false);
}

bool Travel::checkNeedlessHotel()
{
    if(travelBookings.size()>0) {
        HotelBooking* lastHotel = new HotelBooking(0, 0.0, "", "", 0, "", "", false); // Just two dummy bookings for the first compares
        Booking* lastCarFlight = new FlightBooking(0, 0.0, "", "", 0, "", "", "", '0');

        // Get the last hotel by its date
        for(unsigned int i=0; i<travelBookings.size(); i++) {
            Booking* currentBooking = travelBookings.at(i);
            if (HotelBooking* hotel = dynamic_cast<HotelBooking*> (currentBooking)) { // Check if the booking is a hotel
                if (hotel->getToDate() > lastHotel->getToDate())
                    lastHotel = hotel;
            } else {
                if (currentBooking->getToDate() > lastCarFlight->getToDate())
                    lastCarFlight = currentBooking;
            }
        }
        return(lastHotel->getToDate() <= lastCarFlight->getToDate()); // Compare the dates
    }
    return(false);
}

bool Travel::checkMissingHotel()
{
    if(travelBookings.size()>0) {
        // This is just the easiest way, so we dont have to search all flights/hotels again and again in the compare down below
        vector <FlightBooking*> allFlights; // All flights beside the last one
        vector <HotelBooking*> allHotels;
        FlightBooking* lastFlight = new FlightBooking(0, 0.0, "", "", 0, "", "", "", '0'); // Just another dummy flight for the first compare

        // Get only the flights and hotels (without the last flight!) in special temp vectors
        for(unsigned int i=0; i<travelBookings.size(); i++) {
            Booking* currentBooking = travelBookings.at(i);
            if (FlightBooking* flight = dynamic_cast<FlightBooking*> (currentBooking)) { // Check if the booking is a flight
                if (flight->getId() > lastFlight->getId()) { // Check if the found flight is the current latest flight
                    if (lastFlight->getId() != 0)
                        allFlights.push_back(lastFlight); // Save the old last flight if its not the dummy
                    lastFlight = flight; // Set the current last flight to the found one
                } else {
                    allFlights.push_back(flight); // If its not later than the current latest flight save it directly
                }
            } else if (HotelBooking* hotel = dynamic_cast<HotelBooking*> (currentBooking)) {
                allHotels.push_back(hotel); // If its a hotel, save it to the hotel vector
            }
        }

        // Check if theres a hotel or flight for every to_date of a flight (beside the last one)
        for(unsigned int i=0; i<allFlights.size(); i++) {
            bool found = false; // Set the found flag to false
            for(unsigned int j=0; j<allHotels.size(); j++) { // Check for hotels
                if(allFlights.at(i)->getToDate() == allHotels.at(j)->getFromDate()) { // Check if theres a hotel for the same date as the to_date of the flight
                    found = true;
                    break;
                }
            }
            if(found == false) // Check if a hotel got found already
                for(unsigned int j=0; j<allFlights.size(); j++) { // Check for flights (without the last one)
                    if((allFlights.at(i)->getId() != allFlights.at(j)->getId()) && (allFlights.at(i)->getToDate() == allFlights.at(j)->getFromDate())) { // Check if theres a flight (thats not the flight itself) for the same date as the to_date of the flight
                        found = true;
                        break;
                    }
                }
            if(found == false) // Check if a hotel or flight got found already
                if(allFlights.at(i)->getToDate() == lastFlight->getFromDate()) // Check if the last flight has the same date as the to_date of the flight
                    found = true;

            if(found == false) // If nothing got found -> return false
                return(false);
        }
        return(true); // If there was a hotel or flight for every to_date of a flight without the last one -> return true
    }
    return(false); // If theres only one booking or less in the travelbooking vector -> return false
}

long Travel::getCustomerId() const
{
    return customerId;
}
