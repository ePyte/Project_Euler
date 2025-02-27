#ifndef OPERATIONSHEADER_H
#define OPERATIONSHEADER_H

void firstRowInit(long long mainArray[])
{
    for(int i = 0; i < ARRAYSIDE; ++i)
    {
        mainArray[i] = 1;
    }
}

void firstColumnInit(long long mainArray[])
{
    for(int i = 0; i < ARRAYSIDE; ++i)
    {
        mainArray[i*ARRAYSIDE] = 1;
    }
}

void addTogetherTheDiagonals(long long mainArray[])
{   
    for(int i = 1; i < ARRAYSIDE; ++i)//2nd row -> 3rd row ->...
    {
        for(int j = 1; j < ARRAYSIDE; ++j)
        {
            mainArray[i*ARRAYSIDE+j] = mainArray[(i-1)*ARRAYSIDE+j]+mainArray[i*ARRAYSIDE+(j-1)];
        }
        
    }
}

#endif