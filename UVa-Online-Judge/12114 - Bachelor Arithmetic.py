# ==================================================
# Problem   :   12114 - Bachelor Arithmetic
# Run time  :   0.020 sec.
# Language  :   Python 3.5
# ==================================================


def main():
    from sys import stdin, stdout

    # stdin = open("in.txt", "r")
    it = iter(map(int, stdin.read().split()))
    tc = 0

    ansL = []

    while True:
        b = next(it); s = next(it)

        if b == 0 and s == 0:
            break

        if b-1 == 0:
            ans = ":-\\"
        else:
            before = min(1, s / b)
            after = min(1, (s-1) / (b-1))

            if before < after:
                ans = ":-)"
            elif before > after:
                ans = ":-("
            else:
                ans = ":-|"

        tc += 1
        ansL.append("Case %d: %s\n" % (tc, ans))

    stdout.write(''.join(ansL))


if __name__ == '__main__':
    main()
