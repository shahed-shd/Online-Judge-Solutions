# ==================================================
# Problem  :   11462 - Age Sort
# Run time :   1.380 sec.
# Language :   Python 3.5
# ==================================================

def main():
	from sys import stdin, stdout

	# stdin = open("input.txt", "r")
	
	nextInt = iter(map(int, stdin.read().split())).__next__
	ans = []

	while True:
		n = nextInt()
		if not n: break

		seq = [nextInt() for i in range(n)]
		seq.sort()

		seq = map(str, seq);

		ans.append(' '.join(seq))
		ans.append('\n')
	
	stdout.write(''.join(ans))

if __name__ == '__main__':
	main()
