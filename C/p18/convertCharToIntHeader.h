#ifndef CONVERTCHARTOINT_H
#define CONVERTCHARTOINT_H

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

int getInt(char c, char d)
{
    return nextDigit(c) * 10 + nextDigit(d);
}

#endif