#ifndef HORIZONVERTMUL_H
#define HORIZONVERTMUL_H

int rowMaxMul(int intArray[])
{
    int rowMaxMulValue = 0;
    int rowMul = 1;
    for (int i = 0; i < NUMBEROFROWS; ++i)
    {
        for(int j = 0; j < NUMBEROFCOLS-NUMBEROFMUL+1; ++j)
        {
            for(int h = 0; h < NUMBEROFMUL; ++h)
            {
                rowMul *= intArray[i*NUMBEROFCOLS+j+h];
                if(rowMul>rowMaxMulValue)
                {
                    rowMaxMulValue = rowMul;
                }
            }
            rowMul = 1;
        }
    }
    return rowMaxMulValue;
}

int colMaxMul(int intArray[])
{
    int colMaxMulValue = 0;
    int colMul = 1;
    for (int i = 0; i < NUMBEROFCOLS; ++i)
    {
        for(int j = 0; j < NUMBEROFROWS-NUMBEROFMUL+1; ++j)
        {
            for(int h = 0; h < NUMBEROFMUL; ++h)
            {
                colMul *= intArray[i*NUMBEROFROWS+j+h];
                if(colMul>colMaxMulValue)
                {
                    colMaxMulValue = colMul;
                }
            }
            colMul = 1;
        }
    }
    return colMaxMulValue;
}

#endif