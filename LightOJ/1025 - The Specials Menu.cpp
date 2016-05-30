#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef     long long       LL;

const int MAXL = 60+3;

char str[MAXL];
LL memo[MAXL][MAXL];

LL fn(int left, int right)
{
    if(left > right) return 0;
    if(left == right) return 1;

    LL &ret = memo[left][right];
    if(ret != -1) return ret;

    ret = fn(left+1, right) - fn(left+1, right-1) + fn(left, right-1);
    if(str[left] == str[right]) ret += 1 + fn(left+1, right-1);

    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%s", str);

        fill(&memo[0][0], &memo[MAXL][0], -1);

        printf("Case %d: %lld\n", tc, fn(0, strlen(str)-1));
    }

    return 0;
}
