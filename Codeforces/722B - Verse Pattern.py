# ==================================================
# Problem  :   722B - Verse Pattern
# Run time :   0.062 sec.
# Language :   Python 3.5
# ==================================================

def main():
	from sys import stdin, stdout

	# stdin = open("input.txt", "r")

	inp = stdin.readlines()

	n = int(inp[0])

	versePattern = iter(map(int, inp[1].split()))

	ans = True

	for line in inp[2:]:
		vowelCnt = 0

		for x in line:
			if x in "aeiouy":
				vowelCnt += 1
	
		if vowelCnt != next(versePattern):
			ans = False
			break

	stdout.write("YES\n" if ans else "NO\n")


if __name__ == '__main__':
	main()
