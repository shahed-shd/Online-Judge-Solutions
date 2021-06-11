// ==================================================
// Problem  :   1538C - Number of Pairs
// Run time :   0.078 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;


typedef     long long       LL;


const int MAXN = 2e5 + 3;

int a[MAXN];


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, l, r;
        scanf("%d %d %d", &n, &l, &r);

        for(int i = 0; i < n; ++i) scanf("%d", a+i);

        sort(a, a+n);
        LL ans = 0;

        for(int i = 0; i < n; ++i) {
            int* lb = lower_bound(a+i+1, a+n, l - a[i]);
            int* ub = upper_bound(a+i+1, a+n, r - a[i]);
            ans += ub - lb;
        }

        printf("%lld\n", ans);
    }
    

    return 0;
}
