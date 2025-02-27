#include <stdio.h>

#define ARRAYSIDE 21 //+1 sidelength; each cell contains a value representing the edges

#include "operationsHeader.h"

int main()

{
    long long mainArray[(ARRAYSIDE)*(ARRAYSIDE)];
    firstRowInit(mainArray);//only one path in the first row
    firstColumnInit(mainArray);//only one path in the first column
    addTogetherTheDiagonals(mainArray);

    printf("%lld\n", mainArray[(ARRAYSIDE-1)*ARRAYSIDE+ARRAYSIDE-1]);//bottom-right corner
    return 1;
}