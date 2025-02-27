//runtime: ~0.29s
#include <stdio.h>
#include <stdlib.h>

#define MAXLIMIT 1000000

struct maxValues
{
    int maxChain;
    long long numberWithMaxChain;
};

typedef struct maxValues maxValStr;

void checkCollatz(int index, maxValStr* maxValues)
{

    int chain = 1;
    long long newNumber = index;


        while(newNumber!=1)
        {
            if(newNumber % 2 == 0)
            {
                newNumber /= 2;
            }
            else
            {
                newNumber *= 3;
                ++newNumber;
            }
            ++chain;
        }

        if(chain > maxValues->maxChain)
        {
            maxValues->maxChain = chain;
            maxValues->numberWithMaxChain = (long long)index;
        }
}

int main()
{
    maxValStr* maxValues = (maxValStr*)malloc(sizeof(maxValStr));

    if ( maxValues == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    maxValues->maxChain = 0;
    maxValues->numberWithMaxChain = 0;

    for(int i = 1; i < MAXLIMIT; ++i)
    {
        checkCollatz(i, maxValues);
    }

    printf("%lld\n", maxValues->numberWithMaxChain);

    free(maxValues);
    return 1;
}