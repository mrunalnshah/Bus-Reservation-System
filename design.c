/*
This module has designs used in different modules.

TO LEARN MORE ABOUT THIS MODULE KINDLY REFER TO DOCUMENTATION
*/

#include <stdio.h>
#include <stdlib.h>

void start_screen();
void end_screen();
void creator_details();
void returnpage();
void user_welcome();
void admin_welcome();
void makedir();

void start_screen(){
    printf("\t\t*********************************************************************\n");
    printf("                                                                     \n");
    printf("                                                                     \n");
    printf("                                                                     \n");
    printf("                                                                     \n");
    printf("                                                                     \n");
    printf("\t\t                         WELCOME TO THE                              \n");
    printf("\t\t                            MRUNAL BUS SYSTEM                        \n");
    printf("                                                                     \n");
    printf("                                                                     \n");
    printf("                                                                     \n");
    printf("                                                                     \n");
    printf("                                                                     \n");
    printf("\t\t*********************************************************************\n\n\n");

    printf("\t\tPress any key to continue...");
    getch();
    printf("\n");
}

void end_screen(){
    system("cls || clear");
    printf("\t\t*********************************************************************\n");
    printf("\t\t                                                                     \n");
    printf("\t\t                                                                     \n");
    printf("\t\t                                                                     \n");
    printf("\t\t                                                                     \n");
    printf("\t\t                                                                     \n");
    printf("\t\t                         THANK YOU FOR USING                         \n");
    printf("\t\t                            MRUNAL BUS SYSTEM                        \n");
    printf("\t\t                                                                     \n");
    printf("\t\t                                                                     \n");
    printf("\t\t                                                                     \n");
    printf("\t\t                                                                     \n");
    printf("\t\t                                                                     \n");
    printf("\t\t*********************************************************************\n\n\n");

    printf("\t\tPress any key to continue...");
    getch();
}

void creator_details(){
    system("cls || clear");
    printf("\n\n\n\t\t*********************************************************\n");
    printf("\t\t*              MADE BY MRUNAL NIRAJKUMAR SHAH           *\n");
    printf("\t\t*       \"https://www.linkedin.com/in/mrunalnshah/\"      *\n");
    printf("\t\t*       \"https://github.com/mrunalnshah\"                *\n");
    printf("\t\t*       \"Email : \"mrunalnshah@protonmail.com\"\"          *\n");
    printf("\t\t*********************************************************\n\n");
    printf("\n\n\t\tIf you see any bugs or any need of improvement \n\t\tI would be happy to implement it as soon as possible \n\t\tor if you want to learn something about/in the code,\n\t\tcontact me on above links!!!\n");

    printf("\n\n\n\t\tPRAISE BE!!!\n\t\tMRUNAL NIRAJKUMAR SHAH\n");

    printf("\n\n\n\t\tEnter any key to continue...");
    getch();
    system("cls || clear");
}

void returnpage(){
    system("cls || clear");
    printf("\t\t*****************************************************************************\n");
    printf("\t\t                    MRUNAL BUS MANAGEMENT SYSTEM                             \n");
    printf("\t\t*****************************************************************************\n");

}
void user_welcome(){
    system("cls || clear");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t*****************************************************************************\n");
    printf("\t\t\t                            WELCOME USER                                     \n");
    printf("\t\t\t*****************************************************************************\n");

}
void admin_welcome(){
    system("cls || clear");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t*****************************************************************************\n");
    printf("\t\t\t                            WELCOME ADMINISTRATOR                            \n");
    printf("\t\t\t*****************************************************************************\n");

    printf("\n\t\tEnter any key to continue...");
    getch();
}

void makedir(){
    int validate = 1;
    validate = system("mkdir database");
    if(validate != 0){
        printf("(FOR ADMIN KNOWLEDGE)\n");
    }
}
