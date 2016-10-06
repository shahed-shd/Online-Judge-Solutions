// ==================================================
// Problem  :   1036 - A Refining Company
// Run time :   0.148 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

const int MAXN = 500 + 3;

int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int m = fastIn<int>(), n = fastIn<int>();

        int uCumulative[MAXN][MAXN] = {{0}};

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                uCumulative[i][j] = fastIn<int>();
                uCumulative[i][j] += uCumulative[i][j-1];
            }
        }

        int rCumulative[MAXN][MAXN] = {{0}};

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                rCumulative[i][j] = fastIn<int>();
                rCumulative[i][j] += rCumulative[i-1][j];
            }
        }

        int memo[MAXN][MAXN] = {{0}};

        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                memo[i][j] = max(uCumulative[i][j] + memo[i-1][j], rCumulative[i][j] + memo[i][j-1]);

        printf("Case %d: %d\n", tc, memo[m][n]);
    }

    return 0;
}



// -------------------- Alternatively (recursive approach) --------------------
// Run time :   0.160 sec.
/*
#include <cstdio>
#include <algorithm>
using namespace std;

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

const int MAXN = 500 + 3;

int uCumulative[MAXN][MAXN] = {{0}}, rCumulative[MAXN][MAXN] = {{0}};
int memo[MAXN][MAXN];

int fn(int i, int j)
{
    if(i < 1 || j < 1) return 0;

    int &ret = memo[i][j];
    if(ret != -1) return ret;

    ret = max(uCumulative[i][j] + fn(i-1, j), rCumulative[i][j] + fn(i, j-1));

    return ret;
}

int main()
{
    freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int m = fastIn<int>(), n = fastIn<int>();

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                uCumulative[i][j] = fastIn<int>();
                uCumulative[i][j] += uCumulative[i][j-1];
            }
        }

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                rCumulative[i][j] = fastIn<int>();
                rCumulative[i][j] += rCumulative[i-1][j];
            }
        }

        fill(&memo[0][0], &memo[m][n]+1, -1);

        printf("Case %d: %d\n", tc, fn(m, n));
    }

    return 0;
}
*/
