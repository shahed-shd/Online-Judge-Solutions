#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

typedef     long long       LL;

const int MAXN = (1LL<<31)-1, MOD = 1000000007;

vector<int> primes;

void sieve()
{
    const int RT = 46340+3; // sqrt(MAXN).
    bitset<RT> status;
    int rt = sqrt(RT);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < RT; j+= (i<<1))
                status[j] = true;

    primes.push_back(2);

    for(int i = 3; i < RT; i+=2)
        if(!status[i]) primes.push_back(i);
}

LL modular_pow(LL base, LL exponent)
{
    LL result = 1;
    base %= MOD;

    while(exponent > 0) {
        if(exponent & 1) {
            result = (result * base) % MOD;
        }

        exponent >>= 1;
        base = (base * base) % MOD;
    }

    return result;
}

LL solve(int n, int m)
{
    LL res = 1;
    int sz = primes.size();

    for(int i = 0; i < sz && primes[i]*primes[i] <= n; ++i) {
        if(n % primes[i] == 0) {
            LL pw = 0;

            while(n % primes[i] == 0)
                n /= primes[i], ++pw;

            pw *= m;

            res *= (((modular_pow(primes[i], pw+1) + (-1+MOD)) % MOD) * modular_pow(primes[i]-1, MOD-2)) % MOD;
            res %= MOD;
        }
    }


    if(n != 1) {
        res *= (((modular_pow(n, m+1LL) + (-1+MOD)) % MOD) * modular_pow(n-1, MOD-2)) % MOD;
        res %= MOD;
    }

    return res;
}

int main()
{
    //freopen("in", "r", stdin);

    sieve();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, m;
        scanf("%d %d", &n, &m);

        printf("Case %d: %lld\n", tc, solve(n, m));
    }

    return 0;
}
