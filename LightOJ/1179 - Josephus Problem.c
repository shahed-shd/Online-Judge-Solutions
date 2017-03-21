// ==================================================
// Problem  :   1179 - Josephus Problem
// Run time :   0.056 sec.
// Language :   C
// ==================================================

#include <stdio.h>

int main()
{
    int t, tc, n, k, i, ans;
    scanf("%d", &t);

    for(tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &n, &k);

        ans = 0;

        for(i = 2; i <= n; ++i) {
            ans += k;
            if(ans >= i) ans %= i;
        }

        printf("Case %d: %d\n", tc, ans+1);
    }

    return 0;
}
