#include "Bus-Reservation-System.h"

#include "src/directory.h"
#include "src/login.h"
#include "src/clearScreen.h"
#include "src/design.h"

int main() {
	createDirectory();
	clearScreen();

	firstScreenDesign();
		
	char typeOfUser = userType();

	int check = 1;

	char user[20];

	clearScreen();
	int threeChance = 0;
	while (check) {
		loginScreen();
		char* username = inputUsername();
		char* password = inputPassword();
		check = login(username, password, typeOfUser);
		threeChance++;
		if (threeChance == 3) {
			free(username);
			free(password);
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
			return -2;
		}
	}
	lastScreenDesign();

	return 0;
}
