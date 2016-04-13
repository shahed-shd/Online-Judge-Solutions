// By Square Root Decomposition.
// Run time : 0.324 sec.

#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

const int MAXN = 1e5+3;

class sqrtDecomposition {
    int bucketSize;
    vector<int> buckets;

public:
    sqrtDecomposition(int n) {
        bucketSize = sqrt(n);
        buckets.assign(bucketSize+1, INT_MAX);
    }

    void init(int arr[], int sz) {
        for(int i = 0; i < sz; ++i)
            buckets[i/bucketSize] = min(buckets[i/bucketSize], arr[i]);
    }

    int query(int arr[], int s, int t) {
        int bucketStart = s/bucketSize, bucketEnd = t/bucketSize;

        int mn = INT_MAX;

        if(bucketStart == bucketEnd) {
            for(int i = s; i <= t; ++i)
                mn = min(mn, arr[i]);

            return mn;
        }

        int tmp = (bucketStart+1) * bucketSize;

        for(int i = s; i < tmp; ++i) mn = min(mn, arr[i]);
        for(int i = bucketStart+1; i < bucketEnd; ++i) mn = min(mn, buckets[i]);
        for(int i = bucketEnd*bucketSize; i <= t; ++i) mn = min(mn, arr[i]);

        return mn;
    }
};

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, q;
        scanf("%d %d", &n, &q);

        int arr[n+3];

        for(int i = 0; i < n; ++i)
            scanf("%d", arr+i);

        sqrtDecomposition sd(n);

        sd.init(arr, n);

        printf("Case %d:\n", tc);

        while(q--) {
            int a, b;
            scanf("%d %d", &a, &b);

            printf("%d\n", sd.query(arr, a-1, b-1));
        }
    }

    return 0;
}


/*
// ---------------------- Alternatively (by Segment Tree) ----------------------
// Run time : 0.332 sec.

#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

const int MAXN = 1e5+3;

int arr[MAXN];

class segmentTree {
    vector<int> tree;

public:
    segmentTree(int n) {
        int x = ceil(log2(n));
        int mx = 2 * int(pow(2, x)) - 1;
        tree.resize(mx+1);
    }

    void init(int node, int s, int t) {
        if(s == t) {
            tree[node] = arr[s];
            return;
        }

        int left = (node<<1), right = (node<<1 | 1), mid = (s+t)>>1;

        init(left, s, mid);
        init(right, mid+1, t);

        tree[node] = min(tree[left], tree[right]);
    }

    int query(int node, int s, int t, int rs, int rt) {
        if(s > rt || t < rs) return INT_MAX;

        if(s >= rs && t <= rt) return tree[node];

        int left = (node<<1), right = (node<<1 | 1), mid = (s+t)>>1;

        int p1 = query(left, s, mid, rs, rt);
        int p2 = query(right, mid+1, t, rs, rt);

        return min(p1, p2);
    }
};

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, q;
        scanf("%d %d", &n, &q);

        for(int i = 1; i <= n; ++i)
            scanf("%d", arr+i);

        segmentTree st(n);

        st.init(1, 1, n);

        printf("Case %d:\n", tc);

        while(q--) {
            int rs, rt;
            scanf("%d %d", &rs, &rt);

            printf("%d\n", st.query(1, 1, n, rs, rt));
        }
    }

    return 0;
}


// ---------------------- Alternatively (by forming Sparse Table) ----------------------
// Run time : 0.676 sec.

#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<vector<int> > table;
vector<int> arr;

void formTable(int n)   // forming the sparse table.
{
    for(int j = 1; (1 << j) < n; ++j) {
        for(int i = 0; i < n; ++i) {
            if(int(table[i].size()) >= j && int(table[i-(1<<(j-1))].size()) >= j)
                table[i].push_back(min(table[i][j-1], table[i - (1 << (j-1))][j-1]));
        }
    }
}

int findMin(int a, int b)   // always a <= b, according to the problem description.
{
    if(a == b) return arr[a];

    int mini = INT_MAX;

    for(int i = log2(b-a); i >= 0; --i) {
        if(b - (1<<i) >= a) {
            mini = min(mini, table[b][i]);
            b -= (1 << i);
        }
    }

    return mini;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        table.clear();
        arr.clear();

        int n, q;
        scanf("%d %d", &n, &q);

        table.resize(n);
        arr.resize(n);

        scanf("%d", &arr[0]);

        for(int i = 1; i < n; ++i) {
            scanf("%d", &arr[i]);
            table[i].push_back(min(arr[i], arr[i-1]));
        }

        formTable(n);

        printf("Case %d:\n", tc);

        int a, b;
        while(q--) {
            scanf("%d %d", &a, &b);
            printf("%d\n", findMin(--a, --b));
        }
    }

    return 0;
}
*/
