// ==================================================
// Problem  :   1607C - Minimum Extraction
// Run time :   0.078 sec
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

        vector<int> vec(n);

        for (auto &x : vec) {
            scanf("%d", &x);
        }

        sort(vec.begin(), vec.end());

        int ans = vec[0];

        if (n > 1) {
            for (int i = 1; i < n; ++i) {
                ans = max(ans, vec[i] - vec[i - 1]);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
