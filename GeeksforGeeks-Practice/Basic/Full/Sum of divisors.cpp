// ==================================================
// Problem  :   Sum of divisors
// Run time :   0.069 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1000 + 3;

vector<int> primes;

void sieve()
{
    bitset<MAXN> status;

    primes.push_back(2);
    int RT = sqrt(MAXN);
    int rt = sqrt(RT);

    for(int i = 3; i <= rt; i += 2) {
        if(!status[i]) {
            primes.push_back(i);

            for(int j = i*i; j <= RT; j += (i<<1))
                status[j] = true;
        }
    }

    for(int i = ((rt & 1)? rt+2 : rt+1); i <= RT; i += 2)
        if(!status[i])
            primes.push_back(i);
}

int sum_of_divisors(int n)
{
    int sum = 1;
    int sz = primes.size();

    for(int i = 0; i < sz && primes[i]*primes[i] <= n; ++i) {
        if(n % primes[i] == 0) {
            int pw = 0;

            while(n % primes[i] == 0) {
                ++pw;
                n /= primes[i];
            }

            sum *= (pow(primes[i], pw+1) - 1) / (primes[i] - 1);
        }
    }

    if(n != 1) sum *= 1 + n;

    return sum;
}

int main()
{
    sieve();

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        printf("%d\n", sum_of_divisors(n) - n);
    }

    return 0;
}
