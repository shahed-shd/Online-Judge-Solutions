// ==================================================
// Problem  :   106C - Buns
// Run time :   0.030 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
#include <climits>
using namespace std;

const int MAXN = 1000+3;
const int MAXM = 10+3;

int n, m;
int ab[MAXM], c[MAXM], d[MAXM];
int memo[MAXM][MAXN];
bitset<MAXN> isCalc[MAXM];

int fn(int idx, int remDough)
{
    if(idx > m) {
        return 0;
    }

    if(isCalc[idx][remDough]) return memo[idx][remDough];

    int &ret = memo[idx][remDough] = 0;

    for(int i = 0; i <= ab[idx]; ++i) {
        int tmp = remDough - c[idx] * i;

        if(tmp >= 0) {
            ret = max(ret, i*d[idx] + fn(idx+1, tmp));
        }
    }

    isCalc[idx][remDough] = true;
    return ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int c0, d0;
    scanf("%d %d %d %d", &n, &m, &c0, &d0);

    ab[0] = n / c0, c[0] = c0, d[0] = d0;

    int ai, bi;

    for(int i = 1; i <= m; ++i) {
        scanf("%d %d %d %d", &ai, &bi, c+i, d+i);
        ab[i] = ai / bi;
    }

    printf("%d\n", fn(0, n));

    return 0;
}
