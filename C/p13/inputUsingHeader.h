#ifndef INPUTUSINGHEADER_H
#define INPUTUSINGHEADER_H

#include <stdio.h>
#include <stdlib.h>

long long firstTenDigitsFunc(int sumArray[], int lengthOfSum)
{
    int firstTenDigits = 0;
    FILE* ftpr;
    ftpr = fopen("p13inputs.txt", "r");

    if(ftpr == NULL)
    {
        printf("Not able to open the file.");
        exit(0);
    }

    char charArray[NUMOFDIGITS+1];
    charArray[NUMOFDIGITS] = '\0';
    for(int i = 0; i < NUMOFROWS; ++i)
    {
        for(int j = 0; j < NUMOFDIGITS; ++j)
        {
            charArray[j] = fgetc(ftpr);
        }
        addDigitsToArray(charArray, sumArray);//numbers are stored from "left to right"
        fgetc(ftpr);//'\n's and EOF
    }

    fclose(ftpr);

    long long result = getTopTenDigitsFunc(sumArray);

    return result;
}

#endif