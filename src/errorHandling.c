#include "errorHandling.h"
#include "key.h"
#include "design.h"

void errorMessage(int code) {
	if (code == 0) {
		return;
	}
	errorMessageDesign();
	printTab(2);
	if (code == -1) {
		printf("Login Failed.\n");
		exit(-1);
	}
	if (code == -2) {
		printf("Wrong Login Username and Password.\n");
	}
	if (code == -3) {
		printf("We didnt get into user or admin interface in main function.\n");
		exit(-3);
	}
	if (code == -5) {
		printf("File Not Found!\n");
	}
	if (code == -6) {
		printf("Unable to create file.\n");
	}
	if (code == -7) {
		printf("Error Removing Original File.\n");
	}
	if (code == -8) {
		printf("Error Renaming Temp File to Original File");
	}
	if (code == -9) {
		printf("Unable to open file.\n");
	}
	if (code == -10) {
		printf("Registration failed.\n");
		exit(-10);
	}

	if (code == 1) {
		printf("Bus is not registered.\n");
	}
	if (code == 2) {
		printf("Booking Not Available.\n");
	}
	if (code == 3) {
		printf("Multiple try attempted.\n");
	}
	if (code == 4) {
		printf("didnt get y or Y input.\n");
	}
	if (code == 5) {
		printf("Got out of chances.\n");
	}
	if (code == 6) {
		printf("No Seats booked yet.\n");
	}
	if (code == 7) {
		printf("Bus is already registered.\n");
	}
	if (code == 8) {
		printf("wrong input entered.\n");
	}
	pressAnyKey();
}