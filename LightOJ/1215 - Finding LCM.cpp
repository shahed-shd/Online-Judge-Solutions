// ==================================================
// Problem  :   1215 - Finding LCM
// Run time :   0.008 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

#define     ff              first
#define     ss              second

typedef     long long       LL;
typedef     pair<int,int>   ii;

const int MX = 1e6 + 3;

vector<int> primes;

void sieve()
{
    bitset<MX> status;

    int rt = sqrt(MX);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < MX; j+=(i<<1))
                status[j] = true;

    primes.push_back(2);

    for(int i = 3; i < MX; i+=2)
        if(!status[i])
            primes.push_back(i);
}

void prime_factorization(LL n, vector<ii> &V)
{
    V.clear();
    int sz = primes.size();

    for(int i = 0; i < sz && primes[i]*primes[i] <= n; ++i) {
        if(n % primes[i] == 0) {
            int pw = 0;

            while(n % primes[i] == 0) {
                ++pw;
                n /= primes[i];
            }

            V.push_back(ii(primes[i], pw));
        }
    }

    if(n != 1) V.push_back(ii(n, 1));
}

int main()
{
    sieve();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL a, b, L;
        scanf("%lld %lld %lld", &a, &b, &L);

        printf("Case %d: ", tc);

        map<int, ii> fact;

        vector<ii> V;

        prime_factorization(L, V);
        int sz = V.size();

        for(int i = 0; i < sz; ++i)
            fact[V[i].ff] = ii(V[i].ss, 0);

        bool impossible = false;

        prime_factorization(a, V);
        sz = V.size();

        for(int i = 0; i < sz; ++i) {
            ii &reff = fact[V[i].ff];
            reff.ss = V[i].ss;

            if(reff.ff < reff.ss) {
                impossible = true;
                break;
            }
        }

        if(impossible) {
            puts("impossible");
            continue;
        }

        prime_factorization(b, V);
        sz = V.size();

        for(int i = 0; i < sz; ++i) {
            ii &reff = fact[V[i].ff];
            reff.ss = max(reff.ss, V[i].ss);

            if(reff.ff < reff.ss) {
                impossible = true;
                break;
            }
        }

        if(impossible) {
            puts("impossible");
            continue;
        }

        LL c = 1;

        for(map<int,ii>::iterator it = fact.begin(); it != fact.end(); ++it)
            if(it->ss.ff > it->ss.ss)
                c *= pow(it->ff, it->ss.ff);

        printf("%lld\n", c);
    }

    return 0;
}
