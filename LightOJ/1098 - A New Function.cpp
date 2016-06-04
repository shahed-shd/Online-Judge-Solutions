// Run time : 0.188 sec.

#include <cstdio>
#include <cmath>
using namespace std;

typedef     long long       LL;

LL csod(int n)
{
    int rt = sqrt(n);
    LL ans = 0;

    for(int i = 2; i <= rt; ++i) {
        int j = n/i;

        ans += (LL(j+i) * (j-i+1)) >> 1;
        ans += i * (j-i);
    }

    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        printf("Case %d: %lld\n", tc, csod(n));
    }

    return 0;
}
