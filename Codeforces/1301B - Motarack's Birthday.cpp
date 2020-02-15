// ==================================================
// Problem  :   1301B - Motarack's Birthday
// Run time :   0.139 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int mn = INF, mx = -INF, diff = 0;
        int curr, prev;

        scanf("%d", &prev);

        for(int i = 1; i < n; ++i) {
            scanf("%d", &curr);

            if(curr == -1) {
                if(prev != -1) {
                    mn = min(mn, prev);
                    mx = max(mx, prev);
                }
            } else {
                if(prev == -1) {
                    mn = min(mn, curr);
                    mx = max(mx, curr);
                } else {
                    diff = max(diff, abs(curr - prev));
                }
            }

            prev = curr;
        }

        int k = (mx + mn) / 2;
        diff = max(diff, mx-k);

        printf("%d %d\n", diff, k);
    }

    return 0;
}
