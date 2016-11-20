// ==================================================
// Problem  :   Count Divisors of Factorial
// Run time :   0.074 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

typedef     long long       LL;

const int MAXN = 100 + 3;

vector<int> primes;

void sieve()
{
    bitset<MAXN> status;
    primes.push_back(2);

    int rt = sqrt(MAXN);

    for(int i = 3; i <= rt; i += 2) {
        if(!status[i]) {
            primes.push_back(i);

            for(int j = i*i; j < MAXN; j += (i<<1))
                status[j] = true;
        }
    }

    for(int i = ((rt & 1)? rt+2 : rt+1); i < MAXN; i += 2)
        if(!status[i])
            primes.push_back(i);
}

int legendre(int n, int p)
{
    int pw = 0;

    while(n) {
        n /= p;
        pw += n;
    }

    return pw;
}

LL get_ans(int n)
{
    LL ans = 1;

    for(auto &p : primes) {
        if(p > n) break;
        ans *= legendre(n, p) + 1;
    }

    return ans;
}

int main()
{
    sieve();

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", get_ans(n));
    }

    return 0;
}
