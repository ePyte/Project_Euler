#ifndef MAXCOMPARE_H
#define MAXCOMPARE_H

#include <stdio.h>

int maxCompare(int intArray[])
{
    int rowMaxValue = rowMaxMul(intArray);
    int colMaxValue = colMaxMul(intArray);
    int diagMaxValue = diagMaxMul(intArray);
    printf("ROWMAX: %d\n", rowMaxValue);
    printf("COLMAX: %d\n", colMaxValue);
    printf("DIAG. MAX: %d\n", diagMaxValue);
    return maxFunc(maxFunc(rowMaxValue, colMaxValue), diagMaxValue);
}

#endif