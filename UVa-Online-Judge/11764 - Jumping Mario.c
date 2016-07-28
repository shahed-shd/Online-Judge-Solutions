#include <stdio.h>

int main()
{
    int t, tc, n, prev, curr, hiCnt, loCnt;

    scanf("%d", &t);

    for(tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &n, &prev);

        hiCnt = loCnt = 0;

        while(--n) {
            scanf("%d", &curr);

            if(prev < curr) ++hiCnt;
            else if(prev > curr) ++loCnt;

            prev = curr;
        }

        printf("Case %d: %d %d\n", tc, hiCnt, loCnt);
    }

    return 0;
}
