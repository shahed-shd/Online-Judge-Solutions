// ==================================================
// Problem  :   Divisibility
// Run time :   0.745 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef     long long       LL;

inline bool bitcheck(int n, int pos) { return n & (1 << pos); }

LL gcd(LL m, LL n)
{
    while (n != 0) {
        LL t = m % n;
        m = n;
        n = t;
	}

    return m;
}

inline LL lcm(LL m, LL n)
{
    return m / gcd(m, n) * n;
}

inline LL get_lcm(vector<LL> &V)
{
    return accumulate(V.begin(), V.end(), 1, lcm);
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int a[n+3];
        for(int i = 0; i < n; ++i) scanf("%d", a+i);

        LL k;
        scanf("%lld", &k);

        LL res = 0;

        for(int bitmask = (1 << n) - 1; bitmask; --bitmask) {
            vector<LL> V;

            for(int i = 0; i < n; ++i)
                if(bitcheck(bitmask, i))
                    V.push_back(a[i]);

            LL tmp = k / get_lcm(V);

            res += ((V.size() & 1)? tmp : -tmp);
        }

        printf("%lld\n", res);
    }

    return 0;
}
