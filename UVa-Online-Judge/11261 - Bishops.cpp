#include <iostream>
#include <bitset>
using namespace std;

#define MAXN 80001

bitset<MAXN> mark_left;
bitset<MAXN> mark_right;

int n, m, *dp;

void input()
{
    int r_i, c_i;

    cin >> n >> m;

    mark_left.reset();
    mark_right.reset();

    while(m--) {
        cin >> r_i >> c_i;

        mark_left.set(r_i + c_i);
        mark_right.set(r_i + n - c_i + 1);
    }
}

void solve()
{
    dp = new int [2*n+2];
    dp[0] = dp[1] = 0;

    dp[2] = (mark_left[n+1])? 0 : 1;

    for(int i = 3; i <= n+1; ++i) {
        dp[i] = dp[i-2];

        if(!mark_left[i+n-1]) ++dp[i];
        if(!mark_left[n+3-i]) ++dp[i];
    }

    dp[2*n+1] = 0;
    dp[2*n] = (mark_left[n+1])? 0 : 1;

    for(int i = 2*n-1; i >= n+2; --i) {
        dp[i] = dp[i+2];

        if(!mark_left[3*n+1-i]) ++dp[i];
        if(!mark_left[i+1-n]) ++dp[i];
    }
    // DP complete.

    int ans = 0;
    static int tc = 0;

    for(int i = 2; i <= 2*n; ++i) {
        if(!mark_right[i]) ans += dp[i];
    }

    cout << "Case #" << ++tc << ": " << ans << '\n';

    delete [] dp;
}

int main()
{
    int L;

    cin >> L;

    while(L--) {
        input();
        solve();
    }

    return 0;
}
