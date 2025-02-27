#include <stdio.h>

#define NUMBEROFMONTHS 12
#define NUMBEROFDAYSPERYEARNOTLEAP 365
#define NUMBEROFDAYSPERWEEK 7
#define STARTYEAR 1901
#define ENDYEAR 2000



#include "enumMonthLengthsHeader.h"
#include "operationsHeader.h"


//1 Jan 1901 to 31 Dec 2000

int main()
{
    int arrayMonthLengths[NUMBEROFMONTHS];
    initArray(arrayMonthLengths);
    int initDay = 1;//1 Jan 1900 was a Monday

    int firstDay = (initDay + NUMBEROFDAYSPERYEARNOTLEAP) % NUMBEROFDAYSPERWEEK; //1900 was not a leap year (1 Jan 1901)
    printf("%d\n", firstDay);
    printf("Hello\n");
    int sumOfMondaysOnFirst = countMondays(firstDay, arrayMonthLengths);

    printf("%d\n", sumOfMondaysOnFirst);
    return 1;
}

/*
1 -> Mon
2 -> Tue
...
6 -> Sat
0 -> Sun
*/