// ==================================================
// Problem  :   11297 - Census
// Run time :   0.410 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 500 + 3;
const int MAXS = 1023 + 3;  // 1023 = (1 << (ceil(log2(MAXN)) + 1)) - 1

class segTree {
    int treeMax[MAXS], treeMin[MAXS];

public:
    void build(int node, int s, int t) {
        if(s == t) {
            scanf("%d", treeMax+node);
            treeMin[node] = treeMax[node];
            return;
        }

        int left = node << 1, right = left | 1,  mid = (s + t) >> 1;

        build(left, s, mid);
        build(right, mid+1, t);

        treeMax[node] = max(treeMax[left], treeMax[right]);
        treeMin[node] = min(treeMin[left], treeMin[right]);
    }

    void update(int node, int s, int t, int idx, int val) {
        if(s == t) {
            treeMax[node] = treeMin[node] = val;
            return;
        }

        int left = node << 1, right = left | 1,  mid = (s + t) >> 1;

        if(idx <= mid)
            update(left, s, mid, idx, val);
        else
            update(right, mid+1, t, idx, val);

        treeMax[node] = max(treeMax[left], treeMax[right]);
        treeMin[node] = min(treeMin[left], treeMin[right]);
    }

    void query(int node, int s, int t, int rs, int rt, int &mx, int &mn) {
        if(t < rs || rt < s) return;

        if(rs <= s && t <= rt) {
            mx = treeMax[node];
            mn = treeMin[node];
            return;
        }

        int left = node << 1, right = left | 1,  mid = (s + t) >> 1;

        int mx1, mx2, mn1, mn2;

        mx1 = mx2 = INT_MIN;
        mn1 = mn2 = INT_MAX;

        query(left, s, mid, rs, rt, mx1, mn1);
        query(right, mid+1, t, rs, rt, mx2, mn2);

        mx = max(mx1, mx2);
        mn = min(mn1, mn2);
    }
};

int main()
{
    //freopen("in", "r", stdin);

    int n;
    scanf("%d", &n);

    segTree st[n];

    for(int i = 0; i < n; ++i)
        st[i].build(1, 1, n);

    int q, x1, y1, x2, y2, val;
    char type;

    scanf("%d", &q);

    while(q--) {
        getchar();
        type = getchar();

        if(type == 'q') {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            --x1, --x2;

            int mx = INT_MIN, mn = INT_MAX;
            int curr_mx, curr_mn;

            for(int i = x1; i <= x2; ++i) {
                st[i].query(1, 1, n, y1, y2, curr_mx, curr_mn);

                mx = max(mx, curr_mx);
                mn = min(mn, curr_mn);
            }

            printf("%d %d\n", mx, mn);
        }
        else {
            scanf("%d %d %d", &x1, &y1, &val);
            st[--x1].update(1, 1, n, y1, val);
        }
    }

    return 0;
}
