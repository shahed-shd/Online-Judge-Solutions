# ==================================================
# Problem   :   545D - Queue
# Run time  :   0.156 sec.
# Language  :   Python 3
# ==================================================


def main():
    from sys import stdin, stdout

   #  stdin = open("in.txt", "r")

    it = iter(map(int, stdin.read().split()))

    n = next(it)
    neededTime = []

    for _ in range(n):
        neededTime.append(next(it))

    neededTime.sort()

    cumTime = 0
    ans = 0
    i = 0

    while i < n:
        while i < n and neededTime[i] < cumTime:
            i += 1

        if i < n:
            ans += 1
            cumTime += neededTime[i]
            i += 1

    stdout.write(str(ans) + '\n')


if __name__ == '__main__':
    main()
