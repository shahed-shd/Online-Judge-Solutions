// ==================================================
// Problem  :   Two Strings
// Score    :   25 /25
// Language :   C
// ==================================================


#include <stdio.h>


const int MAXL = 1e5 + 3;

enum boolean {FALSE = 0, TRUE};


int main()
{
    //freopen("in.txt", "r", stdin);

    int p;
    scanf("%d", &p);

    char str_a[MAXL], str_b[MAXL];

    while(p--) {
        scanf("%s %s", str_a, str_b);

        int letterCount[26 + 3] = {0};

        for(int i = 0; str_a[i]; ++i)
            ++letterCount[str_a[i] - 'a'];

        enum boolean ans = FALSE;

        for(int i = 0; str_b[i] && !ans; ++i)
            if(letterCount[str_b[i] - 'a'])
                ans = TRUE;

        puts(ans? "YES" : "NO");
    }

    return 0;
}
