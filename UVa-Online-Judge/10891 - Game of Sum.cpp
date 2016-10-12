// ==================================================
// Problem  :   10891 - Game of Sum
// Run time :   0.010 sec.
// Language :   C++11
// ===================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 100 + 3;

int numbers[MAXN];
int memo[MAXN][MAXN], tc = 0, memoCase[MAXN][MAXN] = {{0}};

int fn(int l, int r)
{
    if(l > r) return 0;
    if(memoCase[l][r] == tc) return memo[l][r];

    int sum = 0, &mxDiff = memo[l][r];
    mxDiff = INT_MIN;

    for(int i = l; i <= r; ++i) {
        sum += numbers[i];
        mxDiff = max(mxDiff, sum - fn(i+1, r));
    }

    sum = 0;

    for(int i = r; i >= l; --i) {
        sum += numbers[i];
        mxDiff = max(mxDiff, sum - fn(l, i-1));
    }

    memoCase[l][r] = tc;
    return mxDiff;
}

int main()
{
    int n;

    while(scanf("%d", &n), n) {
        for(int i = 0; i < n; ++i)
            scanf("%d", numbers+i);

        ++tc;

        printf("%d\n", fn(0,  n-1));
    }

    return 0;
}
