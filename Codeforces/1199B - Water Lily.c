// ==================================================
// Problem  :   1199B - Water Lily
// Run time :   0.031 sec.
// Language :   C11
// ==================================================

#include <stdio.h>


int main()
{
    double h, l;
    scanf("%lf %lf", &h, &l);

    printf("%.7f\n", (l*l - h*h) / (2*h));

    return 0;
}
