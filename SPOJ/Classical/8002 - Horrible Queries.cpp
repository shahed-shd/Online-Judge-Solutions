#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef     long long   LL;

class segmentTree {
    vector<LL> tree;
    vector<LL> propagate;

public:
    segmentTree(int n) {
        int p = ceil(log2(n));
        int mx = 2 * int(pow(2, p)) - 1;
        tree.assign(mx+1, 0);
        propagate.assign(mx+1, 0);
    }

    void update(int node, int s, int t, int rs, int rt, int val) {
        if(s > rt || t < rs) return;

        if(s >= rs && t <= rt) {
            tree[node] += LL(val) * (t-s+1);
            propagate[node] += val;
            return;
        }

        int left = (node<<1), right = (node<<1 | 1), mid = (s+t)>>1;

        update(left, s, mid, rs, rt, val);
        update(right, mid+1, t, rs, rt, val);

        tree[node] = tree[left] + tree[right] + (t-s+1) * propagate[node];
    }

    LL query(int node, int s, int t, int rs, int rt, LL carry) {
        if(s > rt || t < rs) return 0;

        if(s >= rs && t <= rt) return tree[node] + carry*(t-s+1);

        int left = (node<<1), right = (node<<1 | 1), mid = (s+t)>>1;

        LL p1 = query(left, s, mid, rs, rt, propagate[node]+carry);
        LL p2 = query(right, mid+1, t, rs, rt, propagate[node]+carry);

        return p1 + p2;
    }
};

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n, cmd;
        scanf("%d %d", &n, &cmd);

        segmentTree st(n);

        while(cmd--) {
            int type;
            scanf("%d", &type);

            if(type) {
                int p, q;
                scanf("%d %d", &p, &q);

                printf("%lld\n", st.query(1, 1, n, p, q, 0));
            }
            else {
                int p, q, v;
                scanf("%d %d %d", &p, &q, &v);

                st.update(1, 1, n, p, q, v);
            }
        }
    }

    return 0;
}
