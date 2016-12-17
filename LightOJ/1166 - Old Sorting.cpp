// ==================================================
// Problem  :   1166 - Old Sorting
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 3;

int main()
{
    int t;
    scanf("%d", &t);

    int arr[MAXN];

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        for(int i = 1; i <= n; ++i) scanf("%d", arr+i);

        int ans = 0;

        for(int i = 1; i <= n; ++i) {
            while(arr[i] != i) {
                swap(arr[i], arr[arr[i]]);
                ++ans;
            }
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
