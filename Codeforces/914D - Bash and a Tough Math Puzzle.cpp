// ==================================================
// Problem  :   914D - Bash and a Tough Math Puzzle
// Run time :   0.919 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
using namespace std;


const int MAXN = 5e5 + 3;
const int SZ = 1048575 + 3;     // (1 << (ceil(log2(MAXN)) + 1)) - 1

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
        scanf("%d", &tree[node]);
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    build(left, s, mid);
    build(right, mid+1, t);

    tree[node] = gcd(tree[left], tree[right]);
}


void update(int node, int s, int t, int idx, int val)
{
    if(t < idx or idx < s) return;

    if(s == t) {
        tree[node] = val;
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    update(left, s, mid, idx, val);
    update(right, mid+1, t, idx, val);

    tree[node] = gcd(tree[left], tree[right]);
}


int query_gcd(int node, int s, int t, int rs, int rt)
{
    if(t < rs or rt < s) return -1;

    if(rs <= s and t <= rt) return tree[node];

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    int q1 = query_gcd(left, s, mid, rs, rt);
    int q2 = query_gcd(right, mid+1, t, rs, rt);

    if(q1 == -1)
        return q2;
    else if(q2 == -1)
        return q1;
    else
        return gcd(q1, q2);
}


int query_find(int node, int s, int t, int rs, int rt, int x)
{
    if(t < rs or rt < s) return 0;

    if(s == t) {
        return ((tree[node] % x)? 1 : 0);
    }

    if(rs <= s and t <= rt) {
        if(tree[node] % x == 0)
            return 0;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    int q1 = query_find(left, s, mid, rs, rt, x);
    if(q1 > 1) return q1;

    int q2 = query_find(right, mid+1, t, rs, rt, x);
    return (q1 + q2);
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    build(1, 1, n);

    int q;
    scanf("%d", &q);

    while(q--) {
        int qry_type;
        scanf("%d", &qry_type);

        if(qry_type == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);

            bool ans = false;
            int g = query_gcd(1, 1, n, l, r);

            if(g % x == 0)
                ans = true;
            else
                ans = query_find(1, 1, n, l, r, x) == 1;

            puts(ans? "YES" : "NO");
        }
        else {
            int idx, val;
            scanf("%d %d", &idx, &val);
            update(1, 1, n, idx, val);
        }
    }

    return 0;
}
