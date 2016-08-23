# ==================================================
# Problem  :   10611 - The Playboy Chimp
# Run time :   0.170 sec.
# Language :   Python 3.5
# ==================================================

from sys import stdin, stdout

def binSearch(lst, sz, val):
	s, t = 0, sz-1

	while s <= t:
		mid = (s + t) // 2
		lst_mid = lst[mid]

		if lst_mid == val:
			return mid-1, mid+1
		if lst_mid < val:
			s = mid + 1
		else:
			t = mid - 1
	
	return t, s

def main():
	# stdin = open('input.txt', 'r')

	stdin.readline()

	mp = map(int, stdin.readline().split())

	chimps = []
	last = -1

	for x in mp:
		if x != last:
			chimps.append(x)	# Keeps only the unique elements.
			last = x

	stdin.readline()

	queries = map(int, stdin.readline().split())

	sz = len(chimps)
	ans = []

	for q in queries:
		a, b = binSearch(chimps, sz, q)

		ans.append(str(chimps[a]) if a >= 0 else 'X')
		ans.append(' ')
		ans.append(str(chimps[b]) if b < sz else 'X')
		ans.append('\n')

	stdout.write(''.join(ans))

if __name__ == '__main__':
	main()
