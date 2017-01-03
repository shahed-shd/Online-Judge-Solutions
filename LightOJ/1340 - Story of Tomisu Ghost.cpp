// ==================================================
// Problem  :   1340 - Story of Tomisu Ghost
// Run time :   0.084 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

typedef     long long       LL;

const int MAXN = 1e5 + 3;
const int MOD = 10000019;

vector<int> primes;

void sieve()
{
    bitset<MAXN> status;
    int rt = sqrt(MAXN);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < MAXN; j+=(i<<1))
                status[j] = true;

    primes.push_back(2);

    for(int i = 3; i < MAXN; i+=2)
        if(!status[i])
            primes.push_back(i);
}

int highestPowInFact(int n, int p)   // Returns highest power of p in n factorial.
{
    int cnt = 0;

    while(n /= p, n) cnt += n;

    return cnt;
}

int modular_pow(LL base, int exponent)
{
    int result = 1;
    base %= MOD;

    while(exponent) {
        if(exponent & 1)
            result = (result * base) % MOD;

        exponent >>= 1;
        base = (base * base) % MOD;
    }

    return result;
}

int main()
{
    sieve();
    int sz = primes.size();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, k;
        scanf("%d %d", &n, &k);

        LL res = 1;

        for(int i = 0; i < sz; ++i) {
            int pw = highestPowInFact(n, primes[i]);
            if(pw < k) break;
            res = (res * modular_pow(primes[i], pw/k)) % MOD;
        }

        if(res == 1) res = -1;

        printf("Case %d: %lld\n", tc, res);
    }

    return 0;
}
