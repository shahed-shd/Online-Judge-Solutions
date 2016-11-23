// ==================================================
// Problem  :   Interesting Queries
// Run time :   0.208 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 10000 + 3;
const int MAXAI = 1000 + 3;

int bucketSize;

struct query {
    int L, R, serial;

    bool operator<(const query &ob) const {
        if(L / bucketSize != ob.L / bucketSize)
            return L/bucketSize < ob.L/bucketSize;
        return R < ob.R;
    }
};

int arr[MAXN];
query queries[MAXN];

void MOs_algorithm(int n, int q, int k)
{
    bucketSize = sqrt(n);
    sort(queries, queries+q);

    int freqCnt[MAXAI] = {0}, numCnt = 0, ans[q+3];
    int L, R, currL = 1, currR = 1;

    ++freqCnt[arr[1]];
    if(freqCnt[arr[1]] == k) ++numCnt;

    for(int i = 0; i < q; ++i) {
        L = queries[i].L, R = queries[i].R;

        while(currL < L) {
            if(freqCnt[arr[currL]] == k) --numCnt;
            --freqCnt[arr[currL++]];
        }

        while(currL > L) {
            ++freqCnt[arr[--currL]];
            if(freqCnt[arr[currL]] == k) ++numCnt;
        }

        while(currR < R) {
            ++freqCnt[arr[++currR]];
            if(freqCnt[arr[currR]] == k) ++numCnt;
        }

        while(currR > R) {
            if(freqCnt[arr[currR]] == k) --numCnt;
            --freqCnt[arr[currR--]];
        }

        ans[queries[i].serial] = numCnt;
    }

    printf("%d", ans[0]);
    for(int i = 1; i < q; ++i) printf(" %d", ans[i]);
    putchar('\n');
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n, q, k;
        scanf("%d %d %d", &n, &q, &k);

        for(int i = 1; i <= n; ++i) scanf("%d", arr+i);

        int L, R;

        for(int i = 0; i < q; ++i) {
            scanf("%d %d", &L, &R);
            queries[i].L = L;
            queries[i].R = R;
            queries[i].serial = i;
        }

        MOs_algorithm(n, q, k);
    }

    return 0;
}
