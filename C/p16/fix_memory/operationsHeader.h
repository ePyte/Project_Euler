#ifndef OPERATIONSHEADER_H
#define OPERATIONSHEADER_H

void initArray(int resultArray[])//the lowest decimal in the last cell
{
    for(int i = 0; i < LENGTH-1; ++i)
    {
        resultArray[i] = -1;
    }
    resultArray[LENGTH-1] = BASE;
}

void powFunc(int resultArray[])
{
    int exp = EXP;
    int overTen = 0;

    while(exp>1)
    {
        for(int i = LENGTH-1; i >=0; --i)
        {
            if(resultArray[i] == -1)//exit from for cycle
            {
                if(overTen == 1)
                {
                    resultArray[i] = overTen;
                }
                overTen = 0;
                --exp;//exit from while cycle
                break;
            }

            if((BASE * resultArray[i] + overTen) >= 10)
            {
                resultArray[i]= ((BASE * resultArray[i] + overTen) % 10);
                overTen = 1;
            }
            else
            {
                resultArray[i]= BASE * resultArray[i] + overTen;
                overTen = 0;
            }
        }
    }
}


int addDigits(int resultArray[])
{
    long long sum = 0;
    for(int i = LENGTH-1; i >= 0; --i)
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

long long sumOfDigits(int resultArray[])
{
    powFunc(resultArray);

    long long result = addDigits(resultArray);
    return result;
}

#endif