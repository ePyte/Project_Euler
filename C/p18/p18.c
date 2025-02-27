#include <stdio.h>

#define ARRAYLENGTH 15 //numberOfRows

#include "operationsHeader.h"
#include "convertCharToIntHeader.h"
#include "readInData.h"


int main()
{
    int arrayLength = (ARRAYLENGTH+1)*ARRAYLENGTH/2;
    int inputsArray[arrayLength]; //arithmetic series; low triangle array
    initArray(inputsArray, arrayLength);

    readInDataFromTxt(inputsArray);

    int result = determineMaxSum(inputsArray, arrayLength);

    printf("%d\n", result);

    return 1;
}