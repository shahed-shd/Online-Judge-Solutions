// ==================================================
// Problem  :   1163 - Bank Robbery
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL n;
        scanf("%lld", &n);

        printf("Case %d:", tc);

        for(int i = 9; i >= 0; --i) {
            if((n-i) % 9 == 0) {
                LL b = (n - i) / 9;
                printf(" %lld", b * 10 + i);
            }
        }

        putchar('\n');
    }

    return 0;
}
