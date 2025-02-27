#ifndef OPERATIONSHEADER_H
#define OPERATIONSHEADER_H

void quickCheckWithArray(chainInfoStr* workingChainInfoStr, int helperArray[])
{
    if(workingChainInfoStr->numberWithchainLength <= MAXLIMIT)
    {
        if(helperArray[workingChainInfoStr->numberWithchainLength-1] != -1)
        {
            workingChainInfoStr->chainLength += (helperArray[workingChainInfoStr->numberWithchainLength-1]-1); //-1 is necessary, as the while cycle in checkCollatz has ++
            workingChainInfoStr->numberWithchainLength = 1;
        }
    }
}

void addElementToArray(int index, chainInfoStr* workingChainInfoStr, int helperArray[])
{
    if(helperArray[index-1] == -1)
    {
        helperArray[index-1]=workingChainInfoStr->chainLength;
    }
}


void getMax(int index, chainInfoStr* workingChainInfoStr, chainInfoStr* maxChainInfoStr)
{
        if(workingChainInfoStr->chainLength > maxChainInfoStr->chainLength)
        {
            maxChainInfoStr->chainLength = workingChainInfoStr->chainLength;
            maxChainInfoStr->numberWithchainLength = (long long)index;
        }
}

void cycleCollatz(chainInfoStr* workingChainInfoStr, int helperArray[])
{
    while(workingChainInfoStr->numberWithchainLength!=1)
    {
        if(workingChainInfoStr->numberWithchainLength % 2 == 0)
        {
            workingChainInfoStr->numberWithchainLength /= 2;
        }
        else
        {
            workingChainInfoStr->numberWithchainLength *= 3;
            ++workingChainInfoStr->numberWithchainLength;
        }
        ++(workingChainInfoStr->chainLength);

        quickCheckWithArray(workingChainInfoStr, helperArray);

    }
}

void checkCollatz(int index, chainInfoStr* maxChainInfoStr, int helperArray[])
{
    chainInfoStr* workingChainInfoStr = (chainInfoStr*)malloc(sizeof(chainInfoStr));

    if ( workingChainInfoStr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }

    workingChainInfoStr->chainLength = 1;
    workingChainInfoStr->numberWithchainLength = index;

    cycleCollatz(workingChainInfoStr, helperArray);

    addElementToArray(index, workingChainInfoStr, helperArray);

    getMax(index, workingChainInfoStr, maxChainInfoStr);

    free(workingChainInfoStr);
}

void initHelperArray(int helperArray[])//(index+1) the number which is checked; the value is the number of steps
{
    for(int i = 0; i < MAXLIMIT; ++i)
    {
        helperArray[i] = -1;
    }
}

#endif