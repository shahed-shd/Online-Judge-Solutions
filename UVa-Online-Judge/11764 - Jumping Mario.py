def main():
	from sys import stdin, stdout

	t = int(stdin.readline())
	tc = 1

	while tc <= t:
		stdin.readline()		# Just to skip, n is not necessary in this solution.
		walls = stdin.readline().split()
		
		prev = int(walls.pop(0))

		hiCnt, loCnt = 0, 0

		for h in walls:
			curr = int(h)

			if prev < curr: hiCnt += 1
			elif prev > curr: loCnt +=1

			prev = curr

		stdout.write("Case %d: %d %d\n" % (tc, hiCnt, loCnt))
		tc += 1

if __name__ == '__main__':
	main()
