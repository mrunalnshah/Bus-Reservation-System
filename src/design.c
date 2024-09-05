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
    printf("*       \"https://www.linkedin.com/in/mrunalnshah/\"      *\n");
    printTab(2);
    printf("*       \"https://github.com/mrunalnshah\"                *\n");
    printTab(2);
    printf("*       \"Email : \"mrunalnshah7@gmail.com\"\"              *\n");
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
void registrationScreen() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                                  Registration                               \n");
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
}

void busInformationScreen() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                            Bus Information                                  \n");
    printTab(2);
    printf("*****************************************************************************\n");
}
void busBookingScreen() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                                Bus Booking                                  \n");
    printTab(2);
    printf("*****************************************************************************\n");
}
void busCancellationScreen() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                                Bus Cancellation                             \n");
    printTab(2);
    printf("*****************************************************************************\n");
}
void busRegisterScreen() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                                Bus Journey Registration                     \n");
    printTab(2);
    printf("*****************************************************************************\n");
}
void busCancelScreen() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                                Bus Journey Cancellation                     \n");
    printTab(2);
    printf("*****************************************************************************\n");
}
void seatArrangementDesign() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                            Seat Arrangement                                 \n");
    printTab(2);
    printf("*****************************************************************************\n");
}
void userTypeDesign() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                                User Type ?                                  \n");
    printTab(2);
    printf("*****************************************************************************\n");
}
void errorMessageDesign() {
    clearScreen();
    printTab(2);
    printf("*****************************************************************************\n");
    printTab(2);
    printf("                            Error Message Information                        \n");
    printTab(2);
    printf("*****************************************************************************\n");
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