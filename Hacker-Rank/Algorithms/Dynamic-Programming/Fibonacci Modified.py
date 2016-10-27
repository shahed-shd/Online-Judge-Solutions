# ==================================================
# Problem	:	Fibonacci Modified
# Score		:	45 /45
# Language	:   Python 3
# ==================================================

def main():
	from sys import stdin, stdout

	# stdin = open("in.txt", "r")

	t1, t2, n = map(int, stdin.read().split())
	
	ti = int()

	for i in range(3, n+1):
		ti = t1 + t2 * t2
		t1 = t2
		t2 = ti

	stdout.write(str(ti) + '\n')


if __name__ == '__main__':
	main()
