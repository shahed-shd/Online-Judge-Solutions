// ==================================================
// Problem  :   Maximum calorie
// Run time :   0.099 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

typedef     long long       LL;

const int MAXN = 100000 + 3;

int n, arr[MAXN];
LL memo[MAXN][4];

LL fn(int idx, int cnt)
{
    if(idx == n) return 0;

    LL &ret = memo[idx][cnt];
    if(ret != -1) return ret;

    if(cnt == 3)
        ret = fn(idx+1, 1);
    else
        ret = max(arr[idx]+fn(idx+1, cnt+1), fn(idx+1, 1));

    return ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) scanf("%d", arr+i);

        for(int i = 0; i < n; ++i)
            memo[i][1] = memo[i][2] = memo[i][3] = -1;

        printf("%lld\n", fn(0, 1));
    }

    return 0;
}
