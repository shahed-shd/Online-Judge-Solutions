// ==================================================
// Problem  :   1628C - Grid Xor
// Run time :   0.249 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <vector>
using namespace std;


inline bool isEven(int n) { return !(n & 1); }


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        vector<vector<int>> cnt(n, vector<int>(n, 0));
        int res = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val;
                scanf("%d", &val);

                if (i == 0 || isEven(cnt[i - 1][j])) {
                    res ^= val;

                    if (i - 1 >= 0) ++cnt[i - 1][j];
                    if (i + 1 < n) ++cnt[i + 1][j];
                    if (j - 1 >= 0) ++cnt[i][j - 1];
                    if (j + 1 < n)++cnt[i][j + 1];
                }
            }
        }

        printf("%d\n", res);
    }

    return 0;
}
