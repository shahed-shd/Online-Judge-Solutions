// ==================================================
// Problem  :   1341 - Aladdin and the Flying Carpet
// Run time :   0.712 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

typedef     long long       LL;

vector<int> primes;

void sieve()
{
    const int SZ = 1e6 + 3;
    bitset<SZ> status;
    int rt = 1e3;

    for(int i = 3; i < rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < SZ; j+=(i<<1))
                status[j] = true;

    primes.push_back(2);

    for(int i = 3; i < SZ; i+=2)
        if(!status[i])
            primes.push_back(i);
}

int numberOfDivisors(LL n)
{
    int sz = primes.size(), cnt = 1;

    for(int i = 0; i < sz && primes[i]*primes[i] <= n; ++i) {
        if(n % primes[i] == 0) {
            int pw = 0;
            while(n % primes[i] == 0) ++pw, n /= primes[i];
            cnt *= pw + 1;
        }
    }

    if(n != 1) cnt <<= 1;

    return cnt;
}

int main()
{
    sieve();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL n, d;
        scanf("%lld %lld", &n, &d);

        int rt = sqrt(n), ans;

        if(d > rt || d*d == n) {
            ans = 0;
        }
        else {
            ans = numberOfDivisors(n) / 2;

            for(int i = 1; i < d; ++i)
                if(n % i == 0) --ans;
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
