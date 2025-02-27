#ifndef DIAGONALMUL_H
#define DIAGONALMUL_H



int topLeftMaxMul(int intArray[])
{
    int topLeftMaxMulVal = 0;
    int topLeftMul = 1;
    for (int i = 0; i < NUMBEROFCOLS-NUMBEROFMUL+1; ++i)
    {
        for(int j = 0; j < NUMBEROFROWS-NUMBEROFMUL+1; ++j)
        {
            for(int h = 0; h < NUMBEROFMUL; ++h)
            {
                topLeftMul *= intArray[(i+h)*NUMBEROFROWS+j+h];
                if(topLeftMul>topLeftMaxMulVal)
                {
                    topLeftMaxMulVal = topLeftMul;
                }
            }
            topLeftMul = 1;
        }
    }
    return topLeftMaxMulVal;
}

int bottomLeftMaxMul(int intArray[])
{
    int bottomLeftMaxMulVal = 0;
    int bottomLeftMul = 1;
    for (int i = NUMBEROFROWS-1; i >= NUMBEROFMUL-1; --i)
    {
        for(int j = 0; j < NUMBEROFCOLS-NUMBEROFMUL+1; ++j)
        {
            for(int h = 0; h < NUMBEROFMUL; ++h)
            {
                bottomLeftMul *= intArray[(i-h)*NUMBEROFROWS+j+h];
                if(bottomLeftMul>bottomLeftMaxMulVal)
                {
                    bottomLeftMaxMulVal = bottomLeftMul;
                }
            }
            bottomLeftMul = 1;
        }
    }
    return bottomLeftMaxMulVal;
}

int topRightMaxMul(int intArray[])
{
    int topRightMaxMulVal = 0;
    int topRightMul = 1;
    for (int i = 0; i < NUMBEROFROWS-NUMBEROFMUL+1; ++i)
    {
        for(int j = NUMBEROFCOLS-1; j >= NUMBEROFMUL-1; --j)
        {
            for(int h = 0; h < NUMBEROFMUL; ++h)
            {
                topRightMul *= intArray[(i+h)*NUMBEROFROWS+j-h];
                if(topRightMul>topRightMaxMulVal)
                {
                    topRightMaxMulVal = topRightMul;
                }
            }
            topRightMul = 1;
        }
    }
    return topRightMaxMulVal;
}

int bottomRightMaxMul(int intArray[])
{
    int bottomRightMaxMulVal = 0;
    int bottomRightMul = 1;
    for (int i = NUMBEROFROWS-1; i > NUMBEROFMUL-1; --i)
    {
        for(int j = NUMBEROFCOLS-1; j >= NUMBEROFMUL-1; --j)
        {
            for(int h = 0; h < NUMBEROFMUL; ++h)
            {
                bottomRightMul *= intArray[(i-h)*NUMBEROFROWS+j-h];
                if(bottomRightMul>bottomRightMaxMulVal)
                {
                    bottomRightMaxMulVal = bottomRightMul;
                }
            }
            bottomRightMul = 1;
        }
    }
    return bottomRightMaxMulVal;
}

int diagMaxMul(int intArray[])
{
    int topLeftMax = topLeftMaxMul(intArray);
    int bottomLeftMax = bottomLeftMaxMul(intArray);
    int topRightMax = topRightMaxMul(intArray);
    int bottomRightMax = bottomRightMaxMul(intArray);
    return maxFunc(maxFunc(maxFunc(topLeftMax, bottomLeftMax), topRightMax), bottomRightMax);


}

#endif