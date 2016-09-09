// ==================================================
// Problem  :   1183 - Computing Fast Average
// Run time :   0.256 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct treeNode {
    int sum, prop;
    treeNode(int s = 0, int p = -1) { sum = s, prop = p; }
};

const int SZ = 262143 + 3;  // MAXN = 1e5 + 3;
                            // 262143 = 2 * pow(2, ceil(log2(n))) - 1
treeNode tree[SZ];

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

inline void pushDown(int node, int s, int t)
{
    if(tree[node].prop == -1) return;

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    tree[left].prop = tree[right].prop = tree[node].prop;
    tree[node].prop = -1;

    tree[left].sum = tree[left].prop * (mid - s + 1);
    tree[right].sum = tree[right].prop * (t - (mid+1) + 1);
}

void update(int node, int s, int t, int rs, int rt, int newVal)
{
    if(t < rs || rt < s) return;
    if(rs <= s && t <= rt) {
        tree[node].sum = newVal * (t-s+1);
        tree[node].prop = newVal;
        return;
    }

    pushDown(node, s, t);

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    update(left, s, mid, rs, rt, newVal);
    update(right, mid+1, t, rs, rt, newVal);

    tree[node].sum = tree[left].sum + tree[right].sum;
}

int gcd(int m, int n)
{
    while(n != 0) {
        int t = m % n;
        m = n;
        n = t;
    }

    return m;
}

int query(int node, int s, int t, int rs, int rt)
{
    if(t < rs || rt < s) return 0;

    if(rs <= s && t <= rt) return tree[node].sum;

    pushDown(node, s, t);

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    return query(left, s, mid, rs, rt) + query(right, mid+1, t, rs, rt);
}

int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>(), q = fastIn<int>();

        int sz = (1 << (int(ceil(log2(n))) + 1)) - 1;
        fill(tree, tree+sz+3, treeNode());

        printf("Case %d:\n", tc);

        int type, i, j, v;

        while(q--) {
            type = fastIn<int>();

            if(type == 1) {
                i = fastIn<int>(), j = fastIn<int>(), v = fastIn<int>();
                ++i, ++j;
                update(1, 1, n, i, j, v);
            }
            else {
                i = fastIn<int>(), j = fastIn<int>();
                ++i, ++j;
                int sum = query(1, 1, n, i, j);
                int freq = j - i + 1;
                int g = gcd(sum, freq);

                sum /= g;
                freq /= g;

                if(freq == 1) printf("%d\n", sum);
                else printf("%d/%d\n", sum, freq);
            }
        }
    }

    return 0;
}
