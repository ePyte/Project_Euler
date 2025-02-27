#ifndef OPERATIONSHEADER_H
#define OPERATIONSHEADER_H

void initArray(int resultArray[], int * length)//the lowest decimal in the first cell
{
    for(int i = 1; i < (*length); ++i)
    {
        resultArray[i] = -1;
    }
    resultArray[0] = BASE;
}


void doubleInitArray(int prevLength, int resultArray[], int newLength)
{
    for(int i = prevLength; i < newLength; ++i)
    {
        resultArray[i] = -1;
    }
}

void doubleArraySize(int ** resultArray, int* length)
{
    int prevLength = (*length);
    int newLength = 2 * prevLength;
    *length = newLength;

    int * ptr = (int *)realloc((*resultArray), newLength * sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory reallocation has failed.\n");
        exit(0);
    }
    *resultArray = ptr;
    doubleInitArray(prevLength, *resultArray, *length);
}

void powFunc(int ** resultArray, int * length)
{
    int exp = EXP;
    int overTen = 0;

    while(exp>1)
    {
        for(int i = 0; i < (*length); ++i)//turn the direction
        {
            if((*resultArray)[i] == -1)//exit from for cycle
            {
                if(overTen == 1)
                {
                    (*resultArray)[i] = overTen;
                }
                overTen = 0;
                --exp;//exit from while cycle
                break;
            }

            if((BASE * (*resultArray)[i] + overTen) >= 10)
            {
                (*resultArray)[i]= ((BASE * (*resultArray)[i] + overTen) % 10);
                overTen = 1;
            }
            else
            {
                (*resultArray)[i]= BASE * (*resultArray)[i] + overTen;
                overTen = 0;
            }

            if((i == ((*length)-2)) && (overTen == 1))
            {
                doubleArraySize(resultArray, length);
            }
        }
    }
}


long long addDigits(int resultArray[], int * length)
{
    long long sum = 0;
    for(int i = 0; i < *length; ++i)
    {
        if(resultArray[i] != -1)
        {
            sum += (long long)resultArray[i];
        }
        else
        {
            break;
        }
    }
    return sum;
}

long long sumOfDigits(int ** resultArray, int * length)
{
    powFunc(resultArray, length);

    long long result = addDigits(*resultArray, length);
    return result;
}

#endif

