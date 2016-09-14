// ==================================================
// Problem  :   1187 - Lining up Students
// Run time :   0.068 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

template <class T>
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

int main()
{
    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>();

        int a, ans = 1;
        fastIn<int>();  // Feed the first value.

        for(int i = 2; i <= n; ++i) {
            a = fastIn<int>();
            if(i - a <= ans) ++ans;
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}


// -------------------- Alternatively (with Segment Tree) --------------------
// Run time	:	0.180 sec.
/*
#include <cstdio>
using namespace std;

template <class T>
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
const int SZ = 262143 + 3;       // 262143 = (1 << (ceil(log2(MAXN)) + 1)) - 1

int arr[MAXN];
int tree[SZ];

void build(int node, int s, int t)
{
    if(s == t) {
        tree[node] = 1;
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    build(left, s, mid);
    build(right, mid+1, t);

    tree[node] = tree[left] + tree[right];
}

int del(int node, int s, int t, int val)
{
    if(s == t) {
        tree[node] = 0;
        return s;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;
    --tree[node];

    if(tree[left] >= val)
        return del(left, s, mid, val);
    else
        return del(right, mid+1, t, val - tree[left]);
}

int main()
{
    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>();

        for(int i = 1; i <= n; ++i)
            arr[i] = fastIn<int>();

        build(1, 1, n);

        for(int i = n; i > 1; --i)  // Loop (n-1) times.
            del(1, 1, n, i-arr[i]);

        printf("Case %d: %d\n", tc, del(1, 1, n, 1-arr[1]));
    }

    return 0;
}
*/
