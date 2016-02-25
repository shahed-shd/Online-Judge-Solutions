#include <cstdio>
#include <algorithm>
using namespace std;

typedef     long long   LL;

int base, k, len;
char str[17];
LL dp[(1<<16)+3][20];

inline int biton(int n, int pos) { return n | (1<<pos); }
inline bool check(int n, int pos) { return n & (1<<pos); }

LL fn(int mask, int val)
{
    if(mask == (1<<len)-1) return (val == 0);

    if(dp[mask][val] != -1) return dp[mask][val];

    LL cnt = 0;

    for(int i = 0; i < len; ++i)
        if(check(mask, i) == 0)
            cnt += fn(biton(mask, i), (val * base + str[i]) % k);

    return dp[mask][val] = cnt;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d %s", &base, &k, str);

        for(len = 0; str[len]; ++len)
            str[len] -= ('0' <= str[len] && str[len] <= '9')? '0' : 'A'-10;
        // Now, len contains the length of str
        // & every element of str contains number value instead of ASCII value.

        fill(&dp[0][0], &dp[(1<<16)+3][0], -1);

        printf("Case %d: %lld\n", tc, fn(0, 0));
    }

    return 0;
}
