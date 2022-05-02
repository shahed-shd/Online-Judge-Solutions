// ==================================================
// Problem  :   1672D - Cyclic Rotation
// Run time :   0.093 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <vector>
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

        vector<int> a(n), b(n), reserveCount(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }

        int i, j;
        i = j = n - 1;
        bool ans = true;

        while (i >= 0 && j >= 0) {
            if (j > 0 && b[j - 1] == b[j]) {
                ++reserveCount[b[j]];
                --j;
                continue;
            }

            if (a[i] == b[j]) {
                --i;
                --j;
            } else if (reserveCount[a[i]] > 0) {
                --reserveCount[a[i]];
                --i;
            } else {
                ans = false;
                break;
            }
        }

        printf(ans ? "YES\n" : "NO\n");
    }

    return 0;
}
