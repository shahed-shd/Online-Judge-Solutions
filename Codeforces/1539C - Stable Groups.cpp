// ==================================================
// Problem  :   1539C - Stable Groups
// Run time :   0.140 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


typedef     long long       LL;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    LL k, x;
    scanf("%d %lld %lld", &n, &k, &x);

    vector<LL> a(n);
    for(auto& x : a) {
        scanf("%lld", &x);
    }

    sort(a.begin(), a.end());

    vector<LL> largeGaps;

    for(int i = 1; i < n; ++i) {
        LL gap = a[i] - a[i - 1];

        if (gap > x) {
            largeGaps.push_back(gap);
        }
    }

    int groupCount = largeGaps.size() + 1;

    sort(largeGaps.begin(), largeGaps.end());

    for(auto& gap : largeGaps) {
        LL additional = (gap % x == 0) ? (gap / x) - 1 : gap / x;
        
        if (additional <= k) {
            --groupCount;
            k -= additional;
        } else {
            break;
        }
    }


    printf("%d ", groupCount);

    return 0;
}
