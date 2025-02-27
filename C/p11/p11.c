#include <stdio.h>

#define NUMBEROFCOLS 20
#define NUMBEROFROWS 20
#define NUMBEROFMUL 4

#include "convertCharToIntHeader.h"
#include "readInData.h"
#include "maxHeader.h"
#include "horizonVertMulHeader.h"
#include "diagonalMulHeader.h"
#include "maxCompareHeader.h"

int main()
{

    int workingArray[NUMBEROFCOLS*NUMBEROFROWS];
    readInDataFromTxt(workingArray);

    int finalMax = maxCompare(workingArray);
    printf("\nMAX: %d\n", finalMax);

    return 1;
}

