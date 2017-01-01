// ==================================================
// Problem  :   1289 - LCM from 1 to n
// Run time :   0.800 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
#include <cmath>
using namespace std;

const int MAXN = 1e8 + 3;
const int SZ = 5761455 + 3;

bitset<MAXN> status;
int primes[SZ];
unsigned memo[SZ];

int primeCnt = 0;

void sieve()
{
    int rt = 1e4;

    for(int i = 3; i < rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < MAXN; j+=(i<<1))
                status[j] = true;

    primes[primeCnt++] = 2;

    for(int i = 3; i < MAXN; i+=2)
        if(!status[i])
            primes[primeCnt++] = i;
}

unsigned solve(int n)
{
    int rt = sqrt(n);
    unsigned res = 1;

    for(int i = 0; primes[i] <= rt; ++i) {
        int n1 = n / primes[i];

        while(n1 >= primes[i]) {
            res *= primes[i];
            n1 /= primes[i];
        }
    }

    res *= memo[upper_bound(primes, primes+primeCnt, n) - primes - 1];

    return res;
}

int main()
{
    sieve();

    memo[0] = 2;
    for(int i = 1; i < primeCnt; ++i)
        memo[i] = memo[i-1] * primes[i];

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        printf("Case %d: %u\n", tc, solve(n));
    }

    return 0;
}
