/*
This module fetch all data from the filename based on busnumber and prints the seat number and names occupied and give the status of the bus schedule for a particular bus.

TO LEARN MORE ABOUT THIS MODULE KINDLY REFER TO DOCUMENTATION
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "busfunction.h"
#include "designfunction.h"


void busstatus();
void bus_layout(char busnumber[]);

//it checks it filename for the respective busnumber if available if yes than it calls the bus_layout function
void busstatus(){
    FILE *busdetails;

    char status_busnumber[20];
    int size;
    char choice_busavailability;

    printf("\t\t*****************************************************************************\n");
    printf("\t\t                                BUS STATUS                                   \n");
    printf("\t\t*****************************************************************************\n");

    busdetails = fopen("database/busdetails.txt","r");
    if(busdetails != NULL){
        printf("\t\tDo you wish to retrieve bus availability Schedule ? Y/N : ");
        scanf("%s",&choice_busavailability);
        if(choice_busavailability == 'y' || choice_busavailability == 'Y'){
            busavailability();
        }
        printf("\t\tEnter Bus number for status : ");
        scanf("%s",status_busnumber);
        bus_layout(status_busnumber);
    }else{
        printf("\t\tNO BUS HAS BEEN REGISTERED YET...\n");
    }
}

//it takes the input of busnumber and prints all the fetched data for the bus. if there is no file created for it then it prints EMPTY for all seats and totalseats = 20
void bus_layout(char busnumber[]){
    FILE *busdetails, *seatdetails, *bookingdetails;
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

    char busnumber_layout[20];
    char busname_layout[40];
    char from_layout[40];
    char to_layout[40];
    DATE timing;
    TIME timing_hms;

    int totalseats = 20;;
    int temp_seat;
    char temp_name[30];

    int array_seats[20] = {NULL};
    char array_names[20][30] = {NULL};

    char filename_seats[100] = "seat_info_";
    char filename_passenger[100] = "passenger_info_";
    char database_seat[100] = "database/";
    char database_passenger[100] = "database/";

    int checkpoint = 0;
    int isdatetrue = 0;
    int istimetrue = 0;

    busdetails = fopen("database/busdetails.txt","r");

    while(fscanf(busdetails,"%s %s %s %s %d %d %d %d %d %d",busnumber_layout,busname_layout,from_layout,to_layout,&timing.day,&timing.month,&timing.year,&timing_hms.hour,&timing_hms.minute,&timing_hms.second) == 10){
        if(strcmp(busnumber_layout,busnumber) == 0){
            strcat(filename_seats,busnumber);
            strcat(filename_seats,".txt");
            strcat(database_seat,filename_seats);
            strcat(filename_passenger,busnumber);
            strcat(filename_passenger,".txt");
            strcat(database_passenger,filename_passenger);

            seatdetails = fopen(database_seat,"r");
            if(seatdetails != NULL){
                fscanf(seatdetails,"%d",&totalseats);
            }
            fclose(seatdetails);

            bookingdetails = fopen(database_passenger,"r");
            if(bookingdetails != NULL){
                while(fscanf(bookingdetails,"%d %s",&temp_seat,temp_name) == 2){
                    array_seats[temp_seat-1] = temp_seat;
                    strcpy(array_names[temp_seat-1],temp_name);
                }
            }

//DESIGN LAYOUT
            printf("\t\t************************************************************\n");
            printf("\t\t                            STATUS                          \n");
            printf("\t\t************************************************************\n");
            printf("\t\tBUS DEPARTURE DATE                    CURRENT DATE          \n");
            printf("\t\t%2d / %2d / %4d                         %2d / %2d / %4d            \n",timing.day,timing.month,timing.year,tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
            printf("\t\tTIME OF DEPARTURE                     CURRENT TIME          \n");
            printf("\t\t%2d / %2d / %2d                          %2d / %2d / %2d           \n\n",timing_hms.hour,timing_hms.minute,timing_hms.second,tm.tm_hour,tm.tm_min,tm.tm_sec);

            printf("\t\t                    STATUS FOR THE BUS %s:                   \n",busnumber);
            isdatetrue = date_validation(timing.day,timing.month,timing.year);
            if(isdatetrue == 1){
                istimetrue = time_validation(timing_hms.hour,timing_hms.minute,timing_hms.second);
                if(istimetrue == 1){
                        printf("\t\t\t\t\tBOOKING GOING ON....\n\n");
                }else{
                    printf("\t\t\t\t\tBUS IS ON THE WAY...\n\n");
                }
            }else{
                printf("\t\t\t\t\tBUS IS ON THE WAY\n\n");
            }
            for(int i = 0; i < 20; i++){
                if(array_seats[i] == NULL){
                    strcpy(array_names[i],"EMPTY");
                }
                printf("\t\t[%2d] %12s",i+1,array_names[i]);
                if((i+1) % 2 == 0){
                    printf("\n");
                }else{
                    printf("\t\t");
                }
            }
            printf("\n\t\t************************************************************\n");
            printf("\t\t            TOTAL SEATS AVAILABLE ARE %2d                   \n",totalseats);
            printf("\t\t************************************************************\n");
            checkpoint = 1;

// DESIGN LAYOUT
        }
    }
    if(checkpoint != 1){
        printf("\t\tTHIS BUS IS CURRENTLY NOT AVAIALABLE...(Press any key)");
        getch();
        printf("\n");
    }
    fclose(busdetails);
}
