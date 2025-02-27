#include <stdio.h>

#define SMALLER_NUMBER 1 //Fibonacci, therefore it is odd.
#define UPPER_LIMIT 4000000

int main()
{
    int smallerNum = SMALLER_NUMBER;
    int biggerNum = 2;
    int sumOfEvens = 0;


    while (biggerNum < UPPER_LIMIT)
    {
        if (biggerNum % 2 == 0)
        {
            sumOfEvens += biggerNum;
        }

    int newTerm = smallerNum + biggerNum;
    smallerNum = biggerNum;
    biggerNum = newTerm;
    }

    printf("%d\n", sumOfEvens);

    return 0;
}