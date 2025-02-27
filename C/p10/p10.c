#include <stdio.h>

#define UPPER_LIMIT 2000000

int sqrtFuncForInt(int numberToRoot)
{
    for(int i = 1; i <= numberToRoot; ++i)
    {
        if(i*i >= numberToRoot)
        {
            return i;
        }
    }
}

int isPrime(int numberToCheck)
{
    int numberToIncrement = 2;

    if(numberToCheck < 2) //- integers, 0 and 1 are not considered primes
    {
        return 0; // false
    }
    int sqrtnumberToCheck = sqrtFuncForInt(numberToCheck);
    while(numberToIncrement <= sqrtnumberToCheck)
    {
        if(numberToCheck % numberToIncrement == 0)
        {
            return 0; //false
        }
        ++numberToIncrement;
    }

    return 1; //true
}

int main()
{
    long long sumOfPrimes = 2; //2 is the only even prime, also the smallest
    for(int i = 3; i < UPPER_LIMIT;  i += 2) // starting with 3 the increment step can be 2
    {
        if(isPrime(i) == 1)
        {
            sumOfPrimes += i;
        }
    }

    printf("Sum of primes below 2000000:\n");
    printf("%lld\n", sumOfPrimes);

    return 0;
}