#include <cstdio>
#include <bitset>
#include <cmath>
#include <vector>
using namespace std;

const int MAXN = 50000+3;

int phi[MAXN] = {0, 1};     // phi(1) = 1.

bitset<MAXN> status;
vector<int> primes;

void sieve()
{
    for(int i = 4; i < MAXN; i+=2) status[i] = true;

    int rt = sqrt(MAXN);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < MAXN; j += i<<1)
                status[j] = true;

    primes.push_back(2);

    for(int i = 3; i < MAXN; i+=2)
        if(!status[i]) primes.push_back(i);
}

int calc_phi(int n)
{
    if(phi[n]) return phi[n];
    if(!status[n]) return phi[n] = n-1;

    int& ans = phi[n];

    ans = n;

    for(int i = 0; primes[i]*primes[i] <= n; ++i) {
        if(n % primes[i] == 0) {
            ans -= ans / primes[i];

            while(n % primes[i] == 0)
                n /= primes[i];
        }
    }

    if(n != 1) {
        ans /= n;
        ans *= n-1;
    }

    return ans;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    sieve();

    int ans[MAXN] = {0, 1};

    for(int i = 2; i < MAXN; ++i)
        ans[i] = ans[i-1] + (calc_phi(i) << 1);

    int n;

    while(scanf("%d", &n), n)
        printf("%d\n", ans[n]);

    return 0;
}
