// ==================================================
// Problem  :   1148 - Mad Counting
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 50 + 3;

int main()
{
    int t;
    scanf("%d", &t);

    int arr[MAXN];

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) scanf("%d", arr+i);

        sort(arr, arr+n);

        int idx = 0;
        int ans = 0;

        while(idx < n) {
            int val = arr[idx];
            int cnt = 0;

            while(idx < n && arr[idx] == val)
                ++idx, ++cnt;

            int team = cnt / (val+1) + (cnt % (val+1) != 0);
            ans += team * (val+1);
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
