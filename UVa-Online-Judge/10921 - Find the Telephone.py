# ==================================================
# Problem  :   10921 - Find the Telephone
# Run time :   0.010 sec.
# Language :   Python 3.5
# ==================================================

def main():
	from sys import stdin, stdout

	# stdin = open("in.txt", "r")

	inp = stdin.read()

	mapping = "22233344455566677778889999"
	ans = []
	
	f_ord = ord
	ASCII_A = f_ord('A')

	for x in inp:
		ans.append(mapping[f_ord(x) - ASCII_A] if 'A' <= x <= 'Z' else x)

	stdout.write(''.join(ans))


if __name__ == '__main__':
	main()
