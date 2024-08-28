#include "design.h"
#include "clearScreen.h"
#include "key.h"

void firstScreenDesign() {
    printTab(2);
    printf("*********************************************************************\n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                         WELCOME TO THE                              \n");
    printTab(2);
    printf("                          MRUNAL's BUS SYSTEM                        \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("*********************************************************************\n\n\n");
    printTab(2);
    printf("Press any key to continue...");
    pressAnyKey();
    clearScreen();
    printf("\n");
}

void lastScreenDesign() {
    printTab(2);
    printf("*********************************************************************\n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                         Thank You For Using                         \n");
    printTab(2);
    printf("                          MRUNAL's BUS SYSTEM                        \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("                                                                     \n");
    printTab(2);
    printf("*********************************************************************\n\n\n");
    printTab(2);
    printf("Press any key to continue...");
    pressAnyKey();
    clearScreen();
    printf("\n");
}
void creator_details() {
    clearScreen();
    printTab(2);
    printf("*********************************************************\n");
    printTab(2);
    printf("*              MADE BY MRUNAL NIRAJKUMAR SHAH           *\n");
    printTab(2);
    printf("*       \"https://www.linkedin.com/in/mrunalnshah/\"    *\n");
    printTab(2);
    printf("*       \"https://github.com/mrunalnshah\"              *\n");
    printTab(2);
    printf("*       \"Email : \"mrunalnshah7@gmail.com\"\"          *\n");
    printTab(2);
    printf("*********************************************************\n");
    printTab(2);
    printf("If you see any bugs or any need of improvement \n\t\tI would be happy to implement it as soon as possible \n\t\tor if you want to learn something about/in the code,\n\t\tcontact me on above links!!!\n");
    printTab(2);
    printf("PRAISE BE!!!\n\t\tMRUNAL NIRAJKUMAR SHAH\n");
    printTab(2);
    printf("Enter any key to continue...");
    pressAnyKey();
}

void returnpage() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                    MRUNAL BUS MANAGEMENT SYSTEM                             \n");
    printTab(2);
    printf("*****************************************************************************\n");
}

void loginScreen() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                                   Login                                     \n");
    printTab(2);
    printf("*****************************************************************************\n");
}

void userWelcome() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                            WELCOME USER                                     \n");
    printTab(2);
    printf("*****************************************************************************\n");
}
void adminWelcome() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                            WELCOME ADMINISTRATOR                            \n");
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("Enter any key to continue...");
    pressAnyKey();
}

void printTab(int count) {
    for (int i = 0; i < count; i++) {
        printf("\t");
    }
}

void printNewLine(int count) {
    for (int i = 0; i < count; i++) {
        printf("\n");
    }
}