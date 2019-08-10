# ==================================================
# Problem   :   1198C - Matching vs Independent Set
# Run time  :   0.608 sec.
# Language  :   Python 3.7.2
# ==================================================


import sys


def main():
    # sys.stdin = open("in.txt", "r")
    # sys.stdout = open("out.txt", "w")

    it = iter(map(int, sys.stdin.read().split()))

    t = next(it)
    for _ in range(t):
        n = next(it)
        m = next(it)

        total_node = 3 * n
        is_node_covered = [False for _ in range(total_node+1)]
        is_edge_in_matching = [False for _ in range(m+1)]
        matching_edge_count = 0

        for i in range(1, m+1):
            u = next(it)
            v = next(it)

            if (not is_node_covered[u]) and (not is_node_covered[v]):
                is_node_covered[u] = is_node_covered[v] = True
                is_edge_in_matching[i] = True
                matching_edge_count += 1

        ansL = []
        if matching_edge_count >= n:
            ansL.append('Matching\n')
            edge_taken = 0
            for i in range(1, m+1):
                if is_edge_in_matching[i]:
                    ansL.append(str(i) + ' ')
                    edge_taken += 1
                    if edge_taken == n: break
        else:
            ansL.append('IndSet\n')
            node_taken = 0
            for i in range(1, total_node+1):
                if not is_node_covered[i]:
                    ansL.append(str(i) + ' ')
                    node_taken += 1
                    if node_taken == n: break

        ansL.append('\n')
        sys.stdout.write(''.join(ansL))


if __name__ == '__main__':
    main()
