# ==================================================
# Problem  :   11799 - Horror Dash
# Run time :   0.010 sec.
# Language :   Python 3
# ==================================================

def main():
	from sys import stdin, stdout

	# stdin = open('input.txt', 'r')

	inp = [int(x) for x in stdin.read().split()]

	t = inp.pop(0)
	a, b = 0, 0

	for tc in range(1, t+1):
		n = inp[a]

		a += 1
		b = a + n
		ans = max(inp[a:b])
		a = b

		stdout.write("Case %d: %d\n" % (tc, ans))

if __name__ == '__main__':
	main()
