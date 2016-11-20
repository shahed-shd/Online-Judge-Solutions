# ==================================================
# Problem   :	Prime Factors and their Powers
# Run time	:	0.077 sec.
# Language	:	Python 2.7
# ==================================================

import math

MAXN = 10000 + 3

def sieve():
	primes = [2]
	RT = int(math.sqrt(MAXN)) + 3
	status = [True] * RT

	rt = int(math.sqrt(RT)) + 3

	for i in xrange(3, rt, 2):
		if status[i]:
			primes.append(i)

			for j in xrange(i*i, RT, 2*i):
				status[j] = False

	for i in xrange(rt if (rt & 1) else rt+1, RT, 2):
		if status[i]:
			primes.append(i)

	return primes


def factorize(n, primes, ans):
	for p in primes:
		if n % p == 0:
			pw = 0
			while n % p == 0:
				pw += 1
				n /= p

			ans.append(str(p))
			ans.append(' ')
			ans.append(str(pw))
			ans.append(' ')

	if n != 1:
		ans.append(str(n))
		ans.append(' ')
		ans.append(str(1))
		ans.append(' ')


def main():
	from sys import stdin, stdout

	# stdin = open("input.txt", "r")

	primes = sieve()

	it = iter(map(int, stdin.read().split()))
	ans = []

	t = next(it)

	for _ in range(t):
		n = next(it)
		factorize(n, primes, ans)
		ans[-1] = '\n'

	stdout.write(''.join(ans))

if __name__ == '__main__':
	main()
