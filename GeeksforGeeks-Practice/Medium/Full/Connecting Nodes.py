# ==================================================
# Problem	:	Connecting Nodes
# Run time	:	0.202 sec.
# Language	:	Python 2.7
# ==================================================

def main():
	from sys import stdin, stdout

	# stdin = open("input.txt", "r")

	it = iter(map(int, stdin.read().split()))
	ans = []

	t = next(it)

	for _ in xrange(t):
		n = next(it)
		m = next(it)

		degreeCnt = [0] * (n+1)

		for _ in xrange(m):
			degreeCnt[next(it)] += 1
			degreeCnt[next(it)] += 1

		degNeeded = 0

		for i in xrange(1, n+1):
			if degreeCnt[i] & 1:
				degNeeded += 1
			elif degreeCnt[i] == 0:
				degNeeded += 2

		ans.append(str(degNeeded >> 1))   # degNeeded / 2
		ans.append('\n')

	stdout.write(''.join(ans))


if __name__ == '__main__':
	main()
