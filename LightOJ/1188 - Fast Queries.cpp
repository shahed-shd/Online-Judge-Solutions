// ==================================================
// Problem  :   1188 - Fast Queries
// Run time :   0.244 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 3;
const int MAXQ = 50000 + 3;

struct qry {
    int L, R, serial;

    bool operator<(const qry &ob) const {
        return R < ob.R;
    }
};

int n, arr[MAXN];
qry queries[MAXQ];

int tree[MAXN];

void update(int idx, int val)
{
    while(idx <= n) {
        tree[idx] +=  val;
        idx += idx & (-idx);
    }
}

int query(int idx)
{
    int sum = 0;

    while(idx > 0) {
        sum += tree[idx];
        idx -= idx & (-idx);
    }

    return sum;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int q;
        scanf("%d %d", &n, &q);

        for(int i = 1; i <= n; ++i)
            scanf("%d", arr+i);

        for(int i = 0; i < q; ++i) {
            scanf("%d %d", &queries[i].L, &queries[i].R);
            queries[i].serial = i;
        }

        sort(queries, queries+q);
        fill(tree, tree+n+1, 0);

        int prevFoundIdx[MAXN] = {0}, ans[MAXN];
        int qryIdx = 0;

        for(int i = 1; i <= n; ++i) {
            if(prevFoundIdx[arr[i]])
                update(prevFoundIdx[arr[i]], -1);

            prevFoundIdx[arr[i]] = i;
            update(i, 1);

            if(queries[qryIdx].R == i) {
                int qry_upto_i = query(i);

                while(qryIdx < q && queries[qryIdx].R == i) {
                    ans[queries[qryIdx].serial] = qry_upto_i - query(queries[qryIdx].L - 1);
                    ++qryIdx;
                }
            }
        }

        printf("Case %d:\n", tc);

        for(int i = 0; i < q; ++i)
            printf("%d\n", ans[i]);
    }

    return 0;
}
