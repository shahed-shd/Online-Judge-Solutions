// ==================================================
// Problem  :   CamelCase
// Score    :   15 /15
// Language :   C
// ==================================================

#include <stdio.h>

const int MAXL = 1e5 + 3;

int main()
{
    //freopen("in.txt", "r", stdin);

    char str[MAXL];
    int ans = 1;

    scanf("%s", str);

    for(int i = 0; str[i]; ++i)
        if('A' <= str[i] && str[i] <= 'Z')
            ++ans;

    printf("%d\n", ans);

    return 0;
}
