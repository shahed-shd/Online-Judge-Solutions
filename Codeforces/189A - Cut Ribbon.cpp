// ==================================================
// Problem  :   189A - Cut Ribbon
// Run time :   0.062 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 4000 + 3;
const int INF = INT_MAX;

int arr[3];

int memo[3][MAXN];

int fn(int idx, int rem)
{
    if(rem == 0) return 0;
    if(idx == 3) return -INF;

    int &ret = memo[idx][rem];
    if(ret != -1) return ret;

    ret = -INF;

    for(int i = 0; rem - arr[idx]*i >= 0; ++i)
        ret = max(ret,  i + fn(idx+1, rem - arr[idx] * i));

    return ret;
}

int main()
{
    int n;

    while(~scanf("%d %d %d %d", &n, arr, arr+1, arr+2)) {
        fill(&memo[0][0], &memo[3][0], -1);

        printf("%d\n", fn(0, n));
    }

    return 0;
}
