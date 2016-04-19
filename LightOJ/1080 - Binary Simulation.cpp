// Run time : 0.208 sec

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1e5+5;

class BinIdxTree {
    int tree[MAXN] = {0};
    int maxIdx;

public:
    BinIdxTree(int n) { maxIdx = n; }

    void update(int idx, int val) {
        while(idx <= maxIdx) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;

        while(idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }

        return sum;
    }
};

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        char str[MAXN];
        scanf("%s", str);

        int len = strlen(str);

        for(int i = len; i >= 0; --i)
            str[i+1] = str[i] - '0';

        int qry;
        scanf("%d\n", &qry);

        printf("Case %d:\n", tc);

        BinIdxTree bit(len);

        while(qry--) {
            char type;
            scanf("%c", &type);

            if(type == 'I') {
                int rs, rt;
                scanf("%d %d\n", &rs, &rt);

                bit.update(rs, 1);
                bit.update(rt+1, -1);
            }
            else {
                int idx;
                scanf("%d\n", &idx);

                printf("%d\n", ((bit.query(idx) & 1)? 1-str[idx] : str[idx]));
            }
        }
    }

    return 0;
}


// ---------------------------- Alternatively ----------------------------
// Run time : 0.380 sec.
/*
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1e5+5;

class segmentTree {
    int tree[MAXN*4] = {0};

public:
    void update(int node, int s, int t, int rs, int rt) {
        if(s > rt || t < rs) return;

        if(s >= rs && t <= rt) {
            ++tree[node];
            return;
        }

        int left = (node<<1), right = (node<<1 | 1), mid = (s+t)>>1;

        update(left, s, mid, rs, rt);
        update(right, mid+1, t, rs, rt);
    }

    int query(int node, int s, int t, int idx) {
        if(idx < s || idx > t) return 0;

        if(s == t) return tree[node];

        int left = (node<<1), right = (node<<1 | 1), mid = (s+t)>>1;

        return query(left, s, mid, idx) + query(right, mid+1, t, idx) + tree[node];
    }

};

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        char str[MAXN];
        scanf("%s", str);

        int len = strlen(str);

        for(int i = len; i >= 0; --i)
            str[i+1] = str[i] - '0';

        int qry;
        scanf("%d\n", &qry);

        segmentTree ST;

        printf("Case %d:\n", tc);

        while(qry--) {
            char type;
            scanf("%c", &type);

            if(type == 'I') {
                int rs, rt;
                scanf("%d %d\n", &rs, &rt);
                ST.update(1, 1, len, rs, rt);
            }
            else {
                int idx;
                scanf("%d\n", &idx);
                printf("%d\n", str[idx] ^ (ST.query(1, 1, len, idx) & 1));
            }
        }
    }

    return 0;
}
*/
