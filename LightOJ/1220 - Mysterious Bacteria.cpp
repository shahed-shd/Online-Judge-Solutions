// ==================================================
// Problem  :   1220 - Mysterious Bacteria
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;

typedef     long long           LL;

vector<int> primes;

void sieve()
{                               // MAXX = (1LL << 32) - 1;
    const int RT = 65535 + 3;   // 65535 = int(sqrt(MAXX));
    bitset<RT> status;
    int rt = sqrt(RT);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < RT; j+=(i<<1))
                status[j] = true;

    primes.push_back(2);

    for(int i = 3; i < RT; i+=2)
        if(!status[i])
            primes.push_back(i);
}

void f(LL n, vector<int> &V)
{
    V.clear();

    int sz = primes.size();

    for(int i = 0; i < sz && LL(primes[i])*primes[i] <= n; ++i) {
        if(n % primes[i] == 0) {
            int pw = 0;
            while(n % primes[i] == 0) ++pw, n /= primes[i];
            V.push_back(pw);
        }
    }

    if(n != 1) V.push_back(1);
}

int gcd(int m, int n)
{
    while (n != 0) {
        int t = m % n;
        m = n;
        n = t;
	}

    return m;
}

int main()
{
    //freopen("in", "r", stdin);

    sieve();

    int t;
    scanf("%d",  &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL x;
        scanf("%lld", &x);

        vector<int> V;
        f(abs(x), V);
        int p = accumulate(V.begin()+1, V.end(), *V.begin(), gcd);

        if(x < 0) p /= p & (-p);

        printf("Case %d: %d\n", tc, p);
    }

    return 0;
}
