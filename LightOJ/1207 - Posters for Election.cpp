// ==================================================
// Problem  :   1207 - Posters for Election
// Run time :   0.324 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
#include <cmath>
using namespace std;

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

const int MAXN = 1e5 + 3;
const int SZ = 524287 + 3;  // 524287 = (1 << int(ceil(log2(MAXN*2))+1)) - 1

int treeColor[SZ];
bitset<MAXN> vis;
int ans;

void init(int n)
{
    n <<= 1;
    int range = (1 << int(ceil(log2(n))+1)) - 1;
    fill(treeColor, treeColor+range+3, 0);
    vis.reset();
}

inline void pushDown(int node, int left, int right)
{
    treeColor[left] = treeColor[right] = treeColor[node];
    treeColor[node] = 0;
}

void update(int node, int s, int t, int rs, int rt, int col)
{
    if(t < rs || rt < s) return;
    if(rs <= s && t <= rt) {
        treeColor[node] = col;
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    if(treeColor[node]) pushDown(node, left, right);

    update(left, s, mid, rs, rt, col);
    update(right, mid+1, t, rs, rt, col);
}

void query(int node, int s, int t)
{
    if(treeColor[node]) {
        if(!vis[treeColor[node]])
            ++ans, vis[treeColor[node]] = true;
        return;
    }

    if(s == t) return;

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    query(left, s, mid);
    query(right, mid+1, t);
}

int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>();

        init(n);
        int li, ri;

        for(int i = 1; i <= n; ++i) {
            li = fastIn<int>(), ri = fastIn<int>();
            update(1, 1, n<<1, li, ri, i);
        }

        ans = 0;
        query(1, 1, n<<1);

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
