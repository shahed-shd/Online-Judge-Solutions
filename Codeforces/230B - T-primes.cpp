// ==================================================
// Problem  :   230B - T-primes
// Run time :   0.530 sec
// Language :   C++14
// ==================================================

#include <cstdio>
#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;


typedef     long long       LL;


const int MAXP = 1e6 + 3;

bitset<MAXP> isPrime;


void sieve()
{
    isPrime.set();

    isPrime[0] = isPrime[1] = false;

    for(int i = 4; i < MAXP; i += 2)
        isPrime[i] = false;

    int rt = sqrt(MAXP);

    for(int i = 3; i <= rt; i += 2)
        if(isPrime[i])
            for(int j = i*i; j < MAXP; j += (i<<1))
                isPrime[j] = false;
}


inline bool is_t_prime(LL x)
{
    LL rt = sqrt(x);

    return (rt * rt == x and isPrime[rt]);  // if x is square of a prime number.
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);

    sieve();

    int n;
    cin >> n;

    LL x;

    while(n--) {
        cin >> x;
        cout << (is_t_prime(x) ? "YES\n" : "NO\n");
    }

    return 0;
}
