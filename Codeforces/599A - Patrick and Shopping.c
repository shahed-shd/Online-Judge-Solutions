// ==================================================
// Problem  :   599A - Patrick and Shopping
// Run time :   0.015 sec.
// Language :   C11
// ==================================================

#include <stdio.h>

#define     min(a, b)       ((a < b)? a : b)

int main()
{
    int d1, d2, d3;
    scanf("%d %d %d", &d1, &d2, &d3);

    int ans = d1 + d2 + min(d1+d2, d3);
    ans = min(ans, (d1 << 1) + (d3 << 1));
    ans = min(ans, (d2 << 1) + (d3 << 1));

    printf("%d\n", ans);

    return 0;
}
