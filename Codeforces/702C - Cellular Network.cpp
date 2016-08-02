// ==================================================
// Problem  :   702C - Cellular Network
// Run time :   0.062 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef     long long       LL;

int main()
{
    int n, m;

    while(~scanf("%d %d", &n, &m)) {
        LL cities[n];
        for(int i = 0; i < n; ++i) scanf("%I64d", cities+i);

        LL towers[m];
        for(int i = 0; i < m; ++i) scanf("%I64d", towers+i);

        int j = 0;
        LL ans = 0;

        for(int i = 0; i < n; ++i) {
            while(j+1 < m && abs(cities[i] - towers[j]) >= abs(cities[i] - towers[j+1])) ++j;
            ans = max(ans, abs(cities[i] - towers[j]));
        }

        printf("%I64d\n", ans);
    }

    return 0;
}
