#include "interface.h"
#include "functionality.h"
#include "design.h"
#include "clearScreen.h"
#include "errorHandling.h"

int errorCode;

char userType() {
	clearScreen();
	userTypeDesign();
	char userType;
	int selectOption;

	printTab(2);
	printf("Login as ...\n");
	printTab(2);
	printf("1. User\n");
	printTab(2);
	printf("2. Admin\n");
	printTab(2);
	printf("3. Register\n");
	printTab(2);
	printf("4+. Exit\n");
	printTab(2);
	printf("Select Option : ");
	scanf("%d", &selectOption);

	switch (selectOption) {
	case 1:
		return 'u';
	case 2:
		return 'a';
	case 3:
		errorCode = registerUser();
		errorMessage(errorCode);
		return 'u';
	default:
		return 'x';
	}
	clearScreen();
	return userType;
}

int adminInterface() {
	clearScreen();
	adminWelcome();
	int selectOption;

	printTab(2);
	printf("Select One of the option");
	printTab(2);
	printf("\n");
	printTab(2);
	printf("1. Bus Information\n");
	printTab(2);
	printf("2. Bus Ticket Booking\n");
	printTab(2);
	printf("3. Bus Ticket Cancel\n");
	printTab(2);
	printf("4. Register new Bus Journey\n");
	printTab(2);
	printf("5. Cancel Bus Journey\n");
	printTab(2);
	printf("6+. LogOut\n");
	printTab(2);
	printf("Enter Your Option : ");
	scanf("%d", &selectOption);

	switch (selectOption) {
	case 1:
		clearScreen();
		errorCode = busInformation();
		break;
	case 2:
		clearScreen();
		errorCode = bookTicket();
		break;
	case 3:
		clearScreen();
		errorCode = cancelTicket();
		break;
	case 4:
		clearScreen();
		errorCode = createBusJourney();
		break;
	case 5:
		clearScreen();
		errorCode = cancelBusJourney();
		break;
	default:
		clearScreen();
		return 0;
	}
	errorMessage(errorCode);
	return 1;
}

int userInterface() {
	clearScreen();
	userWelcome();
	int selectOption;

	printTab(2);
	printf("Select One of the option");
	printTab(2);
	printf("\n");
	printTab(2);
	printf("1. Bus Information\n");
	printTab(2);
	printf("2. Bus Ticket Booking\n");
	printTab(2);
	printf("3. Bus Ticket Cancel\n");
	printTab(2);
	printf("4+. LogOut\n");
	printTab(2);
	printf("Enter Your Option : ");
	scanf("%d", &selectOption);

	switch (selectOption) {
	case 1:
		clearScreen();
		errorCode = busInformation();
		break;
	case 2:
		clearScreen();
		errorCode = bookTicket();
		break;
	case 3:
		clearScreen();
		errorCode = cancelTicket();
		break;
	default:
		clearScreen();
		return 0;
	}
	errorMessage(errorCode);
	return 1;
}

