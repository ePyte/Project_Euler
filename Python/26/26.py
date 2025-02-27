#Idea: Collect the remainders in a list. Once reoccurance happens count the index-difference between the same numbers.


def calcReoccur(col, rem):
    count= 1
    for i in reversed(col):
        if(i == rem):
            return count
        count += 1


def getRepLength(i):
    j = 1
    col = []
    rem = 0

    while (True):
        rem = j % i
        if rem == 0:
            return 0

        if(rem in col):
            return calcReoccur(col, rem)

        col.append(rem)

        j=rem*10


maxOccure = 0
numWithMax = 0

for i in range(1, 1000):
    if getRepLength(i) > maxOccure:
        maxOccure = getRepLength(i)
        numWithMax = i

#print(maxOccure)
print(numWithMax)


