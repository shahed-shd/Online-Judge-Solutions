// ==================================================
// Problem  :   1135 - Count the Multiples of 3
// Run time :   0.264 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

const int MAXN = 1e5 + 3;

struct treeNode {
    int cnt[4], prop;
};

treeNode tree[262143 + 3];  // 262143 = (1 << (ceil(log2(MAXN)) + 1)) - 1

inline void simulate_adding(int node, int add)
{
    if(add == 0) return;

    treeNode &reff = tree[node];

    if(add == 1) {
        int tmp = reff.cnt[3];
        reff.cnt[3] = reff.cnt[2];
        reff.cnt[2] = reff.cnt[1];
        reff.cnt[1] = reff.cnt[0] + tmp;
    }
    else if(add == 2) {
        int tmp = reff.cnt[2];
        reff.cnt[2] = reff.cnt[3] + reff.cnt[0];
        reff.cnt[3] = reff.cnt[1];
        reff.cnt[1] = tmp;
    }
    else if(add == 3) {
        reff.cnt[3] += reff.cnt[0];
    }

    reff.cnt[0] = 0;
}

inline void push_down(int node, int left, int right)
{
    if(!tree[node].prop) return;

    tree[node].prop %= 3;
    if(tree[node].prop == 0) tree[node].prop = 3;

    simulate_adding(left, tree[node].prop);
    simulate_adding(right, tree[node].prop);

    tree[left].prop += tree[node].prop;
    tree[right].prop += tree[node].prop;
    tree[node].prop = 0;
}

inline void push_up(int node, int left, int right)
{
    treeNode &A = tree[node], &L = tree[left], &R = tree[right];

    A.cnt[0] = L.cnt[0] + R.cnt[0];
    A.cnt[1] = L.cnt[1] + R.cnt[1];
    A.cnt[2] = L.cnt[2] + R.cnt[2];
    A.cnt[3] = L.cnt[3] + R.cnt[3];
}

void build(int node, int s, int t)
{
    treeNode &reff = tree[node];

    reff.cnt[1] = reff.cnt[2] = reff.cnt[3] = reff.prop = 0;
    reff.cnt[0] = t - s + 1;

    if(s == t) return;

    int mid = (s + t) >> 1;

    build(node<<1, s, mid);
    build((node<<1)|1, mid+1, t);
}

void update(int node, int s, int t, int rs, int rt, int val = 1)
{
    if(t < rs || rt < s) return;

    if(rs <= s && t <= rt) {
        simulate_adding(node, val);
        tree[node].prop += val;
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    push_down(node, left, right);

    update(left, s, mid, rs, rt, val);
    update(right, mid+1, t, rs, rt, val);

    push_up(node, left, right);
}

int query(int node, int s, int t, int rs, int rt)
{
    if(t < rs || rt < s) return 0;

    if(rs <= s && t <= rt)
        return tree[node].cnt[3] + tree[node].cnt[0];

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    push_down(node, left, right);

    int r1 = query(left, s, mid, rs, rt);
    int r2 = query(right, mid+1, t, rs, rt);

    return r1 + r2;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>(), q = fastIn<int>();

        build(1, 1, n);

        printf("Case %d:\n", tc);
        int type, i, j;

        while(q--) {
            type = fastIn<int>(), i = fastIn<int>(), j = fastIn<int>();
            ++i, ++j;

            if(type)
                printf("%d\n", query(1, 1, n, i, j));
            else
                update(1, 1, n, i, j);
        }
    }

    return 0;
}
