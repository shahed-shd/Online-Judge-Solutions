# ==================================================
# Problem	:	686 - Goldbach's Conjecture (II)
# Run time  :	0.020 sec.
# Language	:	Python 3.5
# ==================================================


import math
import sys


def sieve(MAXN, isPrime, primes):
    for i in range(0, MAXN, 2):
        isPrime[i] = False

    isPrime[2] = True
    isPrime[1] = False

    rt = int(math.sqrt(MAXN))

    for i in range(3, rt+1, 2):
        if isPrime[i]:
            for j in range(i*i, MAXN, 2*i):
                isPrime[j] = False

    primes.append(2)

    for i in range(3, MAXN, 2):
        if isPrime[i]:
            primes.append(i)


def main():
    # sys.stdin = open("in.txt", "r")
    # sys.stdout = open("out.txt", "w")

    MAXN = (1 << 15) + 3
    isPrime = [True] * MAXN
    primes = []

    sieve(MAXN, isPrime, primes)

    it = iter(map(int, sys.stdin.read().split()))
    ans = []

    for n in it:
        if n == 0: break

        cnt = 0

        for x in primes:
            y = n - x
            if x <= y:
                if isPrime[y]: cnt += 1
            else:
                break

        ans.append(str(cnt))
        ans.append('\n')

    sys.stdout.write(''.join(ans))


if __name__ == '__main__':
    main()
