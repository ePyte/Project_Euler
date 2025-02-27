#include <stdio.h>

#define MAXLIMIT 1000

#include "enumMainNumbers.h"
#include "exchangeHeader.h"
#include "operationsHeader.h"


int main()
{
    int sum = addTogetherNumbers();
    printf("%d\n", sum);

    return 1;
}

