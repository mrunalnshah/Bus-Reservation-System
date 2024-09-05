#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

struct Time {
	int second;
	int minute;
	int hour;

	int day;
	int month;
	int year;
};

struct tm createTimeStruct(struct Time givenTime);
int timeValidation(struct Time givenTime);