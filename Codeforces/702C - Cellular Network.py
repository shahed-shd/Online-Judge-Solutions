# ==================================================
# Problem  :   702C - Cellular Network
# Run time :   0.264 sec.
# Language :   Python 3
# ==================================================

def main():
	from sys import stdin, stdout
	
	inp = stdin.read().split()

	n = int(inp.pop(0))
	m = int(inp.pop(0))

	cities = [int(x) for x in inp[0:n]]	
	towers = [int(x) for x in inp[n:(n+m)]]

	j, ans = 0, 0

	for ct in cities:
		while j+1 < m and abs(ct - towers[j]) >= abs(ct - towers[j+1]):
			j += 1
		ans = max(ans, abs(ct - towers[j]))

	stdout.write(str(ans) + '\n')

if __name__ == '__main__':
	main()
