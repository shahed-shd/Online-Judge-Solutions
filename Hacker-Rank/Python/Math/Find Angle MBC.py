# ==================================================
# Problem   :   Find Angle MBC
# Score     :   10 /10
# Language  :   Python 3
# ==================================================


import math


def main():
    from sys import stdin, stdout

    # stdin = open("in.txt", "r")
    it = iter(map(int, stdin.read().split()))

    ab = next(it)
    bc = next(it)

    theta = math.atan2(ab, bc) # angle ACB = angle CBM
    theta_degree = math.degrees(theta)

    ans = math.floor(theta_degree + 0.5)

    stdout.write(str(ans) + '°\n')


if __name__ == '__main__':
    main()
