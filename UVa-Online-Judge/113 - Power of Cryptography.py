import math

def main():
	from sys import stdin, stdout

	# stdin = open('input.txt', 'r')

	while True:
		try:
			n = int(stdin.readline())
			p = int(stdin.readline())
		except:
			break

		stdout.write(str(round(pow(p, 1/n))) + '\n')

if __name__ == '__main__':
	main()
