/*
This module does take the input from the user/admin and validate the input with the database and returns the value as 1(user),2(admin),0(invalid input)

TO LEARN MORE ABOUT THIS MODULE KINDLY REFER TO DOCUMENTATION
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ENTER 13        //ASCII VALUE FOR ENTER KEY IS 13
#define TAB 9           //ASCII VALUE FOR TAB KEY IS 9
#define BACKSPACE 8     //ASCII VALUE FOR BACKSPACE KEY IS 8
#define SPACE 32        //ASCII VALUE FOR SPACE KEY IS 32

int login();
void input_login();
int validate_login();

char enter_username[20]; //for inputs
char enter_password[30]; //for inputs

char admin_username[] = "admin";
char admin_password[] = "admin";

int login(){
    FILE *userdetails;

    int check_loop = 0; //to check that user/admin can enter password for a certain time and after that loop ends and return the value
    int validation = 0; //takes the value returned by the validate_login function

    userdetails = fopen("database/userdetails.txt","r");

    system("cls || clear");
    printf("\t\t*****************************************************************************\n");
    printf("\t\t                                LOGIN                                        \n");
    printf("\t\t*****************************************************************************\n\n\n");

    if(userdetails == NULL){
        printf("\n\t\tNo user is currently registered with the system. Only ADMIN can register.\n");
    }
    do{
        input_login(); //calls funtion
        validation = validate_login(); //validate the input_login function and returns a value either 0(invalid input),1(user),2(admin) and stores in validation
        check_loop++;
        if(validation == 0 && check_loop < 4){
            printf("\n\n\t\tEnter Valid Username & Password...\n\n");
        }else{
            break;
        }
    }while(validation == 0);

    return validation;
}

//input_login function takes input of username and password.
void input_login(){
    char temp_input;
    int initial = 0;
    printf("\t\t********************************************************************************\n");
    printf("\t\tEnter Username : ");
    scanf("%s",enter_username);

    printf("\n\t\tEnter Password  :  ");
    while(1){
        temp_input = getch();
        if(temp_input == ENTER){
            enter_password[initial] = '\0';
            break;
        }else if(temp_input == BACKSPACE){
            if(initial > 0){
                initial--;
                printf("\b \b");
            }
        }else if(temp_input == TAB || temp_input == SPACE){
            continue;
        }else{
            enter_password[initial] = temp_input;
            initial++;
            printf("*");
        }
    }
    printf("\n\t\t********************************************************************************\n");
}

//the username and password taken from input_login is validated in validate_login with database(admin can create new usernames/passwords and that are stored in userdetails.txt)
int validate_login(){
    FILE *userdetails;
    char temp_username[20], temp_password[30];

    userdetails = fopen("database/userdetails.txt","r");
    if(userdetails == NULL){
        if((strcmp(enter_username,admin_username) == 0) && (strcmp(enter_password,admin_password) == 0)){
            return 2;
        }else{
            return 0;
        }
    }else{
        if((strcmp(enter_username,admin_username) == 0) && (strcmp(enter_password,admin_password) == 0)){
            return 2;
        }
        while(fscanf(userdetails,"%s %s",temp_username,temp_password) == 2){
            if((strcmp(enter_username,temp_username)) == 0 && (strcmp(enter_password,temp_password) == 0)){
                return 1;
            }
        }
        return 0;
    }
}
