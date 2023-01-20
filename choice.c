/*
This module ask user to input a digit and based on digit the switch cases are implemented.

TO LEARN MORE ABOUT THIS MODULE KINDLY REFER TO DOCUMENTATION
*/

//pre-processing directory
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "busfunction.h"
#include "designfunction.h"
#include "choicefunction.h"
//pre-processing directory

void choice();

void choice(){
    system("cls || clear");
    returnpage();
    int yourchoice;

    printf("\t\t[1] BUS AVAILABILITY\n");
    printf("\t\t[2] BUS BOOKING\n");
    printf("\t\t[3] BUS CANCELLATION\n");
    printf("\t\t[4] BUS STATUS\n");
    printf("\t\t[5] EXIT\n");

    printf("\n\t\tEnter your choice :  ");
    scanf("%d",&yourchoice);

    switch(yourchoice){
    case 1:
        {
            system("cls || clear");
            busavailability();
            printf("\t\tPress any key to continue...");
            getch();
            choice();
            break;
        }
    case 2:
        {
            system("cls || clear");
            busbooking();
            choice();
            break;
        }
    case 3:
        {
            system("cls || clear");
            buscancellation();
            choice();
            break;
        }
    case 4:
        {
            system("cls || clear");
            busstatus();
            printf("\t\tPress any key to continue...");
            getch();
            printf("\n");
            choice();
            break;
        }
    case 5:
        {
            end_screen();
            creator_details();
            break;
        }
    default:
        {
            printf("You inputed away from the menu, we took it as EXIT so...(Press any Key)");
            getch();
            printf("\n");
            end_screen();
            creator_details();
            break;
        }
    }
}
