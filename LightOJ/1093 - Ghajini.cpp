// ==================================================
// Problem  :   1093 - Ghajini
// Run time :   0.104 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <deque>
using namespace std;

#define     ff      first
#define     ss      second

typedef     pair<int,int>       ii;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, d;
        scanf("%d %d", &n, &d);

        deque<ii> minq, maxq;
        int val, mn, mx, diff = 0;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &val);

            // Sliding window minimum.
            while(!minq.empty() && minq.back().ff >= val) minq.pop_back();
            minq.push_back(ii(val, i));

            while(minq.front().ss <= i-d) minq.pop_front();
            mn = minq.front().ff;

            // Sliding window maximum.
            while(!maxq.empty() && maxq.back().ff <= val) maxq.pop_back();
            maxq.push_back(ii(val, i));

            while(maxq.front().ss <= i-d) maxq.pop_front();
            mx = maxq.front().ff;

            // Get the difference.
            diff = max(diff, mx - mn);
        }

        printf("Case %d: %d\n", tc, diff);
    }

    return 0;
}
