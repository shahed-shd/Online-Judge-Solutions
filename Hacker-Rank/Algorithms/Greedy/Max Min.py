# ==================================================
# Problem	:	Max Min
# Score		:	35 /35
# Language	:	Python 3
# ==================================================

def main():
	from sys import stdin, stdout

	# stdin = open("input.txt", "r")

	it = iter(map(int, stdin.read().split()))
	
	n = next(it)
	k = next(it)
	L = []

	for _ in range(n):
		L.append(next(it))
		
	L.sort()
	ans = int(1e9+3)		# as INF

	for i in range(k-1, n):
		ans = min(ans, L[i] - L[i-k+1])

	stdout.write(str(ans)+'\n')


if __name__ == '__main__':
	main()
