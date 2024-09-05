#include "Bus-Reservation-System.h"

#include "src/directory.h"
#include "src/login.h"
#include "src/clearScreen.h"
#include "src/design.h"

int errorCode;

int main() {
	createDirectory();
	clearScreen();

	firstScreenDesign();
	creator_details();
	char typeOfUser = userType();
	if (typeOfUser == 'x') {
		return 8;
	}
	int check = 1;

	char user[20];

	clearScreen();
	int threeChance = 0;
	while (check) {
		loginScreen();
		char* username = inputUsername();
		char* password = inputPassword();
		errorCode = login(username, password, typeOfUser);
		if (errorCode == 0) {
			check = 0;
		}
		errorMessage(errorCode);
		threeChance++;
		if (threeChance == 3) {
			free(username);
			free(password);
			errorMessage(-1);
			return -1;
		}
		strcpy(user, username);
		free(username);
		free(password);
	}
	clearScreen();

	check = 1;
	while (check) {
		if (typeOfUser == 'a') {
			check = adminInterface();
		}
		else if (typeOfUser == 'u') {
			check = userInterface();
		}
		else {
			return -3;
		}
	}
	lastScreenDesign();
	return 0;
}
