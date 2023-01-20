/*
This module fetch the data from the respected filename based on busnumber if available else it ask user to input number of seats to be booked and
ask if the seat is occupied or not if yes than the user is asked again else the system ask to input name and then store all that in an array.

after the number of seats are booked the loop runs to print all the data in the file while formatting the previous data.

TO LEARN MORE ABOUT THIS MODULE KINDLY REFER TO DOCUMENTATION
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "busfunction.h"
#include "designfunction.h"


void busbooking();
//refer to the info of the module as its the only function.
void busbooking(){
    struct date{
        int day;
        int month;
        int year;
    };
    typedef struct date DATE;

    struct time{
        int second;
        int minute;
        int hour;
    };
    typedef struct time TIME;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    FILE *busdetails,*seatdetails,*bookingdetails;
    char choice_busnumber[40];

    char register_busnumber[40];
    char register_busname[40];
    char from[50],to[50];
    DATE timing;
    TIME timing_hms;

    char filename_seats[100] = "seat_info_";
    char filename_passenger[100] = "passenger_info_";
    char database_seat[100] = "database/";
    char database_passenger[100] = "database/";

    int totalseats = 20;
    int number_of_seats;

    char temp_passenger_name[40];
    int temp_passenger_seat;

    char array_passenger_name[20][40] = {NULL};
    int array_passenger_seat[20] = {NULL};

    int temp_seat;
    int validation = 0;
    int istimetrue = 0;
    int checkpoint = 0;
    char choice_retrieve_buslist;
    int isdatetrue = 0;

    char temp_name[40];


    printf("\t\t*****************************************************************************\n");
    printf("\t\t                            BUS BOOKING                                      \n");
    printf("\t\t*****************************************************************************\n\n\n");


    busdetails = fopen("database/busdetails.txt","r");

    if(busdetails != NULL){
        printf("\t\tDo you wish to retrieve Bus availability Schedule ? Y/N   :   ");
        scanf("%s",&choice_retrieve_buslist);

        if(choice_retrieve_buslist == 'y' || choice_retrieve_buslist == 'Y'){
            busavailability();
        }
        printf("\n\t\tEnter Bus Number : ");
        scanf("%s",choice_busnumber);
        while(fscanf(busdetails,"%s %s %s %s %d %d %d %d %d %d",register_busnumber,register_busname,from,to,&timing.day,&timing.month,&timing.year,&timing_hms.hour,&timing_hms.minute,&timing_hms.second) == 10){
            if(strcmp(register_busnumber,choice_busnumber) == 0){
                isdatetrue = date_validation(timing.day,timing.month,timing.year);
                if(isdatetrue == 1){
                    bus_layout(register_busnumber);
                    strcat(filename_seats,choice_busnumber);
                    strcat(filename_seats,".txt");
                    strcat(database_seat,filename_seats);
                    strcat(filename_passenger,choice_busnumber);
                    strcat(filename_passenger,".txt");
                    strcat(database_passenger,filename_passenger);

                    seatdetails = fopen(database_seat,"r");
                    if(seatdetails != NULL){
                        fscanf(seatdetails,"%d",&totalseats);
                    }
                    fclose(seatdetails);

                    bookingdetails = fopen(database_passenger,"r");
                    if(bookingdetails != NULL){
                        while(fscanf(bookingdetails,"%d %s",&temp_passenger_seat,temp_passenger_name) == 2){
                            array_passenger_seat[temp_passenger_seat] = temp_passenger_seat;
                            strcpy(array_passenger_name[temp_passenger_seat],temp_passenger_name);
                        }
                    }
                    printf("\t\tEnter Number of seats to be booked : ");
                    scanf("%d",&number_of_seats);


                    for(int i = 0; i < number_of_seats; i++){
                        printf("\t\tPassenger [%d]\n",i+1);
                        do{
                            validation = 0;
                            printf("\t\tSEAT : ");
                            scanf("%d",&temp_seat);
                            for(int i = 0; i < 20; i++){
                                if(temp_seat == array_passenger_seat[i]){
                                    printf("\t\tWe regret but the seat is not EMPTY/VACANT...\n");
                                    validation = 1;
                                }
                            }
                        }while(validation == 1);

                        printf("\t\tNAME : ");
                        scanf("%s",temp_name);


                        array_passenger_seat[temp_seat] = temp_seat;
                        strcpy(array_passenger_name[temp_seat],temp_name);
                        totalseats = totalseats - 1;
                    }
                    bookingdetails = fopen(database_passenger,"w");
                    for(int i = 0; i < 20;i++){
                        if(array_passenger_seat[i] != NULL && array_passenger_name[i] != NULL){
                            fprintf(bookingdetails,"%d %s\n",array_passenger_seat[i],array_passenger_name[i]);
                        }
                    }
                    fclose(bookingdetails);
                    seatdetails = fopen(database_seat,"w");
                    fprintf(seatdetails,"%d",totalseats);
                    fclose(seatdetails);

                    checkpoint = 1;
                    system("cls || clear");
                    bus_layout(choice_busnumber);
                    printf("\n\n\t\t***********************************************************************\n");
                    printf("\t\t                 TOTAL COST FOR THE %2d TICKETS is %5d                     \n",number_of_seats,number_of_seats*1000);
                    printf("\t\t***********************************************************************\n");
            }else{
                printf("\t\tSorry but the Date has passed for booking and the bus after reaching its destination will be cleared from the list...\n");
            }
        }
    }
    if(checkpoint != 1){
        printf("\t\tBUS NOT FOUND WITH THAT BUS NUMBER...(Press any Key)\n");
        getch();
    }
    }else{
        printf("\t\tCurrently there are no buses registered.\n");
        printf("\t\tEnter to continue...");
        getch();
    }
}
