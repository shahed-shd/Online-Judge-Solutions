// ==================================================
// Problem  :   1311 - Unlucky Bird
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; ++tc) {
        double v1, v2, v3, a1, a2;
        scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);

        double t1 = v1 / a1;
        double t2 = v2 / a2;
        double s1 = v1 * t1 - 0.5 * a1 * t1 * t1;
        double s2 = v2 * t2 - 0.5 * a2 * t2 * t2;

        printf("Case %d: %.8f %.8f\n", tc, s1 + s2, v3 * max(t1, t2));
    }

    return 0;
}
