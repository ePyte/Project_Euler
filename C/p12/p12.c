#include <stdio.h>

#define FIRSTLIMIT 500

 //only returns whole numbers
 //if the number is not square, the "roof" will be returned: e.g.:10 -> 4
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

int isFirstSearchedTriangularNumb(int a)
{
    int divisorCounter = 0;
    int sqrta = sqrtFuncForInt(a);
    for(int i = 1; i<=sqrta; ++i)
    {
        if(a % i == 0)
        {
            divisorCounter++;
        }
    }

    if(sqrta*sqrta == a)// a is square number
    {
        divisorCounter = 2*divisorCounter-1;
    }
    else
    {
        divisorCounter *=2;
    }

    if(divisorCounter>=FIRSTLIMIT)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
square numbers have odd number of divisors
other numbers have even number of divisors
*/

int main()
{
    int number = 1;
    int triangNumb = number;
    int counter = 0;
    while(isFirstSearchedTriangularNumb(triangNumb) != 1)
    {
        ++number;
        triangNumb += number;
    }

    printf("%d\n", triangNumb);
    
    return 1;
}