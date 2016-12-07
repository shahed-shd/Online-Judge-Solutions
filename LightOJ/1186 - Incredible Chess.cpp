// ==================================================
// Problem  :   1186 - Incredible Chess
// Run time :   0.004 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        int arr[n+3], tmp, res = 0;

        for(int i = 0; i < n; ++i) scanf("%d", arr+i);

        for(int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            res ^= tmp - arr[i] - 1;
        }

        printf("Case %d: %s\n", tc, (res)? "white wins" : "black wins");
    }

    return 0;
}

