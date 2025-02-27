#ifndef OPERATIONSHEADER_H
#define OPERATIONSHEADER_H

void initArray(int inputsArray[], int arrayLength)
{
    for(int i = 0; i < arrayLength; ++i)
    {
        inputsArray[i] = -1;
    }
}

int determineMaxSum(int inputsArray[], int arrayLength)
{
    int numberOfElementsInRow = 0;
    int numberOfRow = ARRAYLENGTH;
    for(int i = arrayLength-1; i>1; --i)
    {
        if(inputsArray[i] >= inputsArray[i-1])
        {
            inputsArray[i-numberOfRow] += inputsArray[i];
        }
        else
        {
            inputsArray[i-numberOfRow] += inputsArray[i-1];
        }
        numberOfElementsInRow++;
        if(numberOfElementsInRow + 1 == numberOfRow)
        {
            --i;
            numberOfElementsInRow = 0;
            --numberOfRow;
        }
    }
    return inputsArray[0];
}

#endif