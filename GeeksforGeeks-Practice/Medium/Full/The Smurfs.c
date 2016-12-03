// ==================================================
// Problem  :   The Smurfs
// Run time :   0.078 sec.
// Language :   C
// ==================================================

#include <stdio.h>

int main()
{
    int t, n, rCnt, gCnt, bCnt, i;
    char ch[2];

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        rCnt = gCnt = bCnt = 0;

        for(i = 0; i < n; ++i) {
            scanf("%s", ch);

            if(ch[0] == 'R') ++rCnt;
            else if(ch[0] == 'G') ++gCnt;
            else ++bCnt;
        }

        int ans;

        if(rCnt == n || gCnt == n || bCnt == n)             /* Case 1 */
            ans = n;
        else if(rCnt & 1 && gCnt & 1 && bCnt & 1)           /* Case 2 */
            ans = 2;
        else if(!(rCnt & 1) && !(gCnt & 1) && !(bCnt & 1))  /* Case 3 */
            ans = 2;
        else                                                /* Case 4 */
            ans = 1;

        printf("%d\n", ans);
    }

    return 0;
}
