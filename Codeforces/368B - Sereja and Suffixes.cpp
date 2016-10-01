// ==================================================
// Problem  :   368B - Sereja and Suffixes
// Run time :   0.078 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXN = 1e5 + 3;

void MOs_algorithm(int n, int m, int arr[], ii qry[], int ans[])
{
    sort(qry, qry+m);

    int cnt[MAXN] = {0}, currCnt = 0;

    for(int i = 0; i < n; ++i)
        if(++cnt[arr[i]] == 1)
            ++currCnt;

    int currL = 0;

    for(int i = 0; i < m; ++i) {
        int L = qry[i].first;

        while(currL < L)
            if(--cnt[arr[currL++]] == 0)
                --currCnt;

        ans[qry[i].second] = currCnt;
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int n, m;

    while(~scanf("%d %d", &n, &m)) {
        int arr[n+3];
        ii qry[m+3];

        for(int i = 0; i < n; ++i)
            scanf("%d", arr+i);

        int li;

        for(int i = 0; i < m; ++i) {
            scanf("%d", &li);
            qry[i] = ii(li-1, i);
        }

        int ans[m+3];

        MOs_algorithm(n, m, arr, qry, ans);

        for(int i = 0; i < m; ++i)
            printf("%d\n", ans[i]);
    }

    return 0;
}
