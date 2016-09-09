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


// -------------------- Alternatively (with Segment Tree) --------------------
// Run time	:	0.220 sec.
/*
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int SZ = 262143 + 3;      // MAXN = 1e5 + 3
                                // 262143 = 2 * pow(2, ceil(log2(MAXN))) - 1
int treeMin[SZ], treeMax[SZ];

void init(int node, int s, int t)
{
    if(s == t) {
        scanf("%d", treeMin+node);     // treeMin[node]
        treeMax[node] = treeMin[node];
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    init(left, s, mid);
    init(right, mid+1, t);

    treeMin[node] = min(treeMin[left], treeMin[right]);
    treeMax[node] = max(treeMax[left], treeMax[right]);
}

int minQuery(int node, int s, int t, int rs, int rt)
{
    if(t < rs || rt < s) return INT_MAX;
    if(rs <= s && t <= rt) return treeMin[node];

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    return min(minQuery(left, s, mid, rs, rt), minQuery(right, mid+1, t, rs, rt));
}

int maxQuery(int node, int s, int t, int rs, int rt)
{
    if(t < rs || rt < s) return INT_MIN;
    if(rs <= s && t <= rt) return treeMax[node];

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    return max(maxQuery(left, s, mid, rs, rt), maxQuery(right, mid+1, t, rs, rt));
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, d;
        scanf("%d %d", &n, &d);

        init(1, 1, n);

        int maxDiff = 0;

        for(int i = d; i <= n; ++i)
            maxDiff = max(maxDiff, maxQuery(1, 1, n, i-d+1, i) - minQuery(1, 1, n, i-d+1, i));

        printf("Case %d: %d\n", tc, maxDiff);
    }

    return 0;
}
*/
