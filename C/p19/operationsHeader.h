#ifndef OPERATIONSHEADER_H
#define OPERATIONSHEADER_H

void initArray(int arrayMonthLengths[])
{
    arrayMonthLengths[0] = JAN;
    arrayMonthLengths[1] = FEB_NOT_LEAP;
    arrayMonthLengths[2] = MAR;
    arrayMonthLengths[3] = APR;
    arrayMonthLengths[4] = MAY;
    arrayMonthLengths[5] = JUN;
    arrayMonthLengths[6] = JUL;
    arrayMonthLengths[7] = AUG;
    arrayMonthLengths[8] = SEP;
    arrayMonthLengths[9] = OCT;
    arrayMonthLengths[10] = NOV;
    arrayMonthLengths[11] = DEC;
}

int isLeapYearFunc(int year)
{
    if(year % 4 == 0)
    {
        if(year % 400 == 0)
        {
            return 1; // true
        }
        if(year % 100 == 0)
        {
            return 0; // false
        }
        return 1; // true
    }
    return 0; // false
}

int countMondays(int firstDay, int arrayMonthLengths[])
{
    int sumOfMondaysOnFirst = 0;
    int isLeapYear = 0;
    for(int i = STARTYEAR; i <= ENDYEAR; ++i)
    {
        isLeapYear = isLeapYearFunc(i);
        if(isLeapYear == 1)
        {
            printf("%d\n", i);
        }
        for(int j = 0; j < NUMBEROFMONTHS; ++j)
        {
            if(isLeapYear == 1 && j == 1)
            {
                firstDay += FEB_LEAP;
            }
            else
            {
                firstDay += arrayMonthLengths[j];
            }


            firstDay %= NUMBEROFDAYSPERWEEK;
            if(firstDay == 0) //Sundays
            {
                ++sumOfMondaysOnFirst;
            }
        }
    }
    return sumOfMondaysOnFirst;
}
#endif