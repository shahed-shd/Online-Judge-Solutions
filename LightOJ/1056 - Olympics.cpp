// ==================================================
// Problem  :   1056 - Olympics
// Run time :   0.008 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

int a, b;
double length, w;

double this_len(double len)
{
    w = len * b / a;
    double r = hypot(len, w) / 2;
    double theta = 2 * asin(w / (2*r));
    return r * theta;
}

void binSearch()
{
    double b = 0, e = 200;

    while(b <= e) {
        double mid = (b + e) / 2;

        double assumed_arc = this_len(mid);
        double arc = 200 - mid;

        if(fabs(assumed_arc - arc) < 1e-8) {
            length = mid;
            return;
        }

        if(assumed_arc < arc)
            b = mid;
        else
            e = mid;
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d : %d", &a, &b);

        binSearch();

        printf("Case %d: %.8f %.8f\n", tc, length, w);
    }

    return 0;
}
