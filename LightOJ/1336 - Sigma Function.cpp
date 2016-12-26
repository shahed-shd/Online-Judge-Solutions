// ==================================================
// Problem  :   1336 - Sigma Function
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

typedef     long long       LL;

int main()
{
    int t;
    scanf("%d",  &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL n;
        scanf("%lld", &n);

        printf("Case %d: %lld\n", tc, n - int(sqrt(n)) - int(sqrt(n/2)));
    }

    return 0;
}
