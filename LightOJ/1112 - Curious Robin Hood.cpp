#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class binIdxTree {
    vector<int> tree;
    int maxIdx;
public:
    binIdxTree(int n) { maxIdx = n; tree.assign(maxIdx+1, 0); }

    void update(int idx, int val) {
        while(idx <= maxIdx) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query_sum(int idx) {    // Returns cumulative sum in rage [1...idx]
        int sum = 0;

        while(idx > 0) {
            sum += tree[idx];
            idx -= idx & (-idx);
        }

        return sum;
    }

    int query_idx(int idx) { return query_sum(idx) - query_sum(idx-1); }

    int query_range_sum(int i, int j) { return query_sum(j) - query_sum(i-1); }
};

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, q;
        scanf("%d %d", &n, &q);

        binIdxTree ob(n);

        int val;

        for(int i = 1; i <= n; ++i) {
            scanf("%d", &val);
            ob.update(i, val);
        }

        printf("Case %d:\n", tc);

        while(q--) {
            int task, idx;
            scanf("%d", &task);

            if(task == 1) {
                scanf("%d", &idx);
                ++idx;

                int res = ob.query_idx(idx);
                printf("%d\n", res);
                ob.update(idx, -res);
            }
            else if(task == 2) {
                scanf("%d %d\n", &idx, &val);
                ob.update(idx+1, val);
            }
            else {
                int j;
                scanf("%d %d\n", &idx, &j);
                printf("%d\n", ob.query_range_sum(idx+1, j+1));
            }
        }
    }

    return 0;
}
