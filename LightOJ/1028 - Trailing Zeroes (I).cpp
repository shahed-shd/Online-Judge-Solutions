#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

typedef     long long       LL;

vector<int> primes;
int SZ;

void get_primes()
{
    const int P = 1e6 + 3;  // sqrt(1e12) = 1e6;

    bitset<P> status;

    int rt = 1e3 + 3;

    for(int i = 3; i < rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < P; j+=i<<1)
                status[j] = true;

    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);

    for(int i = 11; i < P; i += 2)
        if(!status[i])
            primes.push_back(i);
}

int numOfDivisors(LL num)
{
    int ret = 1;

    for(int i = 0; i < SZ && LL(primes[i])*primes[i] <= num; ++i) {
        if(num % primes[i] == 0) {
            int pw = 0;

            while(num % primes[i] == 0)
                num /= primes[i], ++pw;

            ret *= pw+1;
        }
    }

    if(num != 1) ret *= 2;

    return ret;
}

int main()
{
    get_primes();
    SZ = primes.size();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL n;
        scanf("%lld", &n);

        printf("Case %d: %d\n", tc, numOfDivisors(n)-1);
    }

    return 0;
}
