// ==================================================
// Problem  :   1081 - Square Queries
// Runtime  :   1.088 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 500 + 3;
const int SZ = 1023 + 3;        // 1023 = (1 << int(ceil(log2(MAXN)) + 1)) - 1.
const int INF = INT_MAX;

struct segTree {
    int tree[SZ];

    void build(int node, int s, int t) {
        if(s == t) {
            scanf("%d", tree+node);
            return;
        }

        int left = node << 1, right = left | 1, mid = (s + t) >> 1;

        build(left, s, mid);
        build(right, mid+1, t);

        tree[node] = max(tree[left], tree[right]);
    }

    int query(int node, int s, int t, int rs, int rt) {
        if(t < rs || rt < s) return -INF;
        if(rs <= s && t <= rt) return tree[node];

        int left = node << 1, right = left | 1, mid = (s + t) >> 1;

        return max(query(left, s, mid, rs, rt), query(right, mid+1, t, rs, rt));
    }
};

segTree trees[MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, q;
        scanf("%d %d", &n, &q);

        for(int i = 1; i <= n; ++i)
            trees[i].build(1, 1, n);

        printf("Case %d:\n", tc);

        int r, c, s;

        while(q--) {
            scanf("%d %d %d", &r, &c, &s);

            int ans = 0;

            for(int i = r; i < r+s; ++i)
                ans = max(ans, trees[i].query(1, 1, n, c, c+s-1));

            printf("%d\n", ans);
        }
    }

    return 0;
}
