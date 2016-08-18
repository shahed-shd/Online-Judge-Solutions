// ==================================================
// Problem  :   616A - Comparing Two Long Integers
// Run time :   0.031 sec.
// Language :   C
// ==================================================

#include <stdio.h>
#include <string.h>

const int MAXL = 1e6 + 3;

int my_gets(char str[], int sz)
{
    int len;

    fgets(str, sz, stdin);
    len = strlen(str);

    if(str[len-1] == '\n') {
        str[len-1] = '\0';
        --len;
    }

    return len;
}

int main()
{
    char a[MAXL], b[MAXL];
    int len_a, start_a, numLen_a, len_b, start_b, numLen_b, i, flag;

    len_a = my_gets(a, MAXL);
    for(i = 0; i < len_a && a[i] == '0'; ++i);
    start_a = i;

    len_b = my_gets(b, MAXL);
    for(i = 0; i < len_b && b[i] == '0'; ++i);
    start_b = i;

    numLen_a = len_a - start_a;
    numLen_b = len_b - start_b;

    if(numLen_a < numLen_b)
        putchar('<');
    else if(numLen_a > numLen_b)
        putchar('>');
    else {                  // numLen_a == numLen_b
        flag = strcmp(&a[start_a], &b[start_b]);

        if(flag < 0) putchar('<');
        else if(flag > 0) putchar('>');
        else putchar('=');
    }

    putchar('\n');

    return 0;
}
