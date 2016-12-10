# ==================================================
# Problem	  :	10323 - Factorial! You Must be Kidding!!!
# Run time	:	0.040 sec.
# Language	:	Python 3.5
# ==================================================

def main():
	from sys import stdin, stdout
	from math import factorial

	# stdin = open("in.txt", "r")

	mp = map(int, stdin.read().split())
	
	f = [0] * 14
	f[8] = factorial(8)

	for x in range(9, 14):
		f[x] = x * f[x-1]
	
	ans = []

	for n in mp:
		if n < 0:
			if (-n) & 1:
				ans.append("Overflow!")
			else:
				ans.append("Underflow!")
		elif n < 8:
			ans.append("Underflow!")
		elif n <= 13:
			ans.append(str(f[n]))
		else:
			ans.append("Overflow!")

		ans.append("\n")

	stdout.write(''.join(ans))


if __name__ == '__main__':
	main()
