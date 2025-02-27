#include <stdio.h>

#define THE_NUMBER 600851475143

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
    long long currentHighestPrimeDivisor = -1;

    long long number = THE_NUMBER;
    for(long long i = 3; i <=number; i += 2) //even numbers are avoided
    {

        if (isPrime(i) == 0)
        {
            if (THE_NUMBER % i == 0)
            {
                currentHighestPrimeDivisor = i;
                number = number / i;
            }
        }
    }

    printf("%lld\n", currentHighestPrimeDivisor);

    return 0;
}