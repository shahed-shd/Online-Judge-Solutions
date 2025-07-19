# ==================================================
# Problem   : BinaryGap
# Score     : 100
# Language  : Python 3.13
# ==================================================

def solution(N):
    max_gap = 0
    curr_gap = 0

    for digit in bin(N)[2:]:
        if digit == '1':
            max_gap = max(max_gap, curr_gap)
            curr_gap = 0
        else:
            curr_gap += 1
    
    return max_gap
