// ==================================================
// Problem  :   1043 - Triangle Partitioning
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        double AB, areaRatio;
        scanf("%lf %*f %*f %lf", &AB, &areaRatio);

        printf("Case %d: %.8lf\n", tc, AB * sqrt(areaRatio / (areaRatio+1)));
    }

    return 0;
}


// ---------- Alternatively (with Binary Search)--------------------
// Run time		: 0.000 sec
/*
#include <cstdio>
#include <cmath>
using namespace std;

double AB, AC, BC, areaRatio;

double this_AD(double AD)
{
    double DE = AD * BC / AB;
    double AE = AC * (AD / AB);

    double s = (AD + DE + AE) / 2;
    double areaADE = sqrt(s * (s-AD) * (s-DE) * (s-AE));

    s = (AB + BC + AC) / 2;
    double areaBCED = sqrt(s * (s-AB) * (s-BC) * (s-AC)) - areaADE;

    return areaADE / areaBCED;
}

double binSearch()
{
    double s = 0, t = AB;

    while(s <= t) {
        double mid = (s + t) / 2;

        double assumedRatio = this_AD(mid);

        if(fabs(assumedRatio - areaRatio) < 1e-8)
            return mid;
        if(assumedRatio < areaRatio)
            s = mid;
        else
            t = mid;
    }

    return 0;   // Just to avoid warning while compiling.
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &areaRatio);

        printf("Case %d: %.8lf\n", tc, binSearch());
    }

    return 0;
}
*/
