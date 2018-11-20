# ==================================================
# Problem   :   1077E - Thematic Contests
# Run time  :   0.311 sec.
# Language  :   Python 3.6
# ==================================================


from collections import Counter


def main():
    from sys import stdin, stdout

    # stdin = open("in.txt", "r")
    it = iter(map(int, stdin.read().split()))

    n = next(it)
    topic_list = [next(it) for _ in range(n)]

    cnt_list = sorted(Counter(topic_list).values())
    mx_val = cnt_list[-1]
    res = 0

    for curr_val in range(1, mx_val+1):
        curr_res = curr_val
        idx = len(cnt_list) - 1

        while curr_val % 2 == 0 and idx > 0:
            curr_val //= 2
            idx -= 1
            if cnt_list[idx] < curr_val:
                break
            curr_res += curr_val

        res = max(res, curr_res)

    stdout.write(str(res))


if __name__ == '__main__':
    main()
