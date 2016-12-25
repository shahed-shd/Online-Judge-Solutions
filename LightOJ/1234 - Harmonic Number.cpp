// ==================================================
// Problem  :   1234 - Harmonic Number
// Run time :   1.008 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

const int MAXN = 1e8;
const int SZ = 1e6 + 3;

double memo[SZ] = {0};

int main()
{
    //freopen("in", "r", stdin);

    for(int i = 1; i < MAXN; ) {
        int x = 100;
        double res = 0;

        while(x--) res += 1.0 / i++;

        memo[i/100] = memo[i/100 - 1] + res;
    }

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        double ans = 0;

        for(int i = n / 100 * 100 + 1; i <= n; ++i)
            ans += 1.0 / i;

        ans += memo[n/100];

        printf("Case %d: %.10f\n", tc, ans);
    }

    return 0;
}
