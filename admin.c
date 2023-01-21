/*
This module ask the admin to enter a digit and based on the digit the switch cases are implemented. also it has capacity to create new buses for registration and new users
so that the users can login in the system and avail the user interface while admin avails admin interface.

TO LEARN MORE ABOUT THIS MODULE KINDLY REFER TO DOCUMENTATION
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "busfunction.h"
#include "designfunction.h"
#include "choicefunction.h"


void admin(); //ask the user to input digit and based on input the switch cases work.
void register_bus(); /*it is for the bus registration or adding bus details to the busdetails.txt so that the bus can be registered otherwise user cannot book
for any bus otherthan the admin registered bus */
void register_user(); /* The function helps to register new username and password which can be used to login as the user. any username doesnot work only registered username
works for valid login*/

void admin(){
    system("cls || clear");
    returnpage();
    int yourchoice;

    printf("\t\t[1] BUS AVAILABILITY\n");
    printf("\t\t[2] BUS BOOKING\n");
    printf("\t\t[3] BUS CANCELLATION\n");
    printf("\t\t[4] BUS STATUS\n");
    printf("\t\t[5] REGISTER USER\n");
    printf("\t\t[6] REGISTER BUS\n");
    printf("\t\t[7] EXIT\n");

    printf("\n\t\tEnter your choice :  ");
    scanf("%d",&yourchoice);

    switch(yourchoice){
    case 1:
        {
            system("cls || clear");
            busavailability();
            printf("\t\tPress any key to continue...");
            getch();
            admin();
            break;
        }
    case 2:
        {
            system("cls || clear");
            busbooking();
            admin();
            break;
        }
    case 3:
        {
            system("cls || clear");
            admin_buscancellation();
            admin();
            break;
        }
    case 4:
        {
            system("cls || clear");
            busstatus();
            printf("\t\tPress any key to continue...");
            getch();
            printf("\n");
            admin();
            break;
        }
    case 5:
        {
            system("cls || clear");
            register_user();
            admin();
            break;
        }
    case 6:
        {
            system("cls || clear");
            register_bus();
            admin();
            break;
        }
    case 7:
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
        }
    }
}

void register_bus(){
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

    FILE *busregister;
    int numberofbuses;

    char register_busnumber[10];
    char register_busname[40];
    char from[50],to[50];
    DATE timing;
    TIME timing_hms;

    char array_busnumber[100][10];
    char array_busname[100][200];
    char array_from[100][100];
    char array_to[100][100];
    DATE times[100];
    TIME times_hms[100];

    int istruedate = 0;
    int istruetime = 0;

    printf("\t\t*****************************************************************************\n");
    printf("\t\t                             BUS REGISTRATION                             \n");
    printf("\t\t*****************************************************************************\n");

    makedir();
    busregister = fopen("database/busdetails.txt","r");

    if(busregister == NULL){
        busregister = fopen("database/busdetails.txt","w");

        printf("\t\tEnter number of buses to be registered : ");
        scanf("%d",&numberofbuses);

        for(int i = 0; i < numberofbuses; i++){
            printf("\t\tBUS [%d] \n",i+1);
            printf("\t\tNUMBER : ");
            scanf("%s",register_busnumber);
            printf("\t\tNAME   : ");
            scanf("%s",register_busname);
            printf("\t\tROUTE NAME \n");
            printf("\t\tFROM   : ");
            scanf("%s",from);
            printf("\t\tTO     : ");
            scanf("%s",to);
            do{
                printf("\t\tDATE   \n ");
                printf("\t\tDay   : ");
                scanf("%d",&timing.day);
                printf("\t\tMonth :");
                scanf("%d",&timing.month);
                printf("\t\tYear  : ");
                scanf("%d",&timing.year);

                istruedate = date_validation(timing.day,timing.month,timing.year);

                if((timing.day < 1 && timing.day > 31) || (timing.month < 1 || timing.month > 12) || (timing.year < (tm.tm_year + 1900)) ){
                    printf("\n\t\tInvalid Dates. Kindly re-enter\n");
                }
                if(istruedate != 1){
                    printf("\t\tPast Dates are not valid for the registration of Future Buses!!!\n");
                }
            }while((timing.day < 1 && timing.day > 31) || (timing.month < 1 || timing.month > 12) || (timing.year < (tm.tm_year + 1900)) || (istruedate != 1) );
            do{
                printf("\t\tTIME IN 24 HOURS  \n ");
                printf("\t\tHours   : ");
                scanf("%d",&timing_hms.hour);
                printf("\t\tMinutes :");
                scanf("%d",&timing_hms.minute);
                printf("\t\tSeconds  : ");
                scanf("%d",&timing_hms.second);

                istruetime = time_validation(timing_hms.hour,timing_hms.minute,timing_hms.second);

                if((timing_hms.hour < 0 && timing_hms.hour > 24) || (timing_hms.minute < 0 || timing_hms.minute > 60) || (timing_hms.second < 0 || timing_hms.second > 61 )){
                    printf("\t\tINVALID TIMING\n");
                }else if(istruetime != 1){
                    printf("Past time is not available");
                }
            }while((timing_hms.hour < 0 && timing_hms.hour > 24) || (timing_hms.minute < 0 || timing_hms.minute > 60) || (timing_hms.second < 0 || timing_hms.second > 61 ) || istruetime != 1);

            fprintf(busregister,"%s %s %s %s %d %d %d %d %d %d\n",register_busnumber,register_busname,from,to,timing.day,timing.month,timing.year,timing_hms.hour,timing_hms.minute,timing_hms.second);
        }
        fclose(busregister);
    }else{
        int initial = 0;
        busregister = fopen("database/busdetails.txt","r");

        while(fscanf(busregister,"%s %s %s %s %d %d %d %d %d %d",&register_busnumber,register_busname,from,to,&timing.day,&timing.month,&timing.year,&timing_hms.hour,&timing_hms.minute,&timing_hms.second) == 10){
            strcpy(array_busnumber[initial],register_busnumber);
            strcpy(array_busname[initial],register_busname);
            strcpy(array_from[initial],from);
            strcpy(array_to[initial],to);
            times[initial].day = timing.day;
            times[initial].month = timing.month;
            times[initial].year = timing.year;
            times_hms[initial].hour = timing_hms.hour;
            times_hms[initial].minute = timing_hms.minute;
            times_hms[initial].second = timing_hms.second;
            initial++;
        }
        printf("\t\tEnter number of buses to be registered : ");
        scanf("%d",&numberofbuses);

        for(int i = 0; i < numberofbuses; i++){
            printf("\t\tBUS [%d] \n",i+1);
            printf("\t\tNUMBER : ");
            scanf("%s",array_busnumber[initial]);
            printf("\t\tNAME   : ");
            scanf("%s",array_busname[initial]);
            printf("\t\tROUTE NAME \n");
            printf("\t\tFROM   : ");
            scanf("%s",array_from[initial]);
            printf("\t\tTO     : ");
            scanf("%s",array_to[initial]);
            do{
                printf("\t\tTIME   \n ");
                printf("\t\tDay   : ");
                scanf("%d",&times[initial].day);
                printf("\t\tMonth :");
                scanf("%d",&times[initial].month);
                printf("\t\tYear  : ");
                scanf("%d",&times[initial].year);

                if((times[initial].day < 1 && times[initial].day > 31) || (times[initial].month < 1 || times[initial].month > 12) || (times[initial].year < 2023) ){
                    printf("\n\t\tInvalid Dates. Kindly re-enter\n");
                }
                if(istruedate != 1){
                    printf("\t\tPast Dates are not valid for the registration of Future Buses!!!\n");
                }
            }while((times[initial].day < 1 && times[initial].day > 31) || (times[initial].month < 1 || times[initial].month > 12) || (times[initial].year < 2023) || (istruedate != 1) );
            do{
                printf("\t\t TIME IN 24 Hours Format   \n ");
                printf("\t\tHours   : ");
                scanf("%d",&times_hms[initial].hour);
                printf("\t\tMinutes :");
                scanf("%d",&times_hms[initial].minute);
                printf("\t\tSeconds  : ");
                scanf("%d",&times_hms[initial].second);

                if((timing_hms.hour < 0 && timing_hms.hour > 24) || (timing_hms.minute < 0 || timing_hms.minute > 60) || (timing_hms.second < 0 || timing_hms.second > 61 )){
                    printf("\t\tINVALID TIMING\n");
                   }
            }while((timing_hms.hour < 0 && timing_hms.hour > 24) || (timing_hms.minute < 0 || timing_hms.minute > 60) || (timing_hms.second < 0 || timing_hms.second > 61 ));
            initial++;
        }
        fclose(busregister);
        busregister = fopen("database/busdetails.txt","w");
        for(int i = 0; i < initial;i++){
            fprintf(busregister,"%s %s %s %s %d %d %d %d %d %d\n",array_busnumber[i],array_busname[i],array_from[i],array_to[i],times[i].day,times[i].month,times[i].year,times_hms[i].hour,times_hms[i].minute,times_hms[i].second);
        }

        fclose(busregister);
    }
}
void register_user(){
    FILE *userregister;

    makedir();

    int numberofusers;
    char register_username[20],register_password[30];
    char array_username[100][20],array_password[100][30];

    printf("\t\t*****************************************************************************\n");
    printf("\t\t                            USER REGISTRATION                             \n");
    printf("\t\t*****************************************************************************\n");

    userregister = fopen("database/userdetails.txt","r");

    if(userregister == NULL){
        userregister = fopen("database/userdetails.txt","w");

        printf("\t\tHow many users to be registered : ");
        scanf("%d",&numberofusers);

        for(int i = 0;i < numberofusers;i++){
            printf("\t\tUSER [%d]\n",i+1);
            printf("\t\tusername : ");
            scanf("%s",register_username);
            printf("\t\tpassword : ");
            scanf("%s",register_password);

            fprintf(userregister,"%s %s\n",register_username,register_password);
        }
        fclose(userregister);
    }else{
        userregister = fopen("database/userdetails.txt","r");

        int initial = 0;
        while(fscanf(userregister,"%s %s",register_username,register_password) == 2){
            strcpy(array_username[initial],register_username);
            strcpy(array_password[initial],register_password);
            initial++;
        }

        printf("\t\tHow many users to be registered : ");
        scanf("%d",&numberofusers);

        for(int i = 0;i < numberofusers;i++){
            printf("\t\tUSER [%d]\n",i+1);
            printf("\t\tusername : ");
            scanf("%s",array_username[initial]);
            printf("\t\tpassword : ");
            scanf("%s",array_password[initial]);
            initial++;
        }

        userregister = fopen("database/userdetails.txt","w");

        for(int i = 0; i < initial;i++){
            fprintf(userregister,"%s %s\n",array_username[i],array_password[i]);
        }

        fclose(userregister);
    }
}
