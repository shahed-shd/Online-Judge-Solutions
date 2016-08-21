// ==================================================
// Problem  :   707A - Brain's Photos
// Run time :   0.030 sec.
// Language :   C
// ==================================================

#include <stdio.h>

int main()
{
    int n, m, i, j;
    char clr, isColored;

    while(scanf("%d %d", &n, &m) != EOF) {
        isColored = 0;

        for(i = 0; i < n; ++i) {
            for(j = 0; j < m; ++j) {
                getchar();
                clr = getchar();

                if(!isColored && clr != 'B' && clr != 'W' && clr != 'G')
                    isColored = 1;
            }
        }

        puts((isColored)? "#Color" : "#Black&White");
    }

    return 0;
}
