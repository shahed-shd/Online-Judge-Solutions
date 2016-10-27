def main():
	from sys import stdin, stdout

	# stdin = open("input.txt", "r")

	n = int(stdin.read())

	f = n

	for x in range(1, n):
		f *= x

	stdout.write(str(f) + '\n')
	

if __name__ == '__main__':
	main()
