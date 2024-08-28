#include "functionality.h"
#include "time.h"
#include "key.h"

void busInformation() {
	int busNumber;
	char busName[20];
	char departure[20];
	char destination[20];
	int year, month, day;
	int hour, minute, second;
	
	FILE* fptr;

	char selectOption;

	fptr = fopen("database/busInformation/busInfo.txt", "r");
		while (fscanf(fptr, "%d %s %s %s %d %d %d %d %d %d", &busNumber, busName, departure, destination, &year, &month, &day, &hour, &minute, &second) == 10) {
			printTab(2);
			printf("BUS NUMBER  : %d\n", busNumber);
			printTab(2);
			printf("BUS NAME    : %-20s\n", busName);
			printTab(2);
			printf("Departure   : %-20s\n", departure);
			printTab(2);
			printf("Destination : %-20s\n", destination);
			printTab(2);
			printf("Time  : %d %d %d\n", hour, minute, second);
			printTab(2);
			printf("Date  : %d %d %d\n", year, month, day);
			printNewLine(2);
		}

		printTab(2);
		printf("Want to continue, looking at Seat Arrangement (Y/n) ?  : ");
		scanf(" %c", &selectOption);

		if (selectOption != 'y' && selectOption != 'Y') {
			return;
		}
		printTab(2);
		printf("Enter Bus Number to see information : ");
		scanf("%d", &busNumber);

		showAvailableSeats(busNumber);

		printTab(2);
		printf("Enter any key...\n");
		pressAnyKey();
}

void bookTicket() {
	struct Passengers thisBus[20];
	int totalSeatNotOccupied = 20;

	int seatsToBook;

	FILE* fptr;

	char filename[50] = "database/busInformation/";
	char busNumberString[20];
	
	int buffer1;
	char buffer2[20];

	int seatNumber;
	char passengerName[20];
	
	int busNumber;

	printTab(2);
	printf("Enter Bus Number : ");
	scanf("%d", &busNumber);

	if (!doesBusExist(busNumber)) {
		printTab(2);
		printf("Bus is not registered.\n");
		return;
	}

	if (cancellationAvailable(busNumber) != 1) {
		printTab(2);
		printf("Booking Not Available.\n");
		return;
	}


	itoa(busNumber, busNumberString, 10);
	strcat(filename, busNumberString);
	strcat(filename, ".txt");

	for (int i = 0; i < 20; i++) {
		thisBus[i].seatNumber = i + 1;
		strcpy(thisBus[i].passengerName, "$$$");
	}

	fptr = fopen(filename, "r");
	if (fptr != NULL) {
		while (fscanf(fptr, "%d %s", &buffer1, buffer2) == 2) {
			if (strcmp(buffer2, "$$$") != 0) {
				strcpy(thisBus[buffer1 - 1].passengerName, buffer2);
				totalSeatNotOccupied--;
			}
		}
		fclose(fptr);
	}

	int printErrorMessage = 0;
	char selectOption;
	do {
		if (printErrorMessage == 3) {
			printf("Error.");
			return;
		}
		if (printErrorMessage) {
			printTab(2);
			printf("We dont have enough seats.");
			printTab(2);
			printf("Enter y to continue booking : ");
			scanf("%c", &selectOption);
			if (selectOption != 'y' || selectOption != 'Y') {
				return;
			}
		}
		printTab(2);
		printf("Enter Number of Seats to book : ");
		scanf("%d", &seatsToBook);
		printErrorMessage++;
	} while (seatsToBook >= totalSeatNotOccupied);

	for (int i = 0; i < seatsToBook; i++) {
		int isTrue = 0;
		int threeChance = 0;
		do {
			if (threeChance == 3) {
				return;
			}
			printTab(2);
			printf("Enter Seat Number : ");
			scanf("%d", &seatNumber);
			threeChance++;

			if (strcmp(thisBus[seatNumber - 1].passengerName, "$$$") != 0) {
				isTrue = 1;
				printTab(2);
				printf("Seat is occupied.\n");
			}
		} while (isTrue);
		printTab(2);
		printf("Enter Name to Register : ");
		scanf("%s", passengerName);

		strcpy(thisBus[seatNumber - 1].passengerName, passengerName);
	}

	fptr = fopen(filename, "w");
	if (fptr == NULL) {
		perror("unable to create file.\n");
		return;
	}

	for (int i = 0; i < 20; i++) {
		fprintf(fptr, "%d %s\n", thisBus[i].seatNumber, thisBus[i].passengerName);
	}
	fclose(fptr);

	printTab(2);
	printf("Tickets booked successfully.\n");
}

void cancelTicket() {
	int busNumber;

	FILE* fptr;

	int buffer1;
	char buffer2[20];

	int seatNumber;

	printTab(2);
	printf("Enter Bus Number : ");
	scanf("%d", &busNumber);

	if (!doesBusExist(busNumber)) {
		printTab(2);
		printf("Bus Doesn't Exist.\n");
		return;
	}

	if (cancellationAvailable(busNumber) != 1) {
		printTab(2);
		printf("Cancellation Not Available.\n");
		return;
	}

	struct Passengers thisBus[20];

	char filename[50] = "database/busInformation/";
	char busNumberString[20];
	itoa(busNumber, busNumberString, 10);
	strcat(filename, busNumberString);
	strcat(filename, ".txt");


	for (int i = 0; i < 20; i++) {
		thisBus[i].seatNumber = i + 1;
		strcpy(thisBus[i].passengerName, "$$$");
	}

	fptr = fopen(filename, "r");
	if (fptr == NULL) {
		printTab(2);
		printf("No Seats booked yet.\n");
		return;
	}

	while (fscanf(fptr, "%d %s", &buffer1, buffer2) == 2) {
		strcpy(thisBus[buffer1 - 1].passengerName, buffer2);
	}
	fclose(fptr);

	printTab(2);
	printf("Enter a Seat Number to cancel : ");
	scanf("%d", &seatNumber);

	strcpy(thisBus[seatNumber - 1].passengerName, "$$$");
	
	fptr = fopen(filename, "w");
	for (int i = 0; i < 20; i++) {
		fprintf(fptr, "%d %s\n", thisBus[i].seatNumber, thisBus[i].passengerName);
	}
	fclose(fptr);

	printTab(2);
	printf("Seat Number successfully cancelled.\n");

}

void showAvailableSeats(int busNumber) {
	FILE* fptr;
	
	int busExist = doesBusExist(busNumber);

	int buffer1;
	char buffer2[20];

	int totalSeat = 20;
	struct Passengers thisBus[20];

	for (int i = 0; i < 20; i++) {
		thisBus[i].seatNumber = i + 1;
		strcpy(thisBus[i].passengerName, "$$$");
	}

	if (!busExist) {
		printTab(2);
		printf("Bus Doesnt Exist.\n");
	}
	else {
		char busNumberString[10];
		itoa(busNumber, busNumberString, 10);
		char filename[50] = "database/busInformation/";
		strcat(filename, busNumberString);
		strcat(filename, ".txt");
		fptr = fopen(filename, "r");
		if (fptr != NULL) {
			while (fscanf(fptr, "%d %s", &buffer1, buffer2) == 2) {
				if (strcmp(buffer2, "$$$") != 0) {
					strcpy(thisBus[buffer1 - 1].passengerName, buffer2);
					totalSeat--;
				}
			}
			fclose(fptr);
		}
		printNewLine(2);
		printTab(2);
		printf("BUS NUMBER : %2d\n", busNumber);
		printTab(2);
		printf("Total Seats --> %2d\n\n", totalSeat);
		for (int i = 0; i < 20; i++) {
			printTab(2);
			printf("[%d]  %-19s\n", i+1, thisBus[i].passengerName);
		}
	}
}

int doesBusExist(int busNumber) {
	FILE* fptr;

	int busExist = 0;

	int buffer;
	fptr = fopen("database/busInformation/busInfo.txt", "r");
	if (fptr != NULL) {
		while (fscanf(fptr, "%d %*s %*s %*s %*d %*d %*d %*d %*d %*d %*d", &buffer) == 1) {
			if (buffer == busNumber) {
				busExist = 1;
			}
		}
		fclose(fptr);
	}

	return busExist;
}

int cancellationAvailable(int busNumber) {
	struct Time givenTime;
	
	FILE* fptr;

	int busExist = 0;
	int cancelAvail = 0;

	int buffer;
	int buffer1, buffer2, buffer3, buffer4, buffer5, buffer6;
	fptr = fopen("database/busInformation/busInfo.txt", "r");
	if (fptr != NULL) {
		while (fscanf(fptr, "%d %*s %*s %*s %d %d %d %d %d %d %d", &buffer, &buffer1, &buffer2, &buffer3, &buffer4, &buffer5, &buffer6) == 7) {
			if (buffer == busNumber) {
				givenTime.year = buffer1;
				givenTime.month = buffer2;
				givenTime.day = buffer3;
				givenTime.hour = buffer4;
				givenTime.minute = buffer5;
				givenTime.second = buffer6;
			
				cancelAvail = timeValidation(givenTime);
			}
		}
		fclose(fptr);
	}
	return cancelAvail;
}

void createBusJourney() {
	int busNumber;
	char busName[20];
	char departure[20];
	char destination[20];
	int year, month, day;
	int hour, minute, second;

	struct Time givenTime;

	FILE* fptr;

	printTab(2);
	printf("Enter Bus Number : ");
	scanf("%d", &busNumber);
	printTab(2);
	printf("Enter Bus Name : ");
	scanf("%s", busName);
	printTab(2);
	printf("Enter Departure Station : ");
	scanf("%s", departure);
	printTab(2);
	printf("Enter Destination Station : ");
	scanf("%s", destination);

	int printErrorMessage = 0;
	do{
		if (printErrorMessage == 3) {
			exit(EXIT_FAILURE);
		}
		if (printErrorMessage) {
			printf("Error\n");
		}

		printTab(2);
		printf("Enter Year of Journey : ");
		scanf("%d", &year);
		printTab(2);
		printf("Enter Month of Journey : ");
		scanf("%d", &month);
		printTab(2);
		printf("Enter Day of Journey : ");
		scanf("%d", &day);
		printTab(2);
		printf("Enter Hour of Journey : ");
		scanf("%d", &hour);
		printTab(2);
		printf("Enter Minute of Journey : ");
		scanf("%d", &minute);
		printTab(2);
		printf("Enter second of Journey : ");
		scanf("%d", &second);
		
		givenTime.year = year;
		givenTime.month = month;
		givenTime.day = day;
		givenTime.hour = hour;
		givenTime.minute = minute;
		givenTime.second = second;

		printErrorMessage++;
	} while (timeValidation(givenTime) != 1);

	fptr = fopen("database/busInformation/busInfo.txt", "r");
	
	int buffer;

	int busNumberExist = 0;
	if (fptr != NULL) {
		while (fscanf(fptr, "%d %*s %*s %*s %*d %*d %*d %*d %*d %*d", &buffer) == 1) {
			if (buffer == busNumber) {
				busNumberExist = 1;
			}
		}
		fclose(fptr);
	}

	if (busNumberExist) {
		printTab(2);
		printf("Bus is already registered for a journey.\n");
	}
	else {
		fptr = fopen("database/busInformation/busInfo.txt", "a");
		fprintf(fptr, "%d %s %s %s %d %d %d %d %d %d\n", busNumber, busName, departure, destination, year, month, day, hour, minute, second);
		fclose(fptr);
		printTab(2);
		printf("Bus registered successful.\n");
	}
}

void cancelBusJourney() {
	int busNumberToRemove;
	int busNumberExist = 0;

	FILE* fptr, * tempFptr;
	int busNumber;

	int buffer1;
	char buffer2[20], buffer3[20], buffer4[20];
	int buffer5, buffer6, buffer7, buffer8, buffer9, buffer10;

	printTab(2);
	printf("Enter Bus Number to cancel the journey : ");
	scanf("%d", &busNumberToRemove);

	fptr = fopen("database/busInformation/busInfo.txt", "r");
	if (fptr != NULL) {
		while (fscanf(fptr, "%d %*s %*s %*s %*d %*d %*d %*d %*d %*d", &busNumber) == 1) {
			if (busNumber == busNumberToRemove) {
				busNumberExist = 1;
			}
		}
		fclose(fptr);
	}

	if (busNumberExist) {
		fptr = fopen("database/busInformation/busInfo.txt", "r");
		if (fptr == NULL) {
			perror("Unable to open the file.\n");
		}

		tempFptr = fopen("database/busInformation/tempBusInfo.txt", "w");
		if (tempFptr == NULL) {
			perror("Unable to create the file.\n");
		}

		while (fscanf(fptr, "%d %s %s %s %d %d %d %d %d %d", &buffer1, buffer2, buffer3, buffer4, &buffer5, &buffer6, &buffer7, &buffer8, &buffer9, &buffer10) == 10) {
			if (buffer1 != busNumberToRemove) {
				fprintf(tempFptr, "%d %s %s %s %d %d %d %d %d %d\n", buffer1, buffer2, buffer3, buffer4, buffer5, buffer6, buffer7, buffer8, buffer9, buffer10);
			}
		}
		fclose(fptr);
		fclose(tempFptr);

		if (remove("database/busInformation/busInfo.txt") != 0) {
			perror("Error Removing Original File\n");
		}
		if (rename("database/busInformation/tempBusInfo.txt", "database/busInformation/busInfo.txt") != 0) {
			perror("Error Renaming Temp File to Original File\n");
		}
		printf("Bus Journey Cancelled Successfully\n");
	}
	else {
		printTab(2);
		printf("%d Bus is not registered for any journey\n", busNumberToRemove);
	}
}

void notify() {
}