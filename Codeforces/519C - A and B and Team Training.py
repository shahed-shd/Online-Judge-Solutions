# ==================================================
# Problem   :   519C - A and B and Team Training
# Run time  :   0.062 sec.
# Language  :   Python 3
# ==================================================


def main():
    from sys import stdin, stdout

    # stdin = open("in.txt", "r")

    it = iter(map(int, stdin.read().split()))

    n = next(it)
    m = next(it)

    mn = min(n, m)
    rem = n + m - 2 * mn

    if mn <= rem:
        ans = mn
    else:
        ans = rem
        tmp = mn - rem

        ans += ((tmp) // 3) * 2

        if tmp % 3 == 2:
            ans += 1

    stdout.write(str(ans) + '\n')


if __name__ == '__main__':
    main()
