# ==================================================
# Problem	:	10920 - Spiral Tap
# Run time  :	0.030 sec.
# Language	:	Python 3.5
# ==================================================


import math
import sys


def main():
    # sys.stdin = open("in.txt", "r")
    # sys.stdout = open("out.txt", "w")

    it = map(int, sys.stdin.read().split())
    ans = []

    while True:
        sz = next(it)
        p = next(it)

        if sz == 0 and p == 0:
            break

        rt = math.ceil(math.sqrt(p))

        if not (rt & 1):
            rt += 1

        pp = rt * rt
        x = y = sz - (sz - rt) / 2

        if pp - p <= rt-1:
            y -= pp - p
        else:
            y -= rt - 1
            pp -= rt - 1

            if pp - p <= rt - 1:
                x -= pp - p
            else:
                x -= rt - 1
                pp -= rt - 1

                if pp - p <= rt - 1:
                    y += pp - p
                else:
                    y += rt - 1
                    pp -= rt - 1

                    x += pp - p

        ans.append("Line = %d, column = %d.\n" % (y, x))

    sys.stdout.write(''.join(ans))


if __name__ == '__main__':
    main()
