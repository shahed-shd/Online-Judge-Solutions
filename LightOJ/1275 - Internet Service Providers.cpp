// ==================================================
// Problem  :   1275 - Internet Service Providers
// Run time :   0.000 sec
// Language :   C++
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;


typedef     long long       LL;


LL calc(int n, int c, int x)
{
    LL res = x * (c - LL(x) * n);
    return max(res, 0LL);
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, c;
        scanf("%d %d", &n, &c);

        int ans;

        if(n == 0) {
            ans = 0;
        }
        else {
            int x = c / (2 * n);
            ans = ((calc(n, c, x) >= calc(n, c, x+1))? x : x+1);
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
