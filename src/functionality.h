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

void busInformation();
void bookTicket();
void cancelTicket();
void showAvailableSeats(int busNumber);
int doesBusExist(int busNumber);
void createBusJourney();
void cancelBusJourney();
void notify();