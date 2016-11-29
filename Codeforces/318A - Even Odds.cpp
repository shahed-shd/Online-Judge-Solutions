// ==================================================
// Problem  :   318A - Even Odds
// Run time :   0.030 sec.
// Language :   C++11
// ==================================================

#include <iostream>
using namespace std;

typedef     long long       LL;

int main()
{
    LL n, k;
    cin >> n >> k;

    LL totalOdd = n/2 + bool(n & 1);
    LL ans;

    if(k <= totalOdd) ans = 2 * k - 1;
    else {
        k -= totalOdd;
        ans = 2 * k;
    }

    cout << ans << '\n';

    return 0;
}
