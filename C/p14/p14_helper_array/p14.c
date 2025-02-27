//runtime: ~0.06s
#include <stdio.h>
#include <stdlib.h>

#define MAXLIMIT 1000000

struct chainInfo
{
    int chainLength;
    long long numberWithchainLength;
};

typedef struct chainInfo chainInfoStr;

#include "operationsHeader.h"

int main()
{
    chainInfoStr* maxChainInfoStr = (chainInfoStr*)malloc(sizeof(chainInfoStr));

    if ( maxChainInfoStr == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    maxChainInfoStr->chainLength = 0;
    maxChainInfoStr->numberWithchainLength = 0;

    int helperArray[MAXLIMIT];
    initHelperArray(helperArray);

    for(int i = 1; i < MAXLIMIT; ++i)
    {
        checkCollatz(i, maxChainInfoStr, helperArray);
    }

    printf("%lld\n", maxChainInfoStr->numberWithchainLength);

    free(maxChainInfoStr);
    return 1;
}