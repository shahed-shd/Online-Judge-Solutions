// Run time : 0.09 sec.

#include <cstdio>
using namespace std;

typedef     long long   LL;

const int MAXN = 200000+3;

int arr[MAXN], temp[MAXN];

LL mergeSort(int left, int right)
{
    if(left == right) return 0L;

    int mid = (left + right) / 2;

    LL invCnt = mergeSort(left, mid) + mergeSort(mid+1, right);

    int i = left, j = mid+1;

    for(int k = left; k <= right; ++k) {
        if(i <= mid && (arr[i] < arr[j] || j > right))
            temp[k] = arr[i++];
        else {
            temp[k] = arr[j++];

            if(i <= mid) invCnt += mid - i + 1;	// This is tricky.
        }
    }

    for(int k = left; k <= right; ++k)
        arr[k] = temp[k];

    return invCnt;
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) scanf("%d", arr+i);

        printf("%lld\n", mergeSort(0, n-1));
    }

    return 0;
}


// ----------------------- Alternatively -----------------------
// using Binary Indexed Tree (BIT).
// Run time : 0.11 sec
/*
#include <cstdio>
#include <vector>
using namespace std;

class binIdxTree {
    vector<int> tree;
    int maxIdx;
public:
    binIdxTree(int n) { maxIdx = n; tree.assign(n+1, 0); }

    void update(int idx, int val) {
        while(idx <= maxIdx) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int total = 0;

        while(idx > 0) {
            total += tree[idx];
            idx -= idx & (-idx);
        }

        return total;
    }
};

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);

        int inp[n], mx = 0;

        for(int i = 0; i < n; ++i) {
            scanf("%d", inp+i);
            mx = max(mx, inp[i]);
        }

        binIdxTree bit(mx);

        long long ans = 0;

        for(int i = n-1; i >= 0; --i) {
            ans += bit.query(inp[i] - 1);
            bit.update(inp[i], 1);
        }

        printf("%lld\n", ans);
    }

    return 0;
}

*/
