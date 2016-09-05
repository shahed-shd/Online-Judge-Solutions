// ==================================================
// Problem  :   10140 - Prime Distance
// Run time :   0.330 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <climits>
#include <cstdlib>
using namespace std;

typedef     long long       LL;

LL modular_pow(LL base, LL exponent, LL modulus)
{
    if(modulus == 1) return 0;

    LL result = 1;
    base %= modulus;

    while(exponent > 0) {
        if(exponent & 1) {
            result = (result * base) % modulus;
        }

        exponent >>= 1;
        base = (base * base) % modulus;
    }

    return result;
}

bool isPrime(LL n, int iteration = 5)   // Miller-Rabin primality test.
{
    if(n < 2) return false;
    if(n <= 3) return true;
    if(!(n & 1)) return false;              // If n is even.

    LL d = n-1;                             // d * 2^r = n-1 where d is odd and r > 0.
    while(!(d & 1))
        d >>= 1;

    while(iteration--) {                    // Witness loop.
        LL a = rand() % (n-1) + 1;
        LL x = modular_pow(a, d, n);        // x = a^d % n
        LL d1 = d;

        while(d1 != n-1 && x != 1 && x != n-1) {
            x = (x * x) % n;                // x = (x * x) % n.
            d1 <<= 1;
        }

        if(x != n-1 && !(d1 & 1)) {
            return false;
        }
    }

    return true;
}

int main()
{
    int L, U;

    while(~scanf("%d %d", &L, &U)) {
        int minDist = INT_MAX, maxDist = INT_MIN;
        int minDistL, minDistU, maxDistL, maxDistU;

        int lastPrime = -1;
        if(L <= 2) lastPrime = 2, L = 3;

        for(LL i = L + !(L&1); i <= U; i+=2) {     // Considering only the odd numbers.
            if(isPrime(i)) {
                if(lastPrime != -1) {
                    int d = i - lastPrime;

                    if(d < minDist) {
                        minDist = d;
                        minDistL = lastPrime, minDistU = i;
                    }

                    if(d > maxDist) {
                        maxDist = d;
                        maxDistL = lastPrime, maxDistU = i;
                    }
                }

                lastPrime = i;
            }
        }

        if(minDist == INT_MAX)
            puts("There are no adjacent primes.");
        else
            printf("%d,%d are closest, %d,%d are most distant.\n", minDistL, minDistU, maxDistL, maxDistU);
    }

    return 0;
}


// -------------------- Alternatively --------------------
// Run time : 0.550 sec.
/*

#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

const int SZ = 1e6 + 3;

bitset<SZ> status;
vector<int> primes;

void sieve()        // Considering only the odd numbers.
{
    status[1] = true;
    int rt = sqrt(SZ);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < SZ; j += i<<1)
                status[j] = true;

    //primes.push_back(2);
    for(int i = 3; i < SZ; i+=2)
        if(!status[i])
            primes.push_back(i);
}

bool isPrime(int n)
{
    if(n < SZ) return !status[n];

    int rt = sqrt(n);

    for(auto it = primes.begin(); *it <= rt; ++it)
        if(!(n % *it)) return false;

    return true;
}

int main()
{
    sieve();

    int L, U;

    while(~scanf("%d %d", &L, &U)) {
        int minDist = INT_MAX, maxDist = INT_MIN;
        int minDistL, minDistU, maxDistL, maxDistU;

        int lastPrime = -1;
        if(L <= 2) lastPrime = 2, L = 3;

        for(long long i = L + !(L&1); i <= U; i+=2) {     // Considering only the odd numbers.
            if(isPrime(i)) {
                if(lastPrime != -1) {
                    int d = i - lastPrime;

                    if(d < minDist) {
                        minDist = d;
                        minDistL = lastPrime, minDistU = i;
                    }

                    if(d > maxDist) {
                        maxDist = d;
                        maxDistL = lastPrime, maxDistU = i;
                    }
                }

                lastPrime = i;
            }
        }

        if(minDist == INT_MAX)
            puts("There are no adjacent primes.");
        else
            printf("%d,%d are closest, %d,%d are most distant.\n", minDistL, minDistU, maxDistL, maxDistU);
    }

    return 0;
}

*/
