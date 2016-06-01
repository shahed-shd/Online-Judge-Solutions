#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXN = 100+3;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
int primesSize = sizeof(primes) / sizeof(primes[0]);

vector<vector<ii> > primeFactors(MAXN);

void primeFactorization(int num)
{
    vector<ii> &V = primeFactors[num];

    for(int i = 0; i < primesSize && primes[i]*primes[i] <= num; ++i) {
        if(num % primes[i] == 0) {
            int pw = 0;

            while(num % primes[i] == 0)
                num /= primes[i], ++pw;

            V.push_back(ii(primes[i], pw));
        }
    }

    if(num != 1) V.push_back(ii(num, 1));
}

void multiply(int num, int res[])
{
    int sz = primeFactors[num].size();

    for(int i = 0; i < sz; ++i) {
        ii &pr = primeFactors[num][i];
        res[pr.first] += pr.second;
    }
}

int main()
{
    for(int i = 2; i < MAXN; ++i)
        primeFactorization(i);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        int res[MAXN+1] = {0};

        for(int i = 2; i <= n; ++i)
            multiply(i, res);

        printf("Case %d: %d = ", tc, n);

        bool first = true;

        for(int i = 0; primes[i] <= n; ++i) {
            if(res[primes[i]]) {
                if(!first) printf(" * ");
                first = false;

                printf("%d (%d)", primes[i], res[primes[i]]);
            }
        }
        putchar('\n');
    }

    return 0;
}
