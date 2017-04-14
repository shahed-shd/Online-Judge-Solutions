// ==================================================
// Round    :   Google Code Jam 2017 - Qualification Round
// Problem  :   A. Oversized Pancake Flipper
// Size     :   Small, Large
// Point    :   5 + 10
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define     offset(x)       (x & (-x))

const int MAXN = 1000 + 3;

int len;
int bit_tree[MAXN];

void bit_update(int idx, int val)
{
    while(idx <= len) {
        bit_tree[idx] += val;
        idx += offset(idx);
    }
}

int bit_query(int idx)
{
    int sum = 0;

    while(idx > 0) {
        sum += bit_tree[idx];
        idx -= offset(idx);
    }

    return sum;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        char s[MAXN];
        int k;

        scanf("%s %d", s+1, &k);

        len = strlen(s+1);
        int upto = len - k + 1;

        int flipCnt = 0;
        fill(bit_tree, bit_tree+MAXN, 0);

        for(int i = 1; i <= upto; ++i) {
            if((s[i] == '-' and !(bit_query(i) & 1)) or (s[i] == '+' and (bit_query(i) & 1))) {
                ++flipCnt;
                bit_update(i, 1);
                bit_update(i+k, -1);
            }
        }

        bool isPossible = true;

        for(int i = upto+1; i <= len; ++i) {
            if((s[i] == '-' and !(bit_query(i) & 1)) or (s[i] == '+' and (bit_query(i) & 1))) {
                isPossible = false;
                break;
            }
        }

        if(isPossible)
            printf("Case #%d: %d\n", tc, flipCnt);
        else
            printf("Case #%d: IMPOSSIBLE\n", tc);
    }

    return 0;
}
