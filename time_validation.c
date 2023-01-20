/*
This module has functions used in other modules to validate date and time.

TO LEARN MORE ABOUT THIS MODULE KINDLY REFER TO DOCUMENTATION
*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "busfunction.h"
#include "designfunction.h"


int date_validation(int day,int month,int year);
int time_validation(int hour,int minute,int second);

//it takes parameter of the day,month and year you want to compare with the current date
int date_validation(int day,int month,int year){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if (year < tm.tm_year + 1900){
       return -1;
    }
    else if (year > tm.tm_year + 1900){
       return 1;
    }

    if (year == tm.tm_year + 1900)
    {
         if (month < tm.tm_mon + 1)
              return -1;
         else if (month > tm.tm_mon + 1)
              return 1;
         else if (day < tm.tm_mday)
              return -1;
         else if(day > tm.tm_mon + 1)
              return 1;
         else
              return 0;
    }
}

//it takes the input of hour,minute and second you want to compare with the current time.
int time_validation(int hour,int minute,int second){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if (hour < tm.tm_hour){
       return -1;
    }
    else if (hour > tm.tm_hour){
       return 1;
    }

    if (hour == tm.tm_hour){
         if (minute < tm.tm_min)
              return -1;
         else if (minute > tm.tm_min)
              return 1;
         else if (second < tm.tm_sec)
              return -1;
         else if(second > tm.tm_sec)
              return 1;
         else
              return 0;
    }
}
