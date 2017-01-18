// ==================================================
// Problem  :   1198 - Karate Competition
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 50 + 3;

int a[MAXN], b[MAXN];
int memo[MAXN][MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) scanf("%d", a+i);
        for(int i = 0; i < n; ++i) scanf("%d", b+i);

        sort(a, a+n);
        sort(b, b+n);

        for(int i = 0; i <= n; ++i)
            memo[n][i] = memo[i][n] = 0;

        for(int i = n-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                if(a[i] < b[j])
                    memo[i][j] = memo[i+1][j];
                else if(a[i] > b[j])
                    memo[i][j] = 2 + memo[i+1][j+1];
                else
                    memo[i][j] = max(1+memo[i+1][j+1], memo[i+1][j]);
            }
        }

        printf("Case %d: %d\n", tc, memo[0][0]);
    }

    return 0;
}


// -------------------- Alternatively (Recursive approach) --------------------
// Run time :   0.000 sec.
/*
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 50 + 3;

int n, a[MAXN], b[MAXN];
int memo[MAXN][MAXN];

int fn(int i, int j)
{
    if(i >= n || j >= n) return 0;

    int &ret = memo[i][j];
    if(ret != -1) return ret;

    if(a[i] < b[j])
        ret = fn(i+1, j);
    else if(a[i] > b[j])
        ret = 2 + fn(i+1, j+1);
    else
        ret = max(1+fn(i+1, j+1), fn(i+1, j));

    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) scanf("%d", a+i);
        for(int i = 0; i < n; ++i) scanf("%d", b+i);

        sort(a, a+n);
        sort(b, b+n);

        fill(&memo[0][0], &memo[MAXN][0], -1);

        printf("Case %d: %d\n", tc, fn(0, 0));
    }

    return 0;
}
*/
