// Run time :   0.020 sec.

#include <stdio.h>

int fastIn()                // to input positive integer.
{
    register char ch = 0;
    register int a = 0;

    while(ch < 33) ch = getchar();

    a = ch - '0';

    while(ch = getchar(), ch > 33)
        a = a * 10 + (ch - '0');

    return a;
}

int main()
{
    int n;

    while(n = fastIn(), n)
        printf("f91(%d) = %d\n", n, ((n <= 100)? 91 : n-10));

    return 0;
}
