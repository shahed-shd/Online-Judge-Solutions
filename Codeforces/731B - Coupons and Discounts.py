# ==================================================
# Problem  :   731B - Coupons and Discounts
# Run time :   0.186 sec.
# Language :   Python 3.5
# ==================================================

def main():
	from sys import stdin, stdout

	# stdin = open("input.txt", "r")

	it = iter((map(int, stdin.read().split())))

	n = next(it)
	offset = False

	for _ in range(n):
		ai = next(it)

		if offset and ai == 0: break

		if offset :
			ai += 1
			offset = False

		if ai & 1:			# If ai is odd.
			offset = True

	stdout.write("NO\n" if offset else "YES\n")

if __name__ == '__main__':
	main()
