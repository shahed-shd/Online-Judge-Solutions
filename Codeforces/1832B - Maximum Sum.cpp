// ==================================================
// Problem  :   1832B - Maximum Sum
// Run time :   0.078 sec
// Language :   C++17
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);

        vector<int> a(n + 1);

        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + a[i];
        }

        LL ans = 0;

        for (int m = 0; m <= k; ++m) {
            ans = max(ans, prefixSum[n - (k - m)] - prefixSum[2 * m]);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
