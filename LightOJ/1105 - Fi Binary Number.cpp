// ==================================================
// Problem  :   1105 - Fi Binary Number
// Run time :   0.016 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e9 + 3;

int main()
{
    int fib[50] = {1, 2};
    int f_idx = 1;

    while(fib[f_idx] <= MAXN) {
        ++f_idx;
        fib[f_idx] = fib[f_idx-1] + fib[f_idx-2];
    }


    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        int idx = upper_bound(fib, fib+f_idx+1, n) - fib;
        if(fib[idx] > n) --idx;

        int sum = 0;
        char ans[50] = {0};

        for(int i = 0; sum <= n and idx >= 0; ++i, --idx) {
            if(sum + fib[idx] <= n) {
                ans[i] = '1';
                sum += fib[idx];
            }
            else ans[i] = '0';
        }

        printf("Case %d: %s\n", tc, ans);
    }

    return 0;
}
