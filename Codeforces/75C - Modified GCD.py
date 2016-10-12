# ==================================================
# Problem  :   75C - Modified GCD
# Run time :   0.186 sec.
# Language :   Python 3.5
# ==================================================


def gcd(m, n):
	while n != 0:
		t = m % n
		m = n
		n = t

	return m


def get_divisors(g):
	from math import sqrt
	
	rt = int(sqrt(g))
	divisors = []

	for x in range(1, rt+1):
		if g % x == 0:
			divisors.append(x)
			divisors.append(g // x)

	if divisors[-1] ==  divisors[-2]:
		divisors.pop()

	divisors.sort()

	return divisors


def main():
	from sys import stdin, stdout
	from bisect import bisect_right

	# stdin = open("input.txt", "r")

	it = iter(map(int, stdin.read().split()))

	a, b = next(it), next(it)
	divisors = get_divisors(gcd(a, b))

	n = next(it)
	ans = []

	for _ in range(n):
		low, high = next(it), next(it)
		
		idx = bisect_right(divisors, high)
		d = divisors[idx-1]

		ans.append(str(d if low <= d <= high else -1))
		ans.append('\n')

	stdout.write(''.join(ans))


if __name__ == '__main__':
	main()
