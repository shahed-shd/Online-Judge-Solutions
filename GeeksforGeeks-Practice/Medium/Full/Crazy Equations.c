// ==================================================
// Problem  :   Crazy Equations
// Run time :   0.088 sec.
// Language :   C
// ==================================================

#include <stdio.h>

int main()
{
    int t, n, a, b, c, d, x, y, z, w, ans;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

        ans = 0;

        for(x = 1; x <= n; ++x) {
            y = x - b + c;
            z = y - a + d;
            w = z - c + b;

            if(1 <= y && y <= n && 1 <= z && z <= n && 1 <= w && w <= n) ++ans;
        }

        printf("%d\n", ans);
    }

    return 0;
}
