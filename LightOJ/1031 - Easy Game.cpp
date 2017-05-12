// ==================================================
// Problem  :   1031 - Easy Game
// Run time :   0.032 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 100 + 3;

int arr[MAXN], memo[MAXN][MAXN] = {0};

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
            scanf("%d", arr+i);


        for(int i = 0; i < n; ++i) memo[i][i] = arr[i];

        for(int L = 2; L <= n; ++L) {
            for(int i1 = 0; i1 < n; ++i1) {
                int i2 = min(i1+L-1, n-1);

                int sum = 0, res = INT_MIN;

                for(int i = i1; i <= i2; ++i) {
                    sum += arr[i];
                    res = max(res, sum - memo[i+1][i2]);
                }

                sum = 0;

                for(int i = i2; i >= i1; --i) {
                    sum += arr[i];
                    res = max(res, sum - memo[i1][i-1]);
                }

                memo[i1][i2] = res;
            }
        }

        printf("Case %d: %d\n", tc, memo[0][n-1]);

    }

    return 0;
}



// --------------- Alternatively (Recursive) ---------------
// Run time :   0.052 sec.

/*
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 100 + 3;

int arr[MAXN], memo[MAXN][MAXN];

int fn(int i1, int i2)
{
    if(i1 > i2) return 0;

    int &ret = memo[i1][i2];
    if(ret != INT_MIN) return ret;

    int sum = 0;

    for(int i = i1; i <= i2; ++i) {
        sum += arr[i];
        ret = max(ret, sum - fn(i+1, i2));
    }

    sum = 0;

    for(int i = i2; i >= i1; --i) {
        sum += arr[i];
        ret = max(ret, sum - fn(i1, i-1));
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

        for(int i = 0; i < n; ++i)
            scanf("%d", arr+i);

        fill(&memo[0][0], &memo[MAXN][0], INT_MIN);

        printf("Case %d: %d\n", tc, fn(0, n-1));
    }

    return 0;
}
*/
