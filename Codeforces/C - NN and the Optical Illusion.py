# ==================================================
# Problem   :   C - NN and the Optical Illusion
# Run time  :   0.109 sec.
# Language  :   Python 3.7.2
# ==================================================


import sys
import math


def main():
    # sys.stdin = open("in.txt", "r")
    # sys.stdout = open("out.txt", "w")

    it = iter(map(float, sys.stdin.read().split()))

    n = next(it)
    r = next(it)

    A = 2 * math.pi / n
    B = (math.pi - A) / 2

    K = math.sin(B) / math.sin(A)

    x = r / (2*K - 1)

    sys.stdout.write('%.7f' % x)


if __name__ == '__main__':
    main()
