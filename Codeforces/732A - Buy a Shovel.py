# ==================================================
# Problem  :   732A - Buy a Shovel
# Run time :   0.077 sec.
# Language :   Python 3.5
# ==================================================

def main():
	from sys import stdin, stdout

	# stdin = open("input.txt", "r")

	k, r = tuple(map(int, stdin.read().split()))

	n = 0
	ans = int()

	while True:
		if n != 0 and (10*n) % k == 0:
			ans = (10 * n) // k
			break
		if (10 * n + r) % k == 0:
			ans = (10 * n + r) // k
			break
		n += 1

	stdout.write(str(ans) + '\n')

if __name__ == '__main__':
	main()
