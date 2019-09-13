# ==================================================
# Problem   :   1205C - Palindromic Paths
# Run time  :   0.202 sec.
# Language  :   Python 3.7.2
# ==================================================


import sys


def ask(x1, y1, x2, y2):
    print(f'? {x1} {y1} {x2} {y2}')
    inp = int(input())
    sys.stdout.flush()
    return inp


def main():
    # sys.stdin = open("in.txt", "r")
    # sys.stdout = open("out.txt", "w")

    # it = iter(map(int, sys.stdin.read().split()))

    n = int(input())
    grid = [[None]*(n+1) for _ in range(n+1)]

    grid[1][1] = 1
    grid[n][n] = 0
    grid[1][3] = ask(1, 1, 1, 3)    # 1 if ask(1, 1, 1, 3) == 1 else 0
    grid[2][2] = ask(1, 1, 2, 2)

    # Assume grid[1][2] = 1
    grid[1][2] = 1
    grid[2][3] = ask(1, 2, 2, 3)
    grid[2][1] = grid[2][3] if ask(2, 1, 2, 3) == 1 else (1 ^ grid[2][3])       # (1 ^ x) is to have the oppostive value of x

    # 1st and 2nd rows.
    for i in [1, 2]:
        for j in range(4, n+1):
            grid[i][j] = grid[i][j-2] if ask(i, j-2, i, j) == 1 else (1 ^ grid[i][j-2])

    # The remaining rows.
    for i in range(3, n+1):
        for j in range(1, n+1):
            if i == n and j == n:
                continue
            grid[i][j] = grid[i-2][j] if ask(i-2, j, i, j) == 1 else (1 ^ grid[i-2][j])

    # Justify assumption.
    assumption_ok = True

    for i in range(1, n):   # from 1 to n-1
        to_break = False
        for j in range(1, n-1):     # from 1 to n-2
            if grid[i][j] != grid[i+1][j+2] and (grid[i][j+1] != grid[i][j+2] or grid[i][j+1] != grid[i+1][j+1] or grid[i+1][j] != grid[i+1][j+1]):
                # No palindrom from grid[i][j] to grid[i+1][j+2]
                if ask(i, j, i+1, j+2) == 1:    # But that's a palindrom
                    assumption_ok = False
                to_break = True
                break
            elif grid[i][j] == grid[i+1][j+2] and (grid[i][j+1] == grid[i][j+2] or grid[i][j+1] == grid[i+1][j+1] or grid[i+1][j] == grid[i+1][j+1]):
                # Got palindrom from grid[i][j] to grid[i+1][j+2]
                if ask(i, j, i+1, j+2) == 0:    # But that's not a palindrom
                    assumption_ok = False   # Assumption grid[1][2] = 1 is wrong.
                to_break = True
                break
        if to_break:
            break

    if not assumption_ok:
        for i in range(1, n+1):
            for j in range(2 if (i & 1) == 1 else 1, n+1, 2):
                grid[i][j] ^= 1     # Reverse grid[i][j]

    # Print asnwer.
    ansL = ['!\n']
    for row in grid[1:]:
        ansL += [str(row_elem) for row_elem in row[1:]]
        ansL.append('\n')

    sys.stdout.write(''.join(ansL))


if __name__ == '__main__':
    main()
