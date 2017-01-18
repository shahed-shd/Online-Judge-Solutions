// ==================================================
// Problem  :   11417 - GCD
// Runtime  :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

const int MAXN = 500 + 3;

int ans[MAXN] = {0};

int gcd(int m, int n)
{
    while(n != 0) {
        int t = m % n;
        m = n;
        n = t;
    }

    return m;
}

int main()
{
    for(int i = 1; i < MAXN-1; ++i)
        for(int j = i+1; j < MAXN; ++j)
            ans[j] += gcd(i, j);

    for(int i = 1; i < MAXN; ++i)
        ans[i] += ans[i-1];

    // Preprocess complete.

    int n;

    while(scanf("%d", &n), n)
        printf("%d\n", ans[n]);

    return 0;
}
