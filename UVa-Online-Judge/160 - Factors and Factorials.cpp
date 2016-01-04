#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100;

vector<int> primes;
int primesSize;

void sieve()
{
    bitset<MAXN+1> primeBit;

    primeBit[0] = primeBit[1] = true;

    for(int i = 4; i <= MAXN; i+=2) primeBit[i] = true;

    int sq = sqrt(MAXN);

    for(int i = 3; i <= sq; i+=2)
        if(!primeBit[i])
            for(int j = i*i; j <= MAXN; j += i<<1) primeBit[j] = true;

    for(int i = 0; i <= MAXN; ++i)
        if(!primeBit[i]) primes.push_back(i);

    primesSize = primes.size();
}

vector<int> factorize(int n)
{
    vector<int> primeCount(MAXN+1, 0);

    while(n > 1) {
        int num = n--;

        for(int i = 0; i < primesSize && num != 1; ++i) {
            int prm = primes[i];

            while(num % prm == 0) {
                ++primeCount[prm];
                num /= prm;
            }
        }
    }

    return primeCount;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    sieve();

    int n;

    while(scanf("%d", &n) && n) {
        vector<int> ans(factorize(n));

        printf("%3d! =", n);

        for(int i = 0; i < primesSize; ++i) {
            if(ans[primes[i]]) {
                if(i && !(i % 15)) printf("\n      ");
                printf("%3d", ans[primes[i]]);
            }
            else break;
        }

        putchar('\n');
    }

    return 0;
}
