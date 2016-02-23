#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstdint>
using namespace std;

const int16_t MAXN = 20;

int16_t n, monsters[MAXN];
int32_t dp[(1<<MAXN)+3];

inline int32_t biton(int32_t n, int pos) { return n | (1<<pos); }
inline bool check(int32_t n, int pos) { return n & (1<<pos); }

int fn(int32_t mask)
{
    if(mask == (1<<n)-1) return 0;

    if(dp[mask] != -1) return dp[mask];

    int mini = INT_MAX;

    for(int i = 0; i < n; ++i){
        if(check(mask, i) == 0) {
            int32_t tmp_mask = biton(mask, i);

            tmp_mask = (i-1 >= 0)? biton(tmp_mask, i-1) : biton(tmp_mask, n-1);

            tmp_mask = (i+1 < n)? biton(tmp_mask, i+1) : biton(tmp_mask, 0);

            int damage = 0;
            for(int i = 0; i < n; ++i)
                if(check(tmp_mask, i) == 0) damage += monsters[i];

            mini = min(mini, damage + fn(tmp_mask));
        }
    }

    return dp[mask] = mini;
}

int main()
{
    while(scanf("%hd", &n) != EOF) {
        for(int i = 0; i < n; ++i)
            scanf("%hd", monsters+i);

        fill(dp, dp+(1<<MAXN)+3, -1);

        printf("%d\n", fn(0));
    }

    return 0;
}
