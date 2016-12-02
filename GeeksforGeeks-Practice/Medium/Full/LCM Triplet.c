// ==================================================
// Problem  :   LCM Triplet
// Run time :   0.073 sec.
// Language :   C
// ==================================================

#include <stdio.h>

int main()
{
    int t;
    long long n;

    scanf("%d", &t);

    while(t--) {
        scanf("%lld", &n);

        if(n == 1)
            puts("1");
        else if(n == 2)
            puts("2");
        else if(n == 3)
            puts("6");
        else if(n & 1)
            printf("%lld\n", n*(n-1)*(n-2));
        else
            printf("%lld\n", ((n % 6 == 0)? (n-1)*(n-2)*(n-3) : n*(n-1)*(n-3)));
    }

    return 0;
}
