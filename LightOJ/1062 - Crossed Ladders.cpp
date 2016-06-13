#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

double x, y, c, w;

inline double this_w(double w)
{
    double h1 = sqrt(x*x - w*w), h2 = sqrt(y*y - w*w);
    return (h1*h2) / (h1+h2);
}

void bin_search(double s, double t)
{
    while(s <= t) {
        double mid = (s+t)/2;

        double assumed_c = this_w(mid);

        if(fabs(assumed_c - c) <= 1e-9) {
            w = mid;
            return;
        }

        if(assumed_c < c) t = mid;
        else s = mid;
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%lf %lf %lf", &x, &y, &c);

        bin_search(0, min(x, y));

        printf("Case %d: %.9f\n", tc, w);
    }

    return 0;
}
