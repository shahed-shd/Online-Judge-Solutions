// ==================================================
// Problem  :   Optimal walk
// Runtime  :   0.088 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 3;

typedef     long long       LL;

LL memo[MAXN];

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);

        memo[0] = 0;

        for(int i = 1; i <= n; ++i) {
            if(i & 1) {
                memo[i] = min(memo[i-1]+a, memo[(i+1)/2]+b+a);
            }
            else {
                memo[i] = min(memo[i-1]+a, memo[i/2]+b);
            }
        }

        printf("%lld\n", memo[n]);
    }

    return 0;
}
