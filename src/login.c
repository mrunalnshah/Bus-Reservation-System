#include "login.h"
#include "interface.h"
#include "clearScreen.h"


int login(char username[], char password[], char type) {
	if (type == 'a') {
		if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
			return 0;
		}
	}

	char bufferUsername[BUFFER_SIZE];
	char bufferPassword[BUFFER_SIZE];

	FILE* fptr;

	fptr = fopen("database/userInformation/user.txt", "r");
	if (fptr == NULL) {
		return -5;
	}

	while (fscanf(fptr, "%s %s", bufferUsername, bufferPassword) == 2) {
		if (strcmp(username, bufferUsername) != 0) {
			continue;
		}
		if (strcmp(password, bufferPassword) == 0) {
			return 0;
		}
		return -1;
	}

	return -2;
}

char* inputUsername() {
	char buffer[BUFFER_SIZE];
	printTab(2);
	printf("Enter Username : ");
	scanf("%19s", buffer);

	char* username = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	if (username == NULL) {
		perror("Unable to allocate memory for username");
		exit(EXIT_FAILURE);
	}

	strcpy(username, buffer);
	
	return username;
}

char* inputPassword() {
	char buffer[BUFFER_SIZE];
	printTab(2);
	printf("Enter Password : ");
	scanf("%19s", buffer);

	char* password = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	if (password == NULL) {
		perror("Unable to allocate memory for password");
		exit(EXIT_FAILURE);
	}
	strcpy(password, buffer);

	return password;
}

int registerUser() {
	clearScreen();
	registrationScreen();

	char username[BUFFER_SIZE];
	char password1[BUFFER_SIZE];
	char password2[BUFFER_SIZE];

	FILE* fptr;

	int check = 1;
	int usernameExists = 0;

	int threeChance = 0;
	while (check) {
		threeChance++;
		if (threeChance == 3) {
			check = 0;
		}
		printTab(2);
		printf("Enter Username : ");
		scanf("%s", username);
		printTab(2);
		printf("Enter Password : ");
		scanf("%s", password1);
		printTab(2);
		printf("Enter Password Again : ");
		scanf("%s", password2);


		if (strcmp(password1, password2) != 0) {
			printTab(2);
			printf("Passwords do not match. Please try again.\n");
			continue;
		}

		fptr = fopen("database/userInformation/user.txt", "r");
		if (fptr != NULL) {
			char buffer[BUFFER_SIZE];
			while (fscanf(fptr, "%19s %*s", buffer) == 1) {
				if (strcmp(username, buffer) == 0) {
					usernameExists = 1;
					printTab(2);
					printf("Username already exists. Please choose a different username.\n");
					break;
				}
			}
			fclose(fptr);
		}
		if (usernameExists) {
			continue;
		}

		fptr = fopen("database/userInformation/user.txt", "a");
		if (fptr == NULL) {
			return -9;
		}

		fprintf(fptr, "%s %s\n", username, password1);
		fclose(fptr);

		printTab(2);
		printf("Registration successful.\n");
		return 0;
	}
	return -10;
}