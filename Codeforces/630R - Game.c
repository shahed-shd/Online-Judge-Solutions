// ==================================================
// Problem  :   630R - Game
// Run time :   0.015 sec.
// Language :   C
// ==================================================

#include <stdio.h>

int main()
{
    long long n;

    while(~scanf("%I64d", &n))
        puts((n & 1)? "1" : "2");

    return 0;
}
