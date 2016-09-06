// ==================================================
// Problem  :   1339 - Strongest Community
// Run time :   0.360 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 3;

struct treeNode {
    int most, lhsVal, lhsFreq, rhsVal, rhsFreq;
    treeNode() {
        most = lhsVal = lhsFreq = rhsVal = rhsFreq = 0;
    }
};

int arr[MAXN];
treeNode tree[262143 + 3];  // 262143 = 2 * int(pow(2, ceil(log2(MAXN)))) - 1

inline void update_from_child(treeNode &A, treeNode &L, treeNode &R)
{
    A.most = max(L.most, R.most);
    if(L.rhsVal == R.lhsVal) A.most = max(A.most, L.rhsFreq + R.lhsFreq);

    A.lhsVal = L.lhsVal;
    A.lhsFreq = L.lhsFreq;
    if(L.lhsVal == R.lhsVal) A.lhsFreq += R.lhsFreq;

    A.rhsVal = R.rhsVal;
    A.rhsFreq = R.rhsFreq;
    if(L.rhsVal == R.rhsVal) A.rhsFreq += L.rhsFreq;
}

void init(int node, int s, int t) {
    if(s == t) {
        treeNode &A = tree[node];
        A.lhsVal = A.rhsVal = arr[s];
        A.lhsFreq = A.rhsFreq = A.most = 1;
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    init(left, s, mid);
    init(right, mid+1, t);

    update_from_child(tree[node], tree[left], tree[right]);
}

treeNode query(int node, int s, int t, int rs, int rt)
{
    if(t < rs || rt < s) return treeNode();

    if(rs <= s && t <= rt) return tree[node];

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    treeNode p1 = query(left, s, mid, rs, rt);
    treeNode p2 = query(right, mid+1, t, rs, rt);

    treeNode ret;

    update_from_child(ret, p1, p2);

    return ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, c, q;
        scanf("%d %d %d", &n, &c, &q);

        for(int i = 1; i <= n; ++i)
            scanf("%d", arr+i);

        init(1, 1, n);

        printf("Case %d:\n", tc);

        int rs, rt;

        while(q--) {
            scanf("%d %d", &rs, &rt);
            printf("%d\n", query(1, 1, n, rs, rt).most);
        }
    }

    return 0;
}
