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
            sum += a[j];            // sum contains the cumulative sum of current block.
            curr_ans += a[j];
            if(curr_ans < 0) curr_ans = 0;
        }

        // Answer for the current block (each block is of size m).
        curr_ans -= k;

        // If adding the previous block maximizes curr_ans, then take that.
        if(i > m) curr_ans = max(curr_ans, memo[i-m] + sum -k);

        // Memorize it for calculatiion of next block.
        memo[i] = curr_ans;

        // Take the maximum value.
        ans = max(ans, curr_ans);
    }

    printf("%lld\n", ans);

   return 0;
}
