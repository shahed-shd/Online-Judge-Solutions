# ==================================================
# Problem  :   6C - Alice, Bob and Chocolate
# Run time :   0.248 sec.
# Language :   Python 3.5
# ==================================================


def main():
	from sys import stdin, stdout

	# stdin = open("input.txt", "r")

	n = int(stdin.readline())
	times = list(map(int, stdin.readline().split()))

	aliceSpend, bobSpend = 0, 0
	aliceCnt, bobCnt = 0, 0
	i, j = 0, n-1

	while(i <= j):
		if aliceSpend <= bobSpend:
			aliceSpend += times[i]
			aliceCnt += 1
			i += 1
		else:
			bobSpend += times[j]
			bobCnt += 1
			j -= 1

	stdout.write(''.join([str(aliceCnt), '\n', str(bobCnt), '\n']))


if __name__ == '__main__':
	main()
