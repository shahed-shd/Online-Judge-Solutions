//strange experience. C++ i/o system is responsible to face 'Time Limit Exceeded'.
//C i/o is faster than that of C++.

//#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long int t, tc, m, n, ans;

    //cin >> t;
    scanf("%lld", &t);
    tc = 0;

    while(t--) {
        //cin >> m >> n;
        scanf("%lld %lld", &m, &n);

        if(m == 1) ans = n;

        else if(n == 1) ans = m;

        else if(m == 2) {
            ans = n - (n%4);

            if(n%4 == 1) ans += 2;
            else if(n%4 > 1) ans += 4;
        }

        else if(n == 2) {
            ans = m - (m%4);

            if(m%4 == 1) ans += 2;
            else if(m%4 > 1) ans += 4;
        }

        else ans = ((m * n) + 1) / 2;

        //cout << "Case " << ++tc << ": " << ans << '\n';
        printf("Case %lld: %lld\n", ++tc, ans);
    }

    return 0;
}
