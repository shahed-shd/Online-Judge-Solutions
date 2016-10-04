// ==================================================
// Problem  :   1411 - Rip Van Winkle`s Code
// Run time :   1.268 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

typedef     long long       LL;

const int MAXR = 250000;
const int SZ = 524287 + 3;      // 524287 = (1 << (int(ceil(log2(250001))) + 1)) - 1
const int INF = LLONG_MAX;

LL tree_sum[SZ], tree_st[SZ], tree_nd[SZ], tree_x[SZ];
int tree_st_cnt[SZ], tree_nd_cnt[SZ];

inline void push_down_x(int node, int s, int t, int left, int right)
{
    if(tree_x[node] != INF) {
        int mid = (s + t) >> 1;

        tree_x[left] = tree_x[right] = tree_x[node];

        tree_sum[left] = (mid - s + 1) * tree_x[left];
        tree_sum[right] = (t - (mid+1) + 1) * tree_x[right];

        tree_st[left] = tree_st_cnt[left] = tree_nd[left] = tree_nd_cnt[left] = 0;
        tree_st[right] = tree_st_cnt[right] = tree_nd[right] = tree_nd_cnt[right] = 0;

        tree_x[node] = INF;
    }
}

inline void push_down_st(int node, int s, int t, int left, int right)
{
    if(tree_st[node]) {
        int mid = (s + t) >> 1;

        tree_st[left] += tree_st[node];
        tree_st[right] += tree_st[node];

        tree_st_cnt[left] += tree_st_cnt[node];
        tree_st_cnt[right] += tree_st_cnt[node];

        LL a = tree_st_cnt[node] * s - tree_st[node] + tree_st_cnt[node];
        LL p = tree_st_cnt[node] * mid - tree_st[node] + tree_st_cnt[node];
        LL n = mid - s + 1;
        tree_sum[left] += n * (a + p) / 2;          // sum of an Arithmetic Series = n * (a + p) / 2

        a = tree_st_cnt[node] * (mid+1) - tree_st[node] + tree_st_cnt[node];
        p = tree_st_cnt[node] * t - tree_st[node] + tree_st_cnt[node];
        n = t - (mid+1) + 1;
        tree_sum[right] += n * (a + p) / 2;

        tree_st[node] = tree_st_cnt[node] = 0;
    }
}

inline void push_down_nd(int node, int s, int t, int left, int right)
{
    if(tree_nd[node]) {
        int mid = (s + t) >> 1;

        tree_nd[left] += tree_nd[node];
        tree_nd[right] += tree_nd[node];

        tree_nd_cnt[left] += tree_nd_cnt[node];
        tree_nd_cnt[right] += tree_nd_cnt[node];

        LL a = tree_nd[node] - tree_nd_cnt[node] * s + tree_nd_cnt[node];
        LL p = tree_nd[node] - tree_nd_cnt[node] * mid + tree_nd_cnt[node];
        LL n = mid - s + 1;
        tree_sum[left] += n * (a + p) / 2;

        a = tree_nd[node] - tree_nd_cnt[node] * (mid+1) + tree_nd_cnt[node];
        p = tree_nd[node] - tree_nd_cnt[node] * t + tree_nd_cnt[node];
        n = t - (mid+1) + 1;
        tree_sum[right] += n * (a + p) / 2;

        tree_nd[node] = tree_nd_cnt[node] = 0;
    }
}

void build()
{
    fill(tree_sum, tree_sum+SZ, 0);

    fill(tree_st, tree_st+SZ, 0);
    fill(tree_nd, tree_nd+SZ, 0);
    fill(tree_x, tree_x+SZ, INF);

    fill(tree_st_cnt, tree_st_cnt+SZ, 0);
    fill(tree_nd_cnt, tree_nd_cnt+SZ, 0);
}

void updateA(int node, int s, int t, int rs, int rt, int st)
{
    if(t < rs || rt < s) return;
    if(rs <= s && t <= rt) {
        int a = s - st + 1;
        int p = t - st + 1;
        int n = t - s + 1;

        tree_sum[node] += (n * (LL(a) + p)) / 2;

        tree_st[node] += st;
        ++tree_st_cnt[node];
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    push_down_x(node, s, t, left, right);
    push_down_st(node, s, t, left, right);
    push_down_nd(node, s, t, left, right);

    updateA(left, s, mid, rs, rt, st);
    updateA(right, mid+1, t, rs, rt, st);

    tree_sum[node] = tree_sum[left] + tree_sum[right];
}

void updateB(int node, int s, int t, int rs, int rt, int nd)
{
    if(t < rs || rt < s) return;
    if(rs <= s && t <= rt) {
        int a = nd - s + 1;
        int p = nd - t + 1;
        int n = t - s + 1;

        tree_sum[node] += (n * (LL(a)+p)) / 2;

        tree_nd[node] += nd;
        ++tree_nd_cnt[node];
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    push_down_x(node, s, t, left, right);
    push_down_st(node, s, t, left, right);
    push_down_nd(node, s, t, left, right);

    updateB(left, s, mid, rs, rt, nd);
    updateB(right, mid+1, t, rs, rt, nd);

    tree_sum[node] = tree_sum[left] + tree_sum[right];
}

void updateC(int node, int s, int t, int rs, int rt, int x)
{
    if(t < rs || rt < s) return;
    if(rs <= s && t <= rt) {
        tree_sum[node] = (t - s + 1) * LL(x);
        tree_x[node] = x;

        tree_st[node] = tree_st_cnt[node] = tree_nd[node] = tree_nd_cnt[node] = 0;
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    push_down_x(node, s, t, left, right);
    push_down_st(node, s, t, left, right);
    push_down_nd(node, s, t, left, right);

    updateC(left, s, mid, rs, rt, x);
    updateC(right, mid+1, t, rs, rt, x);

    tree_sum[node] = tree_sum[left] + tree_sum[right];
}

LL query(int node, int s, int t, int rs, int rt)
{
    if(t < rs || rt < s) return 0;
    if(rs <= s && t <= rt) {
        return tree_sum[node];
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    push_down_x(node, s, t, left, right);
    push_down_st(node, s, t, left, right);
    push_down_nd(node, s, t, left, right);

    LL q1 = query(left, s, mid, rs, rt);
    LL q2 = query(right, mid+1, t, rs, rt);

    return q1 + q2;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        printf("Case %d:\n", tc);

        build();

        char type;
        int st, nd, x;

        while(n--) {
            scanf("\n%c %d %d", &type, &st, &nd);

            if(type == 'A') {
                updateA(1, 1, MAXR, st, nd, st);
            }
            else if(type == 'B') {
                updateB(1, 1, MAXR, st, nd, nd);
            }
            else if(type == 'C') {
                scanf("%d", &x);
                updateC(1, 1, MAXR, st, nd, x);
            }
            else {
                printf("%lld\n", query(1, 1, MAXR, st, nd));
            }
        }
    }

    return 0;
}
