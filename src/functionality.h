#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Passengers {
	int seatNumber;
	char passengerName[20];
};

struct busInformation {
	int busNumber;
	int totalSeats;
	struct Passengers busPassengers[20];
};

int busInformation();
int bookTicket();
int cancelTicket();
int showAvailableSeats(int busNumber);
int doesBusExist(int busNumber);
int createBusJourney();
int cancelBusJourney();
