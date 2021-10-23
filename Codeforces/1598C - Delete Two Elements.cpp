// ==================================================
// Problem  :   1598C - Delete Two Elements
// Run time :   0.093 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
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

        vector<int> seq;
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            seq.push_back(a);
            sum += a;
        }

        sort(seq.begin(), seq.end());

        double k = sum * 1.0 / n;
        long long ans = 0;

        for (auto it = seq.begin(); it != seq.end(); ++it) {
            double toFind = 2 * k - *it;
            int y = int(toFind);
            if (toFind == y) {
                ans += upper_bound(it + 1, seq.end(), y) - lower_bound(it + 1, seq.end(), y);
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
