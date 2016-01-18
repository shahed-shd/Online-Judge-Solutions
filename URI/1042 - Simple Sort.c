#include <stdio.h>

#define     max(a, b)   ((a>b)? a : b)
#define     min(a, b)   ((a<b)? a : b)

int main()
{
    int a, b, c, mx, mid, mn;

    while(scanf("%d %d %d", &a, &b, &c) != EOF) {
        mx = max(a, max(b, c));
        mn = min(a, min(b, c));
        mid = a + b + c - mx - mn;

        printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", mn, mid, mx, a, b, c);
    }

    return 0;
}
