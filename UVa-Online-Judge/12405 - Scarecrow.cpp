// Greedy approach.
// Run time : 0.000 sec.

#include <cstdio>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        char str[100+3];

        scanf("%d\n%s", &n, str);

        int scarecrow = 0;

        for(int i = 0; i < n; )
            (str[i] == '.')? ++scarecrow, i += 3 : ++i;

        printf("Case %d: %d\n", tc, scarecrow);
    }

    return 0;
}


// --------------------------- Alternatively ---------------------------
// Minimum vertex cover, graph, dp.
// Run time : 0.000 sec.
/*
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100+3;

int n;
char str[MAXN];

int dp[MAXN][2][2];

int fn(int idx, bool isGuarded, bool isScarecrow)
{
    if(idx == n) {
        if(isScarecrow && str[idx-1] == '.') return 1;
        else return 0;
    }

    if(dp[idx][isGuarded][isScarecrow] != -1) return dp[idx][isGuarded][isScarecrow];

    int ret = 0;

    if(str[idx] == '.' && !isGuarded && !isScarecrow) {
        ret = fn(idx+1, true, true);
    }
    else if(str[idx] == '.' && isGuarded && !isScarecrow) {
        ret = min(fn(idx+1, true, true), fn(idx+1, false, false));
    }
    else if(str[idx] == '.' && isGuarded && isScarecrow) {
        ret = min(fn(idx+1, true, false), fn(idx+1, true, true));
    }
    else if(str[idx] == '#' && !isScarecrow){
        ret = min(fn(idx+1, false, false), fn(idx+1, true, true));
    }
    else if(str[idx] == '#' && isScarecrow) {
        ret = min(fn(idx+1, true, false), fn(idx+1, true, true));
    }

    return dp[idx][isGuarded][isScarecrow] = ret + isScarecrow;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d\n%s", &n, str);

        fill(&dp[0][0][0], &dp[MAXN][0][0], -1);

        printf("Case %d: %d\n", tc, min(fn(0, 0, 0), fn(0, 1, 1)));
    }

    return 0;
}
*/
