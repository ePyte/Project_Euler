import math

def isPrime(p):
    p = abs(p)
    if p <=1:
        return False
    for i in range(2, int(math.sqrt(p))):
        if p % i == 0:
            return False
    return True


def calcConsecPrimes(a, b):
    calcNumOfPrimes=0
    for n in range(1000):
        if(isPrime(n*n+a*n+b)):
            calcNumOfPrimes += 1
        else:
            return calcNumOfPrimes
    return calcNumOfPrimes


aOpt=-1001
bOpt=-1001
maxConsecPrimes=0


for a in range(-999, 1000):
    print(a)
    for b in range(-1000, 1001):
        newValue = calcConsecPrimes(a, b)
        if newValue> maxConsecPrimes:
            aOpt = a
            bOpt = b
            maxConsecPrimes = newValue

print("a * b = product")
print(f"{aOpt} * {bOpt} = {aOpt*bOpt}")
print(f"Maximum number of consequitve primes: {maxConsecPrimes}")

#Runtime: 0m4.100s
# commands
# wsl
# time python3 27.py