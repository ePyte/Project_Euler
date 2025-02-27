#ifndef OPERATIONSHEADER_H
#define OPERATIONSHEADER_H

#include <stdio.h>

int nextDigit(char currentChar)
{
    int currentDigit = 0;
    switch(currentChar)
    {
        case '1':
            currentDigit = 1;
            break;
        case '2':
            currentDigit = 2;
            break;
        case '3':
            currentDigit = 3;
            break;
        case '4':
            currentDigit = 4;
            break;
        case '5':
            currentDigit = 5;
            break;
        case '6':
            currentDigit = 6;
            break;
        case '7':
            currentDigit = 7;
            break;
        case '8':
            currentDigit = 8;
            break;
        case '9':
            currentDigit = 9;
            break;
        case '0':
            currentDigit = 0;
            break;
        default:
            currentDigit = 0;
            break;
    }
    return currentDigit;
}

void addDigitToDigit(int newDigit, int indexOfNewDigit, int sumArray[])
{
        int index = LENGHTOFSUM - (NUMOFDIGITS - indexOfNewDigit); //numbers: right smallest decimal
        int digitInSumArray = sumArray[index];
        
        while(1)
        {
            if((digitInSumArray + newDigit) < 10)
            {
                sumArray[index] = (digitInSumArray + newDigit);
                break;
            }
            else // the sum of 2 digits is >=10
            {       sumArray[index] = ((digitInSumArray + newDigit) % 10);
                    newDigit = 1;
                    --index;
                    digitInSumArray = sumArray[index];
            }
        }
}

void addDigitsToArray(char charArray[], int sumArray[])
{
    for(int i = NUMOFDIGITS-1; i >= 0; --i)
    {
        addDigitToDigit(nextDigit(charArray[i]), i, sumArray);
    }
}

long long getTopTenDigitsFunc(int sumArray[])
{
    long long topTenDigitNumber = 0;
    int counter = 0;

    for(int i = 0; i < LENGHTOFSUM; ++i)
    {
        if((counter >= TENDIGITS))
        {
            return topTenDigitNumber;
        }

        if(counter > 0)
        {
            topTenDigitNumber *= 10; 
            topTenDigitNumber += sumArray[i];
            ++counter;
        }

        if((sumArray[i] != 0) && (counter == 0))//getFirstDigit
        {
            topTenDigitNumber = sumArray[i];
            ++counter;
        }
    }

    return 0; //no 10 digit number found
}

#endif