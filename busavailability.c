/*
This module fetch data from the database file name busdetails.txt and prints the data of the bus schedule as a whole.

TO LEARN MORE ABOUT THIS MODULE KINDLY REFER TO DOCUMENTATION
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "busfunction.h"
#include "designfunction.h"


void busavailability();

//refer to the module info as its the only function
void busavailability(){
    printf("\t\t*****************************************************************************\n");
    printf("\t\t                        BUS AVAILABILITY SCHEDULE                            \n");
    printf("\t\t*****************************************************************************\n");
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

    FILE *busdetails;

    char register_busnumber[40];
    char register_busname[40];
    char from[50],to[50];
    DATE timing;
    TIME timing_hms;


    int initial = 1;

    busdetails = fopen("database/busdetails.txt","r");

    if(busdetails != NULL){
        while(fscanf(busdetails,"%s %s %s %s %d %d %d %d %d %d",register_busnumber,register_busname,from,to,&timing.day,&timing.month,&timing.year,&timing_hms.hour,&timing_hms.minute,&timing_hms.second) == 10){
            printf("\t\t[%d] %0.20s\n",initial,register_busname);
            printf("\t\t\tBUS NUMBER : %2.8s\n\t\t\tBUS NAME : %0.20s\n\t\t\tDEPATURE : %0.10s \t DESTINATION : %0.10s\n\t\t\tDeparture Date : %02d / %02d / %4d\n\t\t\tDeparture Time : %02d:%02d:%02d\n",register_busnumber,register_busname,from,to,timing.day,timing.month,timing.year,timing_hms.hour,timing_hms.minute,timing_hms.second);
            initial++;
        }
    }else{
        printf("\t\tNO BUSES REGISTERED YET...\n");
    }
}
