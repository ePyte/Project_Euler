#ifndef OPERATIONSHEADER_H
#define OPERATIONSHEADER_H

typedef struct numberWithDigits{
    int numberOfDigits;
    int ones;
    int tens;
    int hundreds;
}numberWithDigitsStr;

int countCharsOfNumberFunc(numberWithDigitsStr * numberDividedPtr)
{
    int numberOfChars = 0;
    if(numberDividedPtr->numberOfDigits == 3)
    {
        numberOfChars += hundredsOrOnesExchange(numberDividedPtr->hundreds);
        numberOfChars += HUNDRED;
        if((numberDividedPtr->tens > 0) || (numberDividedPtr->ones > 0))
        {
            numberOfChars += AND;
        }
    }
    if(numberDividedPtr->tens == 1) //X10-X19
    {
        return numberOfChars += tenToNineteenExchange(10* (numberDividedPtr->tens) + numberDividedPtr->ones);
    }

    return numberOfChars + tensExchange(numberDividedPtr->tens) + hundredsOrOnesExchange(numberDividedPtr->ones);
}

void divideNumberFunc(int nextNumber, numberWithDigitsStr * numberDividedPtr)
{
    numberDividedPtr->hundreds = nextNumber / 100;
    numberDividedPtr->tens = (nextNumber % 100) / 10;
    numberDividedPtr->ones = (nextNumber % 10);

    numberDividedPtr->numberOfDigits = 1; // 0 is not valid number in this task, lowest number is one
    if(numberDividedPtr->tens>0)
    {
        numberDividedPtr->numberOfDigits = 2;
    }

    if(numberDividedPtr->hundreds>0)
    {
        numberDividedPtr->numberOfDigits = 3;
    }
}

int numberOfCharsFunc(int nextNumber)
{
    int sumOfDigits = 0;
    numberWithDigitsStr numberDivided = {0, 0, 0, 0};
    numberWithDigitsStr * numberDividedPtr = &numberDivided;
    if(nextNumber == MAXLIMIT)
    {
        return ONE + THOUSAND;
    }
    divideNumberFunc(nextNumber, numberDividedPtr);
    return countCharsOfNumberFunc(numberDividedPtr);
}

int addTogetherNumbers()
{
    int sum = 0;

    for(int i = 1; i <= MAXLIMIT; ++i)
    {
        sum += numberOfCharsFunc(i);
    }
    return sum;
}

#endif