# ==================================================
# Problem	:	466C - Number of Ways
# Run time  :	0.421 sec.
# Language	:	Python 3
# ==================================================


def main():
    from sys import stdin, stdout

    # stdin = open("in.txt", "r")

    it = iter(map(int, stdin.read().split()))

    n = next(it)
    cumSum = [0] * (n+3)

    for i in range(1, n+1):
        cumSum[i] = cumSum[i-1] + next(it)

    totSum = cumSum[n]

    if n < 3 or totSum % 3 != 0:
        ans = 0
    elif totSum == 0:
        zeroCnt = 0
        for x in cumSum[1:n+1]:
            if x == 0:
                zeroCnt += 1

        zeroCnt -= 2

        ans = int(zeroCnt * (zeroCnt+1) / 2) if zeroCnt > 0 else 0
    else:
        segSum = totSum // 3
        segSumTwice = segSum * 2
        cnt = 0
        ans = 0

        for i in range(1, n):
            if cumSum[i] == segSum:
                cnt += 1
            if cumSum[i] == segSumTwice:
                ans += cnt

    stdout.write(str(ans) + '\n')


if __name__ == '__main__':
    main()
