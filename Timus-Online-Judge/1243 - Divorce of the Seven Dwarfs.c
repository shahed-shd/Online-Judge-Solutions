// ==================================================
// Problem  :   1243. Divorce of the Seven Dwarfs
// Run time :   0.015 sec.
// Language :   C
// ==================================================

#include <stdio.h>

const int MAXL = 51 + 3;

int main()
{
    char str[MAXL];
    scanf("%s", str);

    int res = 0;

    for(int i = 0; str[i]; ++i) {
        res = (res * 10 + str[i] - '0') % 7;
    }

    printf("%d\n", res);

    return 0;
}
