// ==================================================
// Problem  :   846A - Curriculum Vitae
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 3;

int main()
{
    int n;
    scanf("%d", &n);

    int val, zeroCnt[MAXN] = {0};

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        zeroCnt[i] = zeroCnt[i-1] + (val == 0);
    }

    int ans = 0;

    for(int i = 1; i <= n; ++i) {
        int leftZeroCnt = zeroCnt[i-1];
        int rightOneCnt = (n - i) - (zeroCnt[n] - zeroCnt[i]);
        ans = max(ans, leftZeroCnt + 1 + rightOneCnt);
    }

    printf("%d\n", ans);

    return 0;
}
