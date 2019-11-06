// ==================================================
// Problem  :   1234D - Distinct Characters Queries
// Run time :   0.140 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 3;
const int MAXT = 262143 + 3;    // 262143 = (1 << (1 + ceil(log2(MAXN)))) - 1

int tree[MAXT];
char inpStr[MAXN];


int countSetBits(int mask) {
    int count = 0;

    while(mask) {
        mask = mask & (mask - 1);
        ++count;
    }

    return count;
}


int getMaskFor(char ch) {
    return (1 << (ch - 'a'));
}


void build(int node, int s, int t) {
    if(s == t) {
        tree[node] = getMaskFor(inpStr[s]);
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    build(left, s, mid);
    build(right, mid+1, t);

    tree[node] = tree[left] | tree[right];
}


void update(int node, int s, int t, int idx, char ch) {
    if(s == t) {
        tree[node] = getMaskFor(inpStr[idx]);
        return;
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    if(idx <= mid) {
        update(left, s, mid, idx, ch);
    } else {
        update(right, mid+1, t, idx, ch);
    }

    tree[node] = tree[left] | tree[right];
}


int queryMask(int node, int s, int t, int rs, int rt) {
    if(t < rs or rt < s) return 0;

    if(rs <= s and t <= rt) {
        return tree[node];
    }

    int left = node << 1, right = left | 1, mid = (s + t) >> 1;

    return (queryMask(left, s, mid, rs, rt) | queryMask(right, mid+1, t, rs, rt));
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    scanf("%s", inpStr+1);      // 1 based index
    int len = strlen(inpStr+1);

    build(1, 1, len);

    int q;
    scanf("%d", &q);

    while(q--) {
        int qryType;
        scanf("%d", &qryType);

        if(qryType == 1) {
            int pos;
            char ch;
            scanf("%d %c", &pos, &ch);

            inpStr[pos] = ch;
            update(1, 1, len, pos, ch);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            int mask = queryMask(1, 1, len, l, r);
            int ans = countSetBits(mask);
            printf("%d\n", ans);
        }
    }

    return 0;
}
