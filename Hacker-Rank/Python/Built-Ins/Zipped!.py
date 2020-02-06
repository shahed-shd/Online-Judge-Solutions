# ==================================================
# Problem   :   Zipped!
# Score     :   10 /10
# Language  :   Python 3
# ==================================================


import sys
import statistics


def main():
    # sys.stdin = open("in.txt", "r")
    # sys.stdout = open("out.txt", "w")

    it = iter(map(float, sys.stdin.read().split()))

    n = int(next(it))
    x = int(next(it))

    all_mark_list = []

    for subj in range(x):
        all_mark_list.append(
            [next(it) for stu in range(n)]
        )

    ansL = [statistics.mean(tup) for tup in zip(*all_mark_list)]

    sys.stdout.write('\n'.join(map(str, ansL)))


if __name__ == '__main__':
    main()
