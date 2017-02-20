# ==================================================
# Problem	:	Ugly Numbers
# Run time  :	35 /35
# Language	:	Python 3
# ==================================================


def main():
    from sys import stdin, stdout

    #stdin = open("in.txt", "r")

    isUglyNum = [False, True, True, True, True, True]
    uglyNum = [0, 1, 2, 3, 4, 5]
    sz = 5
    num = 6
    isUgly = bool()

    while sz < 503:
        isUgly = False

        if num % 2 == 0:
            isUgly = isUglyNum[num//2]
        elif num % 3 == 0:
            isUgly = isUglyNum[num//3]
        elif num % 5 == 0:
            isUgly = isUglyNum[num//5]

        if isUgly:
            uglyNum.append(num)
            sz += 1

        isUglyNum.append(isUgly)
        num += 1

    # Preprocess complete.

    it = iter(map(int, stdin.read().split()))

    t = next(it)
    ans = []

    for _ in range(t):
        n = next(it)
        ans.append(str(uglyNum[n]))
        ans.append('\n')

    stdout.write(''.join(ans))


if __name__ == '__main__':
    main()
