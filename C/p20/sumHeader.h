#ifndef SUMHEADER_H
#define SUMHEADER_H

int sumFunc(int ** mulArray, int * endIndex)
{
    int sum = 0;
    for(int i = 0; i< *endIndex; ++i)
    {
        if(*((*mulArray)+i) == -1)
        {
            break;
        }
        sum += (*mulArray)[i];
    }
    return sum;
}

int factorialDigitsSum(int ** mulArray, int * startIndex, int * endIndex)
{
    multiplication(mulArray, startIndex, endIndex);

    int sum = sumFunc(mulArray, endIndex);

    return sum;
}
#endif