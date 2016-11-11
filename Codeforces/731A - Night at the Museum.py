# ==================================================
# Problem  :   731A - Night at the Museum
# Run time :   0.077 sec.
# Language :   Python 3.5
# ==================================================

def main():
	from sys import stdin, stdout

	# stdin = open("input.txt", "r")

	s = map(ord, stdin.read())

	res = 0
	curr = 0

	A = ord('a')
	Z = ord('z')

	for x in s:
		if A <= x <= Z:
			x -= A
			res += min(abs(x-curr), 26-abs(x-curr))
			curr = x;
		else:
			break

	stdout.write(str(res) + '\n')
	

if __name__ == '__main__':
	main()
