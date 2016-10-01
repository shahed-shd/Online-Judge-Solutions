// ==================================================
// Problem  :   313B - Ilya and Queries
// Run time :   0.218 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 1e5 + 3;
const int SZ = 262143 + 3;  // 262143 = (1 << (ceil(log2(MAXL)) + 1)) - 1

char str[MAXL];

int tree[SZ];

void build(int node, int s, int t)
{
    if(s == t) {
        tree[node] = 0;
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    build(left, s, mid);
    build(right, mid+1, t);

    tree[node] = tree[left] + tree[right] + (str[mid] == str[mid+1]);
}

int query(int node, int s, int t, int rs, int rt)
{
    if(t < rs || rt < s) return 0;

    if(rs <= s && t <= rt) return tree[node];

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    int q1 = query(left, s, mid, rs, rt);
    int q2 = query(right, mid+1, t, rs, rt);

    return q1 + q2 + (rs <= mid && mid <= rt && rs <= mid+1 && mid+1 <= rt && str[mid] == str[mid+1]);
}

int main()
{
    fgets(&str[1], MAXL-1, stdin);

    int len = 1 + strlen(&str[1]);
    if(str[len-1] == '\n') str[len-1] = '\0', --len;

    build(1, 1, len-1);

    int m, left, right;
    scanf("%d", &m);

    while(m--) {
        scanf("%d %d", &left, &right);

        printf("%d\n", query(1, 1, len-1, left, right));
    }

    return 0;
}
