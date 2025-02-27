#include <stdio.h>

#define THE_NUMBER 10001

int isPrime(long long nextNumber)
{
    long long incNumber = 2;

    while (incNumber < nextNumber)
    {
        if ( nextNumber % incNumber == 0)
        {
            return 1; // not prime
        }

        incNumber++;
    }

    return 0; // prime
}

int main()
{
    long long currentNumber = 3; //the steps in the while cycle can be 2
    long long currentPrimeNumber = 2;
    int primeNumberCounter = 1;


    while(primeNumberCounter != THE_NUMBER)
    {
        if (isPrime(currentNumber) == 0)
        {
            currentPrimeNumber = currentNumber;
            primeNumberCounter++;
        }
        currentNumber += 2;
    }

    printf("%lld\n", currentPrimeNumber);

    return 0;
}