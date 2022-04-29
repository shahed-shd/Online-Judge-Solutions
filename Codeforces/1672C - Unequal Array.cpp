// ==================================================
// Problem  :   1672C - Unequal Array
// Run time :   0.061 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int prev, curr, mn = -1, mx = -1;
        scanf("%d", &prev);

        for (int i = 1; i < n; ++i) {
            scanf("%d", &curr);

            if (curr == prev) {
                if (mn == -1) {
                    mn = i;
                }
                mx = i;
            }

            prev = curr;
        }

        int ans = mn == mx ? 0 : max(1, mx - mn - 1);

        printf("%d\n", ans);
    }

    return 0;
}
