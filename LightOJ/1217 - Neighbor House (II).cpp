// ==================================================
// Problem  :   1217 - Neighbor House (II)
// Run time :   0.008 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 3;

int memo[2][MAXN];
int n, soaps[MAXN];

int fn(bool isHouseOneTaken, int idx)
{
    if(idx > n) return 0;
    if(idx == n and isHouseOneTaken) return 0;

    int &ret = memo[isHouseOneTaken][idx];
    if(ret != -1) return ret;

    if(idx == 1)
        ret = max(soaps[idx] + fn(true, idx+2), fn(false, idx+1));
    else
        ret = max(soaps[idx] + fn(isHouseOneTaken, idx+2), fn(isHouseOneTaken, idx+1));

    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        for(int i = 1; i <= n; ++i) scanf("%d", soaps+i);

        fill(&memo[0][0], &memo[2][0], -1);

        int res = fn(true, 1);

        printf("Case %d: %d\n", tc, res);
    }

    return 0;
}


// ******************** Alternatively ********************
// Run time :   0.008 sec.
/*
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 3;

int memo[2][MAXN];
int soaps[MAXN];
int upto;

int fn(bool mayTake, int idx)
{
    if(idx > upto) return 0;

    int &ret = memo[mayTake][idx];
    if(ret != -1) return ret;

    ret = 0;

    if(mayTake) {
        ret = max(soaps[idx] + fn(false, idx+1), fn(true, idx+1));
    }
    else {
        ret = fn(true, idx+1);
    }

    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        for(int i = 1; i <= n; ++i) scanf("%d", soaps+i);

        fill(&memo[0][0], &memo[2][0], -1);

        upto = n - 1;
        int res = fn(true, 1);

        fill(&memo[0][0], &memo[2][0], -1);
        upto = n;
        res = max(res, fn(false, 1));

        printf("Case %d: %d\n", tc, res);
    }

    return 0;
}
*/
