
# ==================================================
# Problem  :   12289 - One-Two-Three
# Run time :   0.010 sec.
# Language :   Python 3.5
# ==================================================


def is_almost_same(a, b):
    if len(a) != len(b):
        return False

    cnt = 0

    for x, y in zip(a, b):
        if x != y:
            cnt += 1

    return cnt <= 1


def main():
    from sys import stdin, stdout

    # stdin = open("in.txt", "r")

    it = iter(stdin.read().split())

    n = int(next(it))
    ans = []

    for _ in range(n):
        word = next(it)
        if is_almost_same("one", word):
            ans.append("1\n")
        elif is_almost_same("two", word):
            ans.append("2\n")
        else:
            ans.append("3\n")

    stdout.write(''.join(ans))


if __name__ == '__main__':
    main()
