// ==================================================
// Problem  :   1245 - Harmonic Number (II)
// Run time :   0.184 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d",  &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        int x1 = 1, y1 = n, x2 = 2, y2;
        LL sum = n;

        while(y2 = n/x2, x2 < y2) {
            sum += y2;
            sum += (y1-y2) * x1;

            x1 = x2, y1 = y2;
            ++x2;
        }

        for(int i = x1+1; i <= y1; ++i)
            sum += n / i;

        printf("Case %d: %lld\n", tc, sum);
    }

    return 0;
}
