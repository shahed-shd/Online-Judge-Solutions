// ==================================================
// Problem  :   787A - The Monster
// Run time :   0.015 sec.
// Language :   C11
// ==================================================

#include <stdio.h>

int main()
{
    int a, b, c, d;
    int i;
    double j;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    for(i = 0; i <= 100; ++i) {
        j = (b + a*i - d) * 1.0 / c;

        if(j >= 0 && j == (int) j) {
            printf("%d\n", b + a * i);
            return 0;
        }
    }

    puts("-1");

    return 0;
}
