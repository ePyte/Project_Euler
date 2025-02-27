#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * resultArray = (int*)malloc(sizeof(int) * 4);

    if(resultArray == NULL)
    {
        printf("Memory allocation has failed.\n");
        return 0;
    }

    int * ptr = (int *)realloc(resultArray, 8 * sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory reallocation has failed.\n");
        exit(0);
    }
    
    resultArray = ptr;

    free(resultArray);
    return 1;
}