// ==================================================
// Problem  :   1269 - Consecutive Sum
// Run time :   0.296 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXV = 50000 * 31 + 3;
const int ALPHABET = 2;             // 0, 1

int nxt[MAXV][ALPHABET];
int trieSize;

inline bool bitcheck(int n, int pos) { return ((n >> pos) & 1); }

inline void reset_row(int v)
{
    nxt[v][0] = nxt[v][1] = 0;
}

void trie_insert(int mask)
{
    int v = 0;

    for(int i = 31; i >= 0; --i) {
        int &rf = nxt[v][bitcheck(mask, i)];
        if(rf == 0) {
            rf = ++trieSize;
            reset_row(trieSize);
        }
        v = rf;
    }
}

void get_min_max(int mask, int &mmin, int &mmax)
{
    mmin = mmax = 0;
    int v1 = 0, v2 = 0;

    for(int i = 31; i >= 0; --i) {
        bool bit = bitcheck(mask, i);

        int &rf1 = nxt[v1][bit];
        int &rf2 = nxt[v2][!bit];

        if(rf1 == 0) {
            mmin = (mmin << 1) | 1;
            v1 = nxt[v1][!bit];
        }
        else {
            mmin <<= 1;
            v1 = rf1;
        }

        if(rf2 == 0) {
            mmax <<= 1;
            v2 = nxt[v2][bit];
        }
        else {
            mmax = (mmax << 1) | 1;
            v2 = rf2;
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        reset_row(0);
        trieSize = 0;
        int val, curr = 0, mn = INT_MAX, mx = INT_MIN;
        trie_insert(curr);

        while(n--) {
            scanf("%d", &val);
            curr ^= val;

            int currMin, currMax;
            get_min_max(curr, currMin, currMax);

            mn = min(mn, currMin);
            mx = max(mx, currMax);

            trie_insert(curr);
        }

        printf("Case %d: %d %d\n", tc, mx, mn);
    }

    return 0;
}
