// ==================================================
// Problem  :   455A - Boredom
// Run time :   0.046 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

typedef     long long       LL;

const int MAXN = 1e5 + 3;

int n, mx, cnt[MAXN] = {0};
LL memo[MAXN] = {0};

LL fn(int idx)
{
    if(idx > mx) return 0;
    if(memo[idx]) return memo[idx];

    return memo[idx] = max(fn(idx+1), idx * LL(cnt[idx]) + fn(idx+2));
}

int main()
{
    //freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    int tmp;
    mx = 0;

    for(int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        ++cnt[tmp];

        mx = max(mx, tmp);
    }

    printf("%I64d\n", fn(1));

    return 0;
}
