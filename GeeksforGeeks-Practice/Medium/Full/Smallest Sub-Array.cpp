// ==================================================
// Problem  :   Smallest Sub-Array
// Run time :   0.065 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 30 + 3;
const int SZ = 127 + 3;     // 127 = (1 << int(math.ceil(math.log2(MAXN))) + 1) - 1
const int INF = INT_MAX;

int k, n, arr[MAXN];
int tree[SZ];

int gcd(int m, int n)
{
    while (n != 0) {
        int t = m % n;
        m = n;
        n = t;
	}

    return m;
}

void build(int node, int s, int t)
{
    if(s == t) {
        tree[node] = arr[s];
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    build(left, s, mid);
    build(right, mid+1, t);

    tree[node] = gcd(tree[left], tree[right]);
}

int query(int node, int s, int t, int rs, int rt)
{
    if(t < rs || rt < s) return -1;

    if(rs <= s && t <= rt) return tree[node];

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    int q1 = query(left, s, mid, rs, rt);
    int q2 = query(right, mid+1, t, rs, rt);

    if(q1 == -1) return q2;
    if(q2 == -1) return q1;

    return gcd(q1, q2);
}

int binSearch(int start, int s, int t)
{
    int ret = INF;

    while(s <= t) {
        int mid = (s + t) >> 1;
        int q = query(1, 1, n, start, mid);

        if(q < k) {
            t = mid - 1;
        }
        else if(k < q) {
            s = mid + 1;
        }
        else {      // k == q
            ret = min(ret, mid);
            t = mid - 1;
        }
    }

    return ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &k, &n);

        for(int i = 1; i <= n; ++i) scanf("%d", arr+i);

        build(1, 1, n);

        int ans = INF;

        for(int i = 1; i <= n; ++i) {
            if(arr[i] % k == 0) {
                int idx = binSearch(i, i+1, n);
                if(idx != INF) ans = min(ans, idx - i + 1);
            }
        }

        if(ans == INF) puts("-1");
        else printf("%d\n", ans);
    }

    return 0;
}
