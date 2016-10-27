/*==================================================
   Problem  :   Intro to Tutorial Challenges
   Score    :   30 /30
   Language :   C
==================================================*/

#include <stdio.h>

int main()
{
    int v, n, i, ai, idx;

    scanf("%d %d", &v, &n);

    for(i = 0; i < n; ++i) {
        scanf("%d", &ai);
        if(ai == v) idx = i;
    }

    printf("%d\n", idx);

    return 0;
}
