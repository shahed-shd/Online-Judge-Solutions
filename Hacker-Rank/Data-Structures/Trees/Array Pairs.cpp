// ==================================================
// Problem  :   Array Pairs
// Score    :   100 /100
// Language :   C++14
// ==================================================


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


typedef     long long       LL;

const int MAXN = 5e5 + 3;
const int SZ = 1048575 + 3;     // 1048575 = (1 << (ceil(log2(n)) + 1)) - 1

int n, a[MAXN];

struct Node {
    int mx_elem_idx;
    vector<int> v;
};

Node tree[SZ];


// Initialize the segment tree.
void init(int node, int s, int t)
{
    if(s == t) {
        tree[node].mx_elem_idx = s;
        tree[node].v.push_back(a[s]);
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    init(left, s, mid);
    init(right, mid+1, t);

    // Merge
    int li = tree[left].mx_elem_idx;
    int ri = tree[right].mx_elem_idx;
    
    tree[node].mx_elem_idx = (a[li] <= a[ri])? ri : li;

    vector<int> &lv = tree[left].v;
    vector<int> &rv = tree[right].v;
    vector<int> &nv = tree[node].v;
    
    int ls = lv.size();
    int rs = rv.size();

    int i = 0, j = 0;

    while(i < ls and j < rs) {
        if(lv[i] <= rv[j])
            nv.push_back(lv[i++]);
        else
            nv.push_back(rv[j++]);
    }

    while(i < ls) nv.push_back(lv[i++]);
    while(j < rs) nv.push_back(rv[j++]);
}


// Query on segment tree for the index of max element in a[rs to rt].
int query_mx_elem_idx(int node, int s, int t, int rs, int rt)
{
    if(t < rs or rt < s) return 0;

    if(rs <= s and t <= rt) {
        return tree[node].mx_elem_idx;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    int q1 = query_mx_elem_idx(left, s, mid, rs, rt);
    int q2 = query_mx_elem_idx(right, mid+1, t, rs, rt);

    return ((a[q1] <= a[q2])? q2: q1);
}


// Query on segment tree for the count of values which are less than or equeal to val.
int query_count_le(int node, int s, int t, int rs, int rt, int val)
{
    if(t < rs or rt < s) return 0;

    if(rs <= s and t <= rt) {
        vector<int> &nv = tree[node].v;
        return upper_bound(nv.begin(), nv.end(), val) - nv.begin();
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    int q1 = query_count_le(left, s, mid, rs, rt, val);
    int q2 = query_count_le(right, mid+1, t, rs, rt, val);

    return q1 + q2;
}


LL div_n_conq(int s, int t)
{
    if(s >= t) return 0;

    int mi = query_mx_elem_idx(1, 1, n, s, t);
    int loops, loopt, rs, rt;

    if(mi - s < t - mi){
        loops = s, loopt = mi;
        rs = mi, rt = t;
    }
    else {
        loops = mi, loopt = t;
        rs = s, rt = mi;
    }

    LL cnt = 0;

    for(int i = loops; i <= loopt; ++i) {
        cnt += query_count_le(1, 1, n, rs, rt, a[mi]/a[i]);
        if(a[mi] == 1) --cnt;
    }

    cnt += div_n_conq(s, mi-1);
    cnt += div_n_conq(mi+1, t);

    return cnt;
}


int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    
    init(1, 1, n);

    LL ans = div_n_conq(1, n);

    printf("%lld\n", ans);

    return 0;
}
