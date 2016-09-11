// ==================================================
// Problem  :   1164 - Horrible Queries
// Run time :   0.256 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef     long long       LL;

template<class T>
inline T fastIn()
{
    register T a = 0;
    register char c = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

const int SZ = 262143 + 3;

LL treeSum[SZ], treeProp[SZ];  // MAXN = 1e5 + 3
                                // 262143 = (1 << (int(ceil(log2(MAXN))) + 1)) - 1
void build(int n)
{
    int sz = (1 << (int(ceil(log2(n))) + 1)) - 1;
    fill(treeSum, treeSum+sz+3, 0);
    fill(treeProp, treeProp+sz+3, 0);
}

void update(int node, int s, int t, int rs, int rt, int val)
{
    if(t < rs || rt < s) return;
    if(rs <= s && t <= rt) {
        treeSum[node] += val * (t - s + 1);
        treeProp[node] += val;
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    update(left, s, mid, rs, rt, val);
    update(right, mid+1, t, rs, rt, val);

    treeSum[node] = treeSum[left] + treeSum[right] + (t - s + 1) * treeProp[node];
}

LL query(int node, int s, int t, int rs, int rt, LL lazy)
{
    if(t < rs || rt < s) return 0;
    if(rs <= s && t <= rt) {
        return treeSum[node] + lazy * (t - s + 1);
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    LL s1 = query(left, s, mid, rs, rt, lazy+treeProp[node]);
    LL s2 = query(right, mid+1, t, rs, rt, lazy+treeProp[node]);

    return s1 + s2;
}

int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>(), q = fastIn<int>();

        printf("Case %d:\n", tc);

        build(n);
        int type, x, y;

        while(q--) {
            type = fastIn<int>(), x = fastIn<int>(), y = fastIn<int>();
            ++x, ++y;

            if(type)
                printf("%lld\n", query(1, 1, n, x, y, 0));
            else
                update(1, 1, n, x, y, fastIn<int>());
        }
    }

    return 0;
}
