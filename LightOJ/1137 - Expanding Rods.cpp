// ==================================================
// Problem  :   1137 - Expanding Rods
// Runtime  :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-15;

double s, l;

double binSearch(double ss, double tt)
{
    while(ss <= tt) {
        double mid = (ss + tt) / 2;

        double r = s / mid;
        double d = r * sin(mid/2);

        if(abs(d - l) < eps) {
            return r - r * cos(mid/2);
        }
        if(d > l) {
            ss = mid;
        }
        else {
            tt = mid;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        double L, n, c;
        scanf("%lf %lf %lf", &L, &n, &c);

        s = (1 + n*c) * L;
        l = L / 2;

        printf("Case %d: %.8f\n", tc, binSearch(0, 2*PI));
    }

    return 0;
}
