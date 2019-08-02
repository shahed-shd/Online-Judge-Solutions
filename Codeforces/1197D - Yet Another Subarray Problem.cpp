// ==================================================
// Problem  :   1197D - Yet Another Subarray Problem
// Run time :   0.109 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;


typedef     long long       LL;


const int MAXN = 3e5 + 3;


LL memo[MAXN] = {0};
int a[MAXN] = {0};


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    LL ans = 0;

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);

        LL sum = 0, curr_ans = 0;
        for(int j = max(1, i-m+1); j <= i; ++j) {
            sum += a[j];
            curr_ans += a[j];
            if(curr_ans < 0) curr_ans = 0;
        }

        memo[i] = curr_ans;
        if(i > m) memo[i] = max(memo[i], memo[i-m] + sum - k);
        ans = max(ans, memo[i] - k);
    }

    printf("%lld\n", ans);

   return 0;
}
