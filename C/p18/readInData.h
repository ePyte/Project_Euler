#ifndef READINDATA_H
#define READINDATA_H

#include <stdio.h>
#include <stdlib.h>

void readInDataFromTxt(int workingArray[])
{
    FILE *fptr;
    fptr = fopen("p18_inputs.txt", "r");

    if(fptr == NULL)
    {
        printf("Not able to open the txt file.");
        exit(0);
    }

    int indexArray = 0;
    char c;
    char d;

    while (1)
    {
        c = fgetc(fptr);
        d = fgetc(fptr);//works only for 2 digit numbers; the leading 0 can be handled
        workingArray[indexArray] = getInt(c, d);
        ++indexArray;

        if ((c = fgetc(fptr)) == EOF) //spaces; \n; EOF
        {
            break;
        }
    }

    fclose(fptr);
}

#endif