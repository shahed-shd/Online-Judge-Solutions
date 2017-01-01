// ==================================================
// Problem  :   1259 - Goldbach`s Conjecture
// Run time :   0.300 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
#include <cmath>
using namespace std;

const int MAXN = 1e7 + 3;
const int SZ = 664579 + 3;

bitset<MAXN> status;
int primes[SZ], primeCnt = 0;

void sieve()
{
    int rt = sqrt(MAXN);

    status[0] = status[1] = true;
    for(int i = 4; i < MAXN; i+=2) status[i] = true;

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < MAXN; j+=(i<<1))
                status[j] = true;

    primes[primeCnt++] = 2;

    for(int i = 3; i < MAXN; i+=2)
        if(!status[i])
            primes[primeCnt++] = i;
}

int solve(int n)
{
    int cnt = 0, upto = n/2;

    for(int i = 0; primes[i] <= upto; ++i)
        if(!status[n - primes[i]])
            ++cnt;

    return cnt;
}

int main()
{
    sieve();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        printf("Case %d: %u\n", tc, solve(n));
    }

    return 0;
}
