// ==================================================
// Problem  :   1077F1 - Pictures with Kittens (easy version)
// Run time :   0.078 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

typedef     long long       LL;

const int MAXN = 200 + 3;
const LL INF = LLONG_MAX;

int n, k, x;
int beauty[MAXN];
LL memo[MAXN][MAXN][MAXN];


LL fn(int curr_idx, int last_repost_idx, int curr_tot_pic)
{
    if(curr_idx > n) return 0;
    if(curr_tot_pic >= x) {
        if(n - last_repost_idx >= k) return -INF;
        else return 0;
    }

    LL &ret = memo[curr_idx][last_repost_idx][curr_tot_pic];
    if(ret != -1) return ret;

    ret = beauty[curr_idx] + fn(curr_idx+1, curr_idx, curr_tot_pic+1);
    if(curr_idx - last_repost_idx < k) {
        ret = max(ret, fn(curr_idx+1, last_repost_idx, curr_tot_pic));
    }

    return ret;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    scanf("%d %d %d", &n, &k, &x);

    for(int i = 1; i <= n; ++i) {
        scanf("%d", beauty+i);
    }

    if(x*k < n-k+1) {
        printf("-1\n");
        return 0;
    }

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            for(int k = 0; k <= n; ++k) {
                memo[i][j][k] = -1;
            }
        }
    }

    printf("%lld\n", fn(1, 0, 0));

    return 0;
}
