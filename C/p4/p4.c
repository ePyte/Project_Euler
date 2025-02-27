#include <stdio.h>
#include <stdlib.h>

#define STARTING_NUMBER 100
#define ENDING_NUMBER 999

int lengthCalc(int inputNumber)
{
    int length = 0;
    if (inputNumber <= 0)
    {
        printf("Error: number is below 1.");
        exit(1);
    }
    while(inputNumber>0)
    {
        inputNumber /= 10;
        ++length;
    }

    return length;
}

int isPalindrome(int inputNumber)
{
    int lengthOfNumber = lengthCalc(inputNumber);

    int holdingDigits[lengthOfNumber];

    for (int i = 0; i < lengthOfNumber; ++i)
    {
        holdingDigits[i] = 0;
    }

    for(int i = 0; i < lengthOfNumber; ++i)
    {
        holdingDigits[i] = inputNumber % 10;
        inputNumber /= 10;
    }

    for(int i = 0; i < lengthOfNumber / 2; ++i)
    {
        if(holdingDigits[i] != holdingDigits[lengthOfNumber-1-i])
        {
            return 1; //false
        }
    }

    return 0; // true
}

int main()
{
    int largestPalindrome = -1;

    for (int i = STARTING_NUMBER; i <= ENDING_NUMBER; ++i)
    {
        for(int j = i; j <= ENDING_NUMBER; ++j) //multiplication is commutative
        {
            if(isPalindrome(i * j) == 0)
            {
                if(i*j > largestPalindrome)
                {
                    largestPalindrome = i*j;
                }
            }
        }
    }

    printf("%d\n", largestPalindrome);

    return 0;
}