# ==================================================
# Problem   :	Merge the Tools!
# Score		:	40 /40
# Language  :   Python 3
# ==================================================


def merge_the_tools(string, k):
    from sys import stdout
    from collections import OrderedDict
    
    ansL = []

    for i in range(0, len(string), k):
        ss = string[i:i+k]
        sss = ''.join(OrderedDict.fromkeys(ss).keys())
        ansL.append(sss)
        ansL.append('\n')

    stdout.write(''.join(ansL))


if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)
