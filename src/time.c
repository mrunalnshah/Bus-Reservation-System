#include "time.h"

struct tm createTimeStruct(struct Time givenTime) {
	struct tm tm_time = { 0 }; 

	tm_time.tm_year = givenTime.year - 1900;
	tm_time.tm_mon = givenTime.month - 1;
	tm_time.tm_mday = givenTime.day;
	tm_time.tm_hour = givenTime.hour;
	tm_time.tm_min = givenTime.minute;
	tm_time.tm_sec = givenTime.second;

	return tm_time;
}

int timeValidation(struct Time givenTime) {
    struct tm tm_time = createTimeStruct(givenTime);
    time_t givenTime_t = mktime(&tm_time);
    time_t currentTime = time(NULL);

    if (givenTime_t == -1) {
        perror("mktime");
        return -1;
    }

    if (givenTime_t < currentTime) {
        return -1;
    }
    else if (givenTime_t > currentTime) {
        return 1;
    }
    else {
        return 0;
    }
}