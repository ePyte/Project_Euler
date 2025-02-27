#ifndef INITOPERATIONSHEADER_H
#define INITOPERATIONSHEADER_H

void initValArray(int mulArray[], int start, int end)
{
    for(int i = start; i < end; ++i)
    {
        mulArray[i] = -1;
    }
    
}


void setZeroArrayFunc(int * helperArray, int size)
{
    for(int i = 0; i < size; ++i)
    {
        *(helperArray + i) = 0;
    }
}

#endif