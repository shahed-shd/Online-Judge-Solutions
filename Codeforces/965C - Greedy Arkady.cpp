// ==================================================
// Problem  :   965C - Greedy Arkady
// Run time :   0.031 sec
// Language :   C++14
// ==================================================


#include <iostream>
#include <algorithm>
using namespace std;


typedef     long long       LL;


int main()
{
    LL n, k, m, dd;
    cin >> n >> k >> m >> dd;

    LL ans = 0;

    for(int d = 1; d <= dd; ++d) {
        LL x = n / (k * (d - 1) + 1);
        x = min(x, m);

        if(x <= 0) break;

        LL cnt = n / (x * k);
        cnt += (n % (x * k) >= x);

        if(cnt > d) continue;

        ans = max(ans, cnt * x);
    }

    cout << ans << '\n';

    return 0;
}
