// ==================================================
// Problem  :   750C - New Year and Rating
// Run time :   0.062 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main()
{
    int n;
    scanf("%d", &n);

    int ci, di, delta = 0, hi = INF, lo = -INF;

    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &ci, &di);

        if(di == 1) {
            lo = max(lo, 1900-delta);
        }
        else {
            hi = min(hi, 1899-delta);
        }

        delta += ci;
    }

    if(hi == INF) {
        puts("Infinity");
    }
    else if(hi < lo) {
        puts("Impossible");
    }
    else {
        printf("%d\n", hi+delta);
    }

    return 0;
}
