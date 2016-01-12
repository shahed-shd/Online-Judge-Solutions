#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

long long nCr(int n, int r)
{
    int cnt = min(n-r, r), s = 1;
    double res = 1;

    while(cnt--) {
        res *= n--;
        res /= s++;
    }

    return round(res);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m;

    while(scanf("%d %d", &n, &m), n || m)
        printf("%d things taken %d at a time is %Ld exactly.\n", n, m, nCr(n, m));

    return 0;
}



// ---------------------- Alternatively ----------------------

/*
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primes;
vector<int> primeFactorCount;

void sieve()
{
    bitset<101> bits;
    bits[0] = bits[1] = true;

    for(int i = 4; i <= 100; i+=2) bits[i] = true;

    for(int i = 3; i <= 10; i+=2) {
        if(!bits[i]) {
            for(int j = i*i; j <= 100; j += i<<1)
                bits[j] = true;
        }
    }

    primes.push_back(2);
    for(int i = 3; i <= 100; i+=2)
        if(!bits[i]) primes.push_back(i);
}

void getPrimeFactors(int n)
{
    for(int i = 0; n != 1; ++i) {
        int p = primes[i];

        while(n % p == 0) {
            n /= p;
            ++primeFactorCount[p];
        }
    }
}

void getPrimeFactors2(int n)
{
    for(int i = 0; n != 1; ++i) {
        int p = primes[i];

        while(n % p == 0) {
            n /= p;
            --primeFactorCount[p];
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    sieve();

    int n, m;

    while(scanf("%d %d", &n, &m), n || m) {
        primeFactorCount.assign(100, 0);

        int cnt = min(n-m, m);
        int s = 1, t = n;

        while(cnt--) {
            getPrimeFactors(t--);
            getPrimeFactors2(s++);
        }

        int sz = primes.size();
        double res = 1;

        for(int i = 0; i < sz; ++i) {
            int temp = primeFactorCount[primes[i]];
            if(temp)
                res *= pow(primes[i], temp);
        }

        printf("%d things taken %d at a time is %d exactly.\n", n, m, (int) round(res));
    }

    return 0;
}
*/
