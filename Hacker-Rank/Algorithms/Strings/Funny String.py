# ==================================================
# Problem  :   Funny String
# Score    :   25 /25
# Language :   Python 3
# ==================================================


def main():
    from sys import stdin, stdout

    # stdin = open("in.txt", "r")
    # it = iter(map(int, stdin.read().split()))
    it = iter(stdin.read().split())
    ansL = []

    t = int(next(it))
    tc = 1

    while tc <= t:
        s = next(it)

        i, j = 0, len(s)-1
        is_funny = True

        while i < j:
            if abs(ord(s[i]) - ord(s[i+1])) != abs(ord(s[j]) - ord(s[j-1])):
                is_funny = False
                break

            i += 1
            j -= 1

        tc += 1
        ansL.append("Funny\n" if is_funny else "Not Funny\n")

    stdout.write(''.join(ansL))


if __name__ == '__main__':
main()
