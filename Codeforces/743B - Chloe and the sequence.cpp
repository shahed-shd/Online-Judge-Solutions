// ==================================================
// Problem  :   743B - Chloe and the sequence
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

typedef     long long       LL;

int main()
{
    LL k;
    scanf("%*d %I64d", &k);

    LL mid, diff;

    do {
        mid = 1LL << int(log2(k));
        diff = k - mid;
        k = mid - diff;
    }while(diff);

    LL ans = int(log2(mid)) + 1;

    printf("%I64d\n", ans);

    return 0;
}

