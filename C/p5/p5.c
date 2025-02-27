#include <stdio.h>

#define LOWER_LIMIT 1
#define UPPER_LIMIT 20


void initBaseValuesPrimeNumbersArray(int primeNumbersArray[], int sizePrimeNumberArray)
{
    for (int i = 0; i < sizePrimeNumberArray; ++i)
    {
        primeNumbersArray[i] = -1;
    }

}

int isPrime(int nextNumber)
{
    if (nextNumber< 2)
    {
        return 1; // not prime
    }

    int incNumber = 2;

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

int intitPrimeNumbers(int primeNumbersArray[], int sizePrimeNumberArray)
{
    int numberOfPrimes = 0;

    for (int i = LOWER_LIMIT; i < UPPER_LIMIT; ++i)
    {
        if (isPrime(i) == 0)
        {
            primeNumbersArray[numberOfPrimes] = i;
            ++numberOfPrimes;
        }
    }

    return numberOfPrimes;
}

void initBaseValuesPrimeFactorsArray(int primeFactorsArray[], int numberOfRowsPrimeFactors, int numberOfPrimes, int primeNumbersArray[])
{
        //first line contains the primes
        for (int j = 0; j < numberOfPrimes; ++j)
        {
            primeFactorsArray[0+j] = primeNumbersArray[j];
        }

        for (int i = 1; i < numberOfRowsPrimeFactors; ++i)
        {
            for (int j = 0; j < numberOfPrimes; ++j)
            {
                primeFactorsArray[i*numberOfPrimes+j] = 0;
            }
        }
}

int findMaxPowerInColumn(int primeFactorsArray[], int numberOfPrimes, int choosenColumn)
{
    int maxFactor = 0;
    for ( int i = LOWER_LIMIT; i<=UPPER_LIMIT; ++i)
    {
        if (primeFactorsArray[i*numberOfPrimes+choosenColumn] > maxFactor)
        {
            maxFactor = primeFactorsArray[i*numberOfPrimes+choosenColumn];
        }
    }

    return maxFactor;
}

int powerFunc(int base, int power)
{
    int result = 1;
    while ( power >= 1)
    {
        result *=base;
        power--;
    }

    return result;
}

int leastCommonMultFunc(int primeFactorsArray[], int numberOfRowsPrimeFactors, int numberOfPrimes)
{
    for (int i = LOWER_LIMIT; i <= UPPER_LIMIT; ++i) //line 0 contains the prime factors
    {
        int valueToDecompose = i;
        for(int j = 0; j < numberOfPrimes; ++j)
        {
            if (valueToDecompose %  primeFactorsArray[j] == 0)
            {
                while(valueToDecompose %  primeFactorsArray[j] == 0)
                {
                    primeFactorsArray[i*numberOfPrimes+j]++;
                    valueToDecompose /= primeFactorsArray[j];
                }
            }
        }
    }

    int lcm = 1;

    for ( int i = 0; i < numberOfPrimes; ++i)
    {
        lcm *= powerFunc(primeFactorsArray[i], findMaxPowerInColumn(primeFactorsArray, numberOfPrimes, i));
    }

    return lcm;
}

int main()
{
    //determine prime numbers until UPPER_LIMIT
    int sizePrimeNumberArray = UPPER_LIMIT; // assumption until UPPER_LIMIT only UPPER_LIMIT primes are
    int primeNumbersArray[sizePrimeNumberArray]; // oversized array

    //initialization of array to -1 values
    initBaseValuesPrimeNumbersArray(primeNumbersArray, sizePrimeNumberArray);
    int numberOfPrimes = intitPrimeNumbers(primeNumbersArray, sizePrimeNumberArray);

    //working array
    int numberOfRowsPrimeFactors = 1+(UPPER_LIMIT-LOWER_LIMIT+1); //first line: primes; other lines the numbers in increasing order
    int primeFactorsArray[numberOfRowsPrimeFactors*numberOfPrimes];
    initBaseValuesPrimeFactorsArray(primeFactorsArray, numberOfRowsPrimeFactors, numberOfPrimes, primeNumbersArray);

    //Least common multiple
    int lcm = leastCommonMultFunc(primeFactorsArray, numberOfRowsPrimeFactors, numberOfPrimes);

    printf("%d\n", lcm);

    return 0;
}
/*
1 -> 1
2 -> 2
3 -> 3
4 -> 2 * 2
5 -> 5
6 -> 2 * 3
7 -> 7
8 -> 2 * 2 * 2
9 -> 3 * 3
10 -> 2 * 5
11 -> 11
12 -> 2 * 2 * 3
13 -> 13
14 -> 2 * 7
15 -> 3 * 5
16 -> 2 * 2 * 2 * 2
17 -> 17
18 -> 2 * 3 * 3
19 -> 19
20 - > 2 * 2 * 5

For each base the highest factor is needed.
*/