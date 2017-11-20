# ==================================================
# Problem   :   894A - QAQ
# Run time  :   0.062 sec.
# Language  :   Python 3.6
# ==================================================


def main():
    from sys import stdin, stdout

    # stdin = open("in.txt", "r")
    # it = iter(map(int, stdin.read().split()))

    s = stdin.read()

    tot_q_cnt = s.count('Q')
    curr_q_cnt = 0
    ans = 0

    for x in s:
    	if x == 'A':
    		ans += curr_q_cnt * (tot_q_cnt - curr_q_cnt)
    	elif x == 'Q':
    		curr_q_cnt += 1

    stdout.write(str(ans) + '\n')


if __name__ == '__main__':
    main()
