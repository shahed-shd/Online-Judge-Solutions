// ==================================================
// Problem  :   1178 - Trapezium
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        double a, b, c, d;
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

        if(a < c) swap(a, c);

        double s = (b + d + a - c) / 2;
        double h = 2 * sqrt(s * (s-(a-c)) * (s-b) * (s-d)) / (a-c);

        printf("Case %d: %.8f\n", tc, 0.5 * h * (a+c));
    }

    return 0;
}
