#ifndef MULTIPLICATIONSHEADER_H
#define MULTIPLICATIONSHEADER_H

typedef struct numberInBaseTen
{
    int ones;
    int tens;
    int hundreds;
}baseTypeStruct;

void incArraySize(int ** mulArray, int * startIndex, int * endIndex)
{
    (*startIndex) = (*endIndex);
    (*endIndex) += SIZESTEP;
    int * ptr = realloc((*mulArray), (*endIndex) * sizeof(int));
    if(ptr == NULL)
    {
        printf("Error: memory reallocation has failed.");
        exit(0);
    }
    *mulArray = ptr;
    initValArray(*mulArray, *startIndex, *endIndex);
}

void addDigitToArrayOverTens(int * helperArray, int index, int number)
{
    int overTen = 0;

    while(*(helperArray+index) + number + overTen >= 10)
    {
        *(helperArray+index) = (*(helperArray+index) + number + overTen) % 10;
        number = 0;
        overTen = 1;
        ++index;
    }

    *(helperArray+index) = *(helperArray+index) + overTen+number;

}


void multiplyDigits(int ** mulArray, int endIndex, int * helperArray, int shift, int multiplier)
{   
    for(int j = 0; j < endIndex; ++j)
    {
        if((*mulArray)[j] != -1)
        {
                addDigitToArrayOverTens(helperArray, j+shift, ((*mulArray)[j] * multiplier) % 10); //ones
                addDigitToArrayOverTens(helperArray, j+1+shift, ((*mulArray)[j] * multiplier) / 10); //tens
        }
    }
}

void determineBaseValues(baseTypeStruct * baseValues, int nextNumber)
{
    baseValues->hundreds = nextNumber / 100;
    baseValues->tens = (nextNumber % 100) / 10;
    baseValues->ones = nextNumber % 10;
}

int overideArrayByHelper(int ** mulArray, int * helperArray, int endIndex)
{
    int notCopy = 1;
    int spaceLeft = 0;
    for(int i = endIndex - 1; i >= 0 ; --i)
    {
        if(*(helperArray + i) == 0 && notCopy == 1)
        {
            ++spaceLeft;
            continue;
        }
        else
        {
            notCopy = 0;
        }
        (*mulArray)[i] = *(helperArray + i);
    }
    return spaceLeft;
}

void multiplication(int ** mulArray, int * startIndex, int * endIndex)
{    
    (*mulArray)[0] = FACTLOWLIMIT;

    baseTypeStruct baseValues = {0, 0, 0};

    for(int i = FACTLOWLIMIT+1; i <= FACTUPLIMIT; ++i)
    {   
        determineBaseValues(&baseValues, i);
        
        int * helperArray = (int *) malloc(*endIndex * sizeof(int));
        setZeroArrayFunc(helperArray, *endIndex);


        //ones
        multiplyDigits(mulArray, *endIndex, helperArray, 0, baseValues.ones);

        if(baseValues.tens >= 1)
        {
            multiplyDigits(mulArray, *endIndex, helperArray, 1, baseValues.tens);
        }

        if(baseValues.hundreds >= 1)
        {
            multiplyDigits(mulArray, *endIndex, helperArray, 2, baseValues.hundreds);
        }

        int spaceLeft = overideArrayByHelper(mulArray, helperArray, *endIndex);

        free(helperArray);

        if(spaceLeft <= SPACELIMIT) // max. mul 100 which means +2 digits in the array;
        {
            incArraySize(mulArray, startIndex, endIndex);
        }
    }
}

#endif