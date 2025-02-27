//From valgrind: 5056 bytes allocated.
//Runtime: 0.006s
#include <stdio.h>
#include <stdlib.h>

#define BASE 2
#define EXP 1000 
#define INITARRYLENGTH 16 //assumption: the result will be max 1000 digit long

#include "operationsHeader.h"

int main()
{
    int initLen = INITARRYLENGTH;
    int * length = &initLen;
    int * resultArray = (int*)malloc(sizeof(int) * initLen);

    if(resultArray == NULL)
    {
        printf("Memory allocation has failed.\n");
        return 0;
    }
    
    initArray(resultArray, length);
    
    long long result = sumOfDigits(&resultArray, length);
    printf("%lld\n", result);

    free(resultArray);
    return 1;
}