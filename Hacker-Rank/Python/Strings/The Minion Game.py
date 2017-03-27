# ==================================================
# Problem	:	The Minion Game
# Score     :	40 /40
# Language	:	Python 3
# ==================================================


import sys


def main():
    # sys.stdin = open("in.txt", "r")

    s = sys.stdin.read().strip()
    len_s = len(s)
    kevin_score, stuart_score = 0, 0

    for i in range(len_s):
        if s[i] in "AEIOU":
            kevin_score += len_s - i
        else:
            stuart_score += len_s - i

    if kevin_score < stuart_score:
        sys.stdout.write("Stuart " + str(stuart_score) + '\n')
    elif kevin_score > stuart_score:
        sys.stdout.write("Kevin " + str(kevin_score) + '\n')
    else:
        sys.stdout.write("Draw")


if __name__ == '__main__':
    main()
