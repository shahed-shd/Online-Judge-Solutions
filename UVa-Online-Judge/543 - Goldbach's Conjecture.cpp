// ==================================================
// Problem  :   543 - Goldbach's Conjecture
// Run time :   0.010 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1e6 + 3;

bitset<MAXN> status;
vector<int> primes;

void sieve()
{
    int rt = sqrt(MAXN);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < MAXN; j+=(i<<1))
                status[j] = true;

    for(int i = 3; i < MAXN; i+=2)
        if(!status[i])
            primes.push_back(i);
}

int main()
{
    sieve();

    int n;

    while(scanf("%d", &n), n) {
        int nn = n >> 1;
        int a = -1, b;

        for(int i = 0; primes[i] <= nn && a == -1; ++i)
            if(!status[n - primes[i]])
                a = primes[i], b = n-primes[i];

        if(a == -1) puts("Goldbach's conjecture is wrong.");
        else printf("%d = %d + %d\n", n, a, b);
    }

    return 0;
}
