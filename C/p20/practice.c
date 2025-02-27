#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int * number; //unknown memory address
    *number = 7;
    Segmentation fault
    */

/*
   int * number;
   int value = 7;
   number = &value;
   Correct.
   */
    printf("I.\n");
    int * ptrAr = (int*)malloc(4*sizeof(int));
    if(ptrAr == NULL)
    {
        printf("Error: memory allocation has failed.");
        return 0;
    }
    ptrAr[0] = 9;
    *(ptrAr+1) = 8;


    printf("ptrAr: %p\n", ptrAr);
    printf("&ptrAr: %p\n", &ptrAr);
    printf("*ptrAr: %d\n", *ptrAr);
    printf("\n\n");

    printf("II.\n");
    int array[5] = { 9, 8, 7, 6, 5};

    printf("array: %p\n", array);//first element
    printf("&array: %p\n", &array);//entire array
    printf("*array: %d\n", *array);

    printf("array+1: %p\n", array+1);
    printf("&array+1: %p\n", &array+1); //20 bytes but in 0x

    int * ptr1 = array;

    printf("ptr1: %p\n", ptr1);
    printf("ptr1+1: %p\n", ptr1+1);//4bytes diff
    printf("&ptr1: %p\n", &ptr1);
    printf("&ptr1+1: %p\n", &ptr1+1);//totally differnt
    printf("\n\n");
    free(ptrAr);


    printf("III.\n");
    int matrix[3][5] = 
    {
        {0,1,2,3,4},
        {5,6,7,8,9},
        {10,11,12,13,14}
    };


    printf("matrix:   %p\n", matrix);
    printf("matrix+1: %p\n", matrix+1);//20 bytes diff
    printf("&matrix:   %p\n", &matrix);
    printf("&matrix+1: %p\n", &matrix+1);//60 bytes diff

    printf("*(matrix[1]+1): %d\n", *(matrix[1]+1));// ->6

    printf("&matrix[1]: %p\n", &matrix[1]);
    printf("&matrix[1]+1: %p\n", &matrix[1]+1);//20 bytes diff
    //printf("*(&matrix[1]+1): %d\n", *(&matrix[1]+1));//error; refers to the 3rd line, but can give a pointer to there
    printf("**(&matrix[1]+1): %d\n", *(*(&matrix[1]+1)));//gives 10
    int* pointer = (int*)(&matrix[1]+1);//this works, but gives warning without cast
    printf("pointer: %p\n", pointer);
    printf("*pointer: %d\n", *pointer); //10

    int* pointer2 = (int*)&matrix[1]+1;//interesting
    printf("pointer2: %p\n", pointer2);
    printf("*pointer2: %d\n", *pointer2);//6
    return 1;
}