// ==================================================
// Problem  :   1097 - Lucky Number
// Run time :   0.200 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

const int MAXS = 1429431 + 3;
const int SZ = 4194303 + 3;     // 4194303 = (1 << (ceil(log2(n)) + 1)) - 1

int tree[SZ];

void build(int node, int s, int t)
{
    if(s == t) {
        tree[node] = s & 1;
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    build(left, s, mid);
    build(right, mid+1, t);

    tree[node] = tree[left] + tree[right];
}

void del(int node, int s, int t, int pos)
{
    if(s == t) {
        tree[node] = 0;
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    if(pos <= tree[left])
        del(left, s, mid, pos);
    else
        del(right, mid+1, t, pos-tree[left]);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int s, int t, int pos)
{
    if(s == t)
        return s;

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    if(pos <= tree[left])
        return query(left, s, mid, pos);
    else
        return query(right, mid+1, t, pos-tree[left]);
}

void init()
{
    build(1, 1, MAXS);

    int pos = 2;

    while(pos <= tree[1]) {
        int val = query(1, 1, MAXS, pos);
        int delPos = val;

        while(delPos <= tree[1]) {
            del(1, 1, MAXS, delPos);
            delPos += val - 1;
        }

        ++pos;
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    init();

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        printf("Case %d: %d\n", tc, query(1, 1, MAXS, n));
    }

    return 0;
}
