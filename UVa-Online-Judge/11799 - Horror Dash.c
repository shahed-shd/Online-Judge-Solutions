// ==================================================
// Problem  :   11799 - Horror Dash
// Run time :   0.000 sec.
// Language :   C
// ==================================================

#include <stdio.h>

int main()
{
    int t, tc, n, c, mx;
    scanf("%d", &t);

    for(tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);
        mx = 0;

        while(n--) {
            scanf("%d", &c);
            if(c > mx) mx = c;
        }

        printf("Case %d: %d\n", tc, mx);
    }

    return 0;
}
