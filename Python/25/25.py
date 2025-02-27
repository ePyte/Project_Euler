def fib(a,b):
    return a+b


numLen=0
firstNum = 1
secondNum = 1
index = 2

while(numLen<1000):
    newFib = fib(firstNum, secondNum)
    firstNum = secondNum
    secondNum = newFib
    index += 1
    numLen = len(str(newFib))

print(index)
