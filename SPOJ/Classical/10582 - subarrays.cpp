#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+3, MAXT = 2097151;     // 2097151 = ((1 << int(ceil(log2(MAXN)))) << 1) - 1;

int arr[MAXN];

class segmentTree {
    int tree[MAXT];
public:
    void init(int node, int s, int t) {
        if(s == t) {
            tree[node] = arr[s];
            return;
        }

        int left = node<<1, right = left+1, mid = (s+t)>>1;

        init(left, s, mid);
        init(right, mid+1, t);

        tree[node] = max(tree[left], tree[right]);
    }

    int query(int node, int s, int t, int rs, int rt) {
        if(t < rs || rt < s) return 0;
        if(rs <= s && t <= rt) return tree[node];

        int left = node<<1, right = left+1, mid = (s+t)>>1;

        return max(query(left, s, mid, rs, rt), query(right, mid+1, t, rs, rt));
    }
} segTree;

int main()
{
    //freopen("in", "r", stdin);

    int n;

    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= n; ++i)
            scanf("%d", arr+i);

        int k;
        scanf("%d", &k);

        segTree.init(1, 1, n);

        for(int i = k; i <= n; ++i) {
            printf("%d", segTree.query(1, 1, n, i-k+1, i));
            if(i < n) putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}
