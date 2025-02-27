#include <stdio.h>

#define NUMOFROWS 100
#define NUMOFDIGITS 50
#define LENGHTOFSUM 150 //assumption each addition will add one digit to the number (worst case)
#define TENDIGITS 10

#include "initHeader.h"
#include "operationsHeader.h"
#include "inputUsingHeader.h"

int main()
{
    int sumArray[LENGHTOFSUM];
    initArrayFunc(sumArray, LENGHTOFSUM);
    long long firstTenDigits = firstTenDigitsFunc(sumArray, LENGHTOFSUM);

    printf("%lld\n", firstTenDigits);
    return 1;
}