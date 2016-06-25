#include <cstdio>
#include <stack>
using namespace std;

typedef     pair<int,int>       ii;

template<class T>
inline T fastIn()
{
    register char ch = 0;
    register T a = 0;
    bool neg = false;

    while(ch < 33) ch = getchar();

    if(ch == '-') neg = true;
    else a = ch - '0';

    while(ch = getchar(), ch > 33)
        a = a * 10 + (ch - '0');

    return ((neg)? -a : a);
}

int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>();

        int arr[n+3], left[n+3], right[n+3];

        for(int i = 1; i <= n; ++i) {
            arr[i] = fastIn<int>();
            left[i] = right[i] = i;
        }

        stack<ii> st;

        for(int i = 1; i <= n; ++i) {
            if(st.empty() || arr[i] >= st.top().first) {
                st.push(ii(arr[i], i));
            }
            else {
                while(!st.empty() && arr[i] < st.top().first) {
                    left[i] = left[st.top().second];
                    right[st.top().second] = i-1;
                    st.pop();
                }

                st.push(ii(arr[i], i));
            }
        }

        while(!st.empty()) {
            right[st.top().second] = n;
            st.pop();
        }

        int mx = 0;

        for(int i = 1; i <= n; ++i)
            mx = max(mx, arr[i] * (right[i]-left[i]+1));

        printf("Case %d: %d\n", tc, mx);
    }

    return 0;
}


// -------------------- Alternatively (with Segment Tree) --------------------
/*
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 30000+3, MAXT = 65535;     // ((1 << int(ceil(log2(MAXN)))) << 1) - 1.

int n, arr[MAXN];

class segmentTree {
    int tree[MAXT];

    int min_val_idx(int a, int b) { return ((arr[a] < arr[b])? a : b); }

public:
    void init(int node, int s, int t) {
        if(s == t) {
            tree[node] = s;
            return;
        }

        int left = node<<1, right = left+1, mid = (s+t)>>1;

        init(left, s, mid);
        init(right, mid+1, t);

        tree[node] = min_val_idx(tree[left], tree[right]);
    }

    int query(int node, int s, int t, int rs, int rt) {
        if(t < rs || rt < s) return n+1;
        if(rs <= s && t <= rt) return tree[node];

        int left = node<<1, right = left+1, mid = (s+t)>>1;

        return min_val_idx(query(left, s, mid, rs, rt), query(right, mid+1, t, rs, rt));
    }
} segTree;

int rec(int s, int t)
{
    if(s > t) return 0;

    int mn = segTree.query(1, 1, n, s, t);

    int tmp = max(rec(s, mn-1), rec(mn+1, t));

    return max(tmp, arr[mn]*(t-s+1));
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        for(int i = 1; i <= n; ++i) scanf("%d", arr+i);
        arr[n+1] = INT_MAX;

        segTree.init(1, 1, n);

        printf("Case %d: %d\n", tc, rec(1, n));
    }

    return 0;
}
*/
