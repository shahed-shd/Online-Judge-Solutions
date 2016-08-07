# ==================================================
# Problem  :   158A - Next Round
# Run time :   0.154 sec.
# Language :   Python 3
# ==================================================

def main():
	from sys import stdin, stdout

	inp = [int(x) for x in stdin.read().split()]

	n = inp.pop(0)
	k = inp.pop(0)

	k_th = inp[k-1]
	cnt = 0

	for x in inp:
		if x and x >= k_th:
			cnt += 1;

	stdout.write(str(cnt) + '\n')

if __name__ == '__main__':
	main()
