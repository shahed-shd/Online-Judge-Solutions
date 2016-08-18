# ==================================================
# Problem  :   616A - Comparing Two Long Integers
# Run time :   0.077 sec.
# Language :   Python 3.5
# ==================================================

def main():
	from sys import stdin, stdout

	a = stdin.readline()
	b = stdin.readline()

	maxLen = max(len(a), len(b))

	a = a.zfill(maxLen)
	b = b.zfill(maxLen)

	stdout.write(('=\n', '>\n', '<\n')[(a > b) - (a < b)])

if __name__ == '__main__':
	main()
