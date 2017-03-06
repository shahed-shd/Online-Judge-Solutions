# ==================================================
# Problem   :   682C - Alyona and the Tree
# Run time  :   0.405 sec.
# Language  :   Python 3
# ==================================================


from collections import deque
import sys


def bfs(n, adjList, a):
    q = deque()
    dist = [0] * (n+3)
    vis = [False] * (n+3)

    q.append(1)
    vis[1] = True
    cnt = 0

    while q:
        u = q.popleft()

        if a[u] < dist[u]:
            continue

        cnt += 1
        for (v, c) in adjList[u]:
            if not vis[v]:
                vis[v] = True
                dist[v] = max(dist[u]+c, 0)
                q.append(v)

    return cnt


def main():
    # sys.stdin = open("in.txt", "r")

    it = iter(map(int, sys.stdin.read().split()))

    n = next(it)

    a = [0] * (n+3)
    adjList = [[] for _ in range(n+3)]

    for i in range(1, n+1):
        a[i] = next(it)

    for i in range(1, n):
        p = next(it)
        c = next(it)
        adjList[i+1].append((p, c))
        adjList[p].append((i+1, c))

    ans = n - bfs(n, adjList, a)

    sys.stdout.write(str(ans) + '\n')


if __name__ == '__main__':
    main()
