#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXN = 1000+3;

vector<int> primes;
vector<ii> V;

void sieve()
{
    bitset<MAXN> status;

    primes.push_back(2);

    for(int i = 3; i < MAXN; i+=2) {
        if(!status[i]) {
            primes.push_back(i);

            for(int j = i*i; j < MAXN; j+=(i<<1))
                status[j] = true;
        }
    }
}

int howManyDivisors(int num)
{
    int cnt = 1;

    for(int i = 0; primes[i]*primes[i] <= num; ++i) {
        if(num % primes[i] == 0) {
            int pw = 0;

            while(num % primes[i] == 0)
                num /= primes[i], ++pw;

            cnt *= pw+1;
        }
    }

    if(num != 1) cnt *= 2;

    return cnt;
}

bool myCmp(const ii &a, const ii &b)
{
    if(a.first != b.first) return (a.first < b.first);
    return (a.second > b.second);
}

void preprocess()
{
    sieve();

    for(int i = 1; i <= 1000; ++i)
        V.push_back(ii(howManyDivisors(i), i));

    sort(V.begin(), V.end(), myCmp);
}

int main()
{
    //freopen("in", "r", stdin);

    preprocess();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        printf("Case %d: %d\n", tc, V[n-1].second);
    }

    return 0;
}
