// ==================================================
// Problem  :   1669H - Maximal AND
// Run time :   0.078 sec
// Language :   C++17
// ==================================================


#include <cstdio>
using namespace std;


inline bool bitCheck(int n, int pos) { return n & (1 << pos); }
inline int bitOn(int n, int pos) { return n | (1 << pos); }


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int val, zeroCount[31] = {0};

        for (int i = 0; i < n; ++i) {
            scanf("%d", &val);

            for (int pos = 0; pos <= 30; ++pos) {
                if (!bitCheck(val, pos)) {
                    ++zeroCount[pos];
                }
            }
        }

        int ans = 0;

        for (int pos = 30; pos >= 0; --pos) {
            if (zeroCount[pos] <= k) {
                k -= zeroCount[pos];
                zeroCount[pos] = 0;
            }

            if (zeroCount[pos] == 0) {
                ans = bitOn(ans, pos);
            }
        }
        
        printf("%d\n", ans);
    }

    return 0;
}
