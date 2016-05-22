#include <cstdio>
#include <bitset>
using namespace std;

typedef     unsigned long long      ULL;

const int MAXN = 5e6 + 3;

ULL phi[MAXN];
bitset<MAXN> isPrime;

void sieve()
{
    for(int i = 0; i < MAXN; ++i)
        phi[i] = i;

    phi[1] = 0;
    phi[2] = 1;

    isPrime.set();
    isPrime[0] = isPrime[1] = false;

    for(int i = 4; i < MAXN; i+=2) {
        isPrime[i] = false;
        phi[i] -= phi[i] / 2;
    }

    for(int i = 3; i < MAXN; i+=2) {
        if(isPrime[i]) {
            phi[i] = i-1;

            for(int j = i+i; j < MAXN; j+=i) {
                isPrime[j] = false;
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int main()
{
    sieve();

    for(int i = 2; i < MAXN; ++i) {
        phi[i] *= phi[i];
        phi[i] += phi[i-1];
    }

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n", tc,  phi[b] - phi[a-1]);
    }

    return 0;
}
