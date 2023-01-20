/*
This module cancel one bus seat at a time as it fetch all the filename.txt data based on busnumber into an array and null the data on seat number, if its already null
than it prints EMPTY already.

TO LEARN MORE ABOUT THIS MODULE KINDLY REFER TO DOCUMENTATION
*/


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "busfunction.h"
#include "designfunction.h"


void buscancellation();

/*
it fetch the data of passengers and seat from the filename based on the respective busnumber and stores them in array. ask the user to cancel one seat if occupied
and store them into array if not occupied then prints EMPTY Already and no changes to the array. at last it runs a loop to overwrite and
print all the data from array to filename based on busnumber.
*/
void buscancellation(){
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
    char busnumber_read[10];
    char busname_read[40];
    char busfrom_read[40];
    char busto_read[40];
    DATE timing;
    TIME timing_hms;

    char filename_seats[100] = "seat_info_";
    char filename_passenger[100] = "passenger_info_";
    char database_seat[100] = "database/";
    char database_passenger[100] = "database/";

    char choice_busnumber[40];
    int totalseats = 20;
    int seat_cancel;

    int refund_amount = 0;

    int array_seatnumbers[20] = {NULL};
    char array_seatnames[20][40] = {NULL};

    int temp_seatnumber;
    char temp_seatname[40];

    int date_verify = 0;
    int time_verify = 0;
    int checkpoint = 0;
    char choice_retrieve_buslist;


    printf("\t\t*****************************************************************************\n");
    printf("\t\t                              BUS CANCELLATION                               \n");
    printf("\t\t*****************************************************************************\n");
    busdetails = fopen("database/busdetails.txt","r");

    if(busdetails != NULL){
        printf("\t\tDo you wish to retrieve Bus Availability Schedule ? Y/N : ");
        scanf("%s",&choice_retrieve_buslist);

        if(choice_retrieve_buslist == 'y' || choice_retrieve_buslist == 'Y'){
            busavailability();
        }
        printf("\t\tEnter Bus Number : ");
        scanf("%s",choice_busnumber);

        while(fscanf(busdetails,"%s %s %s %s %d %d %d %d %d %d",busnumber_read,busname_read,busfrom_read,busto_read,&timing.day,&timing.month,&timing.year,&timing_hms.hour,&timing_hms.minute,&timing_hms.second) == 10){
            if(strcmp(choice_busnumber,busnumber_read) == 0){
                date_verify = date_validation(timing.day,timing.month,timing.year);
                if(date_verify == 1){
                    time_verify = time_validation(timing_hms.hour,timing_hms.minute,timing_hms.second);
                    if(time_verify == 1){
                        bus_layout(choice_busnumber);
                        strcat(filename_seats,busnumber_read);
                        strcat(filename_seats,".txt");
                        strcat(database_seat,filename_seats);
                        strcat(filename_passenger,busnumber_read);
                        strcat(filename_passenger,".txt");
                        strcat(database_passenger,filename_passenger);

                        seatdetails = fopen(database_seat,"r");
                        if(seatdetails != NULL){
                            fscanf(seatdetails,"%d",&totalseats);
                        }
                        fclose(seatdetails);
                        bookingdetails = fopen(database_passenger,"r");
                        if(bookingdetails != NULL){
                            while(fscanf(bookingdetails,"%d %s",&temp_seatnumber,temp_seatname) == 2){
                                array_seatnumbers[temp_seatnumber] = temp_seatnumber;
                                strcpy(array_seatnames[temp_seatnumber],temp_seatname);
                            }
                        }

                        printf("\t\tEnter the Seat number you want to cancel : ");
                        scanf("%d",&seat_cancel);

                        if(array_seatnumbers[seat_cancel] != NULL){
                            array_seatnumbers[seat_cancel] = NULL;
                            strcpy(array_seatnames[seat_cancel],"");
                            totalseats = totalseats + 1;
                            refund_amount = refund_amount + 1000;
                        }else{
                            printf("\t\tThe seat is already EMPTY/VACANT. \n");
                        }
                        bookingdetails = fopen(database_passenger,"w");
                        for(int i = 0; i < 20;i++){
                            if(array_seatnumbers[i] != NULL){
                                fprintf(bookingdetails,"%d %s\n",array_seatnumbers[i],array_seatnames[i]);
                            }
                        }
                        fclose(bookingdetails);

                        seatdetails = fopen(database_seat,"w");
                        fprintf(seatdetails,"%d",totalseats);
                        fclose(seatdetails);

                        checkpoint = 1;

                        system("cls || clear");
                        bus_layout(choice_busnumber);
                        printf("\t\t***************************************************\n");
                        printf("\t\t            REFUND OF AMOUNT %5d IS INITIATED      \n ",refund_amount);
                        printf("\t\t***************************************************\n");
                        printf("\n\t\tPress any key to continue...\n");
                        getch();
                    }else{
                        printf("Time has passed...\n");
                        checkpoint = 1;
                    }
                }else{
                    printf("Date has passed...\n");
                    checkpoint = 1;
                }
            }
        }
        if(checkpoint != 1){
            printf("\t\tBUS NOT FOUND WITH THAT BUS NUMBER...(Press any key)");
            getch();
            printf("\n");
        }
    }else{
        printf("\t\tSorry but currently no buses are registered yet...(Press any key)");
        getch();
        printf("\n");
    }
}
