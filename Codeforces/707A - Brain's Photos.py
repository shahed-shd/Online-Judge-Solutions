# ==================================================
# Problem  :   707A - Brain's Photos
# Run time :   0.077 sec.
# Language :   Python 3.5
# ==================================================

from sys import stdin, stdout
from re import search

def main():
	# stdin = open('input.txt', 'r')

	stdout.write("#Color\n" if search('C|M|Y', stdin.read()) else "#Black&White\n")

if __name__ == '__main__':
	main()
