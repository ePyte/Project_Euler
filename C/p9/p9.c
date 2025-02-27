#include <stdio.h>

#define sumOfThree 1000

int main()
{
    for(int a = 1; a <= sumOfThree-2; ++a){
        for(int b = a + 1; b <= sumOfThree-1; ++b){
            for(int c = b + 1; c <= sumOfThree; ++c)
            {
                if(a + b + c == sumOfThree){
                    if(a * a + b * b == c * c){
                        printf("a: %d\n", a);
                        printf("b: %d\n", b);
                        printf("c: %d\n", c);
                        printf("abc: %d\n", a*b*c);
                    }
                }
            }
        }
    }

    return 0;
}