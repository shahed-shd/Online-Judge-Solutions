/*==================================================
   Problem  :   1241 - Pinocchio
   Run time :   0.000 sec.
   Language :   C
==================================================*/

#include <stdio.h>
#include <math.h>

int main()
{
    int t, tc, n, prev, curr, ans;

    scanf("%d", &t);

    for(tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);
        prev = 2, ans = 0;

        while(n--) {
            scanf("%d", &curr);

            if(curr > prev) {
                ans += ceil((curr-prev) / 5.0);
                prev = curr;
            }
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
