#include <stdio.h>

#define LOWER_LIMIT 1
#define UPPER_LIMIT 100

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

int main()
{

    int sumOfSquares = 0;
    for(int i = LOWER_LIMIT; i <= UPPER_LIMIT; ++i)
    {
        sumOfSquares += powerFunc(i, 2);
    }

    int sumOfNumbers = (int) ((((float) LOWER_LIMIT+UPPER_LIMIT)/2)*(UPPER_LIMIT-LOWER_LIMIT+1));
    int squareOfSums = powerFunc(sumOfNumbers, 2);

    printf("%d\n", squareOfSums-sumOfSquares);

    return 0;
}