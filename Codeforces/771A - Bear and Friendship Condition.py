# ==================================================
# Problem	:	771A - Bear and Friendship Condition
# Run time  :	0.499 sec.
# Language	:	Python 3
# ==================================================


import sys
import collections


def bfs(u, adjList, vis):
    dq = collections.deque()

    dq.append(u)
    vis[u] = True
    edgeCnt = 0
    vertexCnt = 0

    while dq:
        u = dq.popleft()

        vertexCnt += 1
        edgeCnt += len(adjList[u])

        for v in adjList[u]:
            if not vis[v]:
                vis[v] = True
                dq.append(v)

    edgeCnt = edgeCnt // 2
    return bool(edgeCnt == ((vertexCnt * vertexCnt - vertexCnt) // 2))


def main():
    # sys.stdin = open("in.txt", "r")

    it = iter(map(int, sys.stdin.read().split()))

    n = next(it)
    m = next(it)

    adjList = [[] for _ in range(n+3)]

    for _ in range(m):
        u = next(it)
        v = next(it)
        adjList[u].append(v)
        adjList[v].append(u)

    vis = [False] * (n+3)

    for u in range(1, n+1):
        if not vis[u]:
            if not bfs(u, adjList, vis):
                sys.stdout.write("NO\n")
                return

    sys.stdout.write("YES\n")


if __name__ == '__main__':
    main()
