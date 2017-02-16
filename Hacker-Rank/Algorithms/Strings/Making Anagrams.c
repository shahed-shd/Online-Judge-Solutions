// ==================================================
// Problem  :   Making Anagrams
// Score    :   30 /30
// Language :   C
// ==================================================

#include <stdio.h>
#include <stdlib.h>

const int MAXL = 1e4 + 3;

int main()
{
    //freopen("in.txt", "r", stdin);

    char strA[MAXL], strB[MAXL];
    int cntA[30] = {0}, cntB[30] = {0}, ans = 0;

    scanf("%s %s", strA, strB);

    for(int i = 0; strA[i]; ++i)
        ++cntA[strA[i] - 'a'];

    for(int i = 0; strB[i]; ++i)
        ++cntB[strB[i] - 'a'];

    for(int i = 0; i < 26; ++i)
        ans += abs(cntA[i] - cntB[i]);

    printf("%d\n", ans);

    return 0;
}
