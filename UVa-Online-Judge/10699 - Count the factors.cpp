#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1000000+3;

vector<int> primes;

void sieve()
{
    bitset<MAXN> status;

    for(int i = 4; i < MAXN; i+=2)
        status[i] = true;

    int sq = sqrt(MAXN);

    for(int i = 3; i < sq; i+=2)
        if(!status[i])
            for(int j = i*i; j < MAXN; j += (i<<1))
                status[j] = true;

    for(int i = 2; i < MAXN; ++i)
        if(!status[i]) primes.push_back(i);

}

int howMany(int n)
{
    int cnt = 0;

    for(int i = 0; primes[i]*primes[i] <= n; ++i) {
        if(n % primes[i] == 0) {
            ++cnt;

            while(n % primes[i] == 0)
                n /= primes[i];
        }
    }

    if(n != 1) ++cnt;

    return cnt;
}

int main()
{
    //freopen("in", "r", stdin);

    sieve();

    int n;

    while(scanf("%d", &n), n)
        printf("%d : %d\n", n, howMany(n));

    return 0;
}
