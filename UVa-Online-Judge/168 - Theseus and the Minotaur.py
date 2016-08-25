# ==================================================
# Problem  :   168 - Theseus and the Minotaur
# Run time :   1.640 sec.
# Language :   Python 3.5
# ==================================================

adjList = [[]]
k = 0
isLit = []
ans = []

def process_input(inp):
	if inp[0] == '#': exit()

	tunnels, minotaur_start, theseus_start, k = inp.split()
	
	ord_f = ord
	asciiA = ord_f('A')

	k = int(k)
	theseus_start = ord_f(theseus_start) - asciiA
	minotaur_start = ord_f(minotaur_start) - asciiA

	tunnels = tunnels[:-1].split(';')

	adjList = [[] for i in range(26)]

	for part in tunnels:
		u = ord_f(part[0]) - asciiA
		adjList[u] = [ord_f(x)-asciiA for x in part[2:]]

	return adjList, minotaur_start, theseus_start, k


def dfs(u, par, stepCnt):
	for v in adjList[u]:
		if v != par and isLit[v] == False:
			if stepCnt % k == 0:
				isLit[u] = True
				ans.append( "%s " % chr(u + ord('A')) )

			dfs(v, u, stepCnt+1)
			return

	ans.append( "/%s" % chr(u + ord('A')) )


def main():
	from sys import stdin, stdout

	# stdin = open('input.txt', 'r')

	while(True):
		global adjList, k, isLit, ans

		adjList, minotaur_start, theseus_start, k = process_input(stdin.readline())
		isLit = [False] * 26
		ans = []

		dfs(minotaur_start, theseus_start, 1)

		ans.append('\n')
		stdout.write(''.join(ans))

if __name__ == '__main__':
	main()
