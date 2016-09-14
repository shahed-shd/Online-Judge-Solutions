// ==================================================
// Problem  :   1216 - Juice in the Glass
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int r1, r2, h, p;
        scanf("%d %d %d %d", &r1, &r2, &h, &p);

        double r = r2 + (r1 - r2) * double(p) / h;

        printf("Case %d: %.8f\n", tc, PI / 3 * p * (r*r + r*r2 + r2*r2));
    }

    return 0;
}
