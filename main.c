/*
This module does the work of implementing the login function and validating it and depending on validation it either goes to choice, admin or gives error.

TO LEARN MORE ABOUT THIS MODULE KINDLY REFER TO THE DOCUMENTATION.
*/

#include <stdio.h>
#include <stdlib.h>
#include "loginfunction.h"
#include "designfunction.h"
#include "choicefunction.h"

int main(){
    start_screen(); //function in design.c
    creator_details(); //function in design.c

    int login_validation = 0;       //Take the return value form
    login_validation = login();     // the login function in login.c (validate_login function in login.c returns value not the login function)

    if(login_validation == 1){
        user_welcome();
        choice();
    }else if(login_validation == 2){
        admin_welcome();
        admin();
    }else{
        system("cls || clear");
        printf("\n\t\tERROR CODE : 403 - FORBIDDEN\n\t\tA 403 status code indicates that the client cannot access the requested resource.\n\t\tThat might mean that the wrong username and password were sent in the request,\n\t\tor that the permissions on the server do not allow what was being asked.\n");
    }
    return 0;
}
