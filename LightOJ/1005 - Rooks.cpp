#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

typedef     long long       LL;
typedef     pair<int,int>   ii;

const int MAXN = 30;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
vector<vector<ii> > factors(MAXN+1);

void primeFactorization(int num)
{
    vector<ii> &V = factors[num];

    for(int i = 0; primes[i]*primes[i] <= num; ++i) {
        if(num % primes[i] == 0) {
            int cnt = 0;

            while(num % primes[i] == 0) {
                num /= primes[i];
                ++cnt;
            }

            V.push_back(ii(primes[i], cnt));
        }
    }

    if(num != 1) V.push_back(ii(num, 1));
}

void multiply(int num, int res[])
{
    int sz = factors[num].size();

    for(int i = 0; i < sz; ++i)
        res[factors[num][i].first] += factors[num][i].second;
}

void divide(int num, int res[])
{
    int sz = factors[num].size();

    for(int i = 0; i < sz; ++i)
        res[factors[num][i].first] -= factors[num][i].second;
}

LL getRes(int num, int pw)
{
    LL ret = 1;
    while(pw--) ret *= num;
    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    for(int i = 2; i <= MAXN; ++i)
        primeFactorization(i);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, k;
        scanf("%d %d", &n, &k);

        printf("Case %d: ", tc);

        if(k > n) {
            puts("0");
            continue;
        }
        else if(k == 0) {
            puts("1");
            continue;
        }
        else if(k == 1) {
            printf("%d\n", n*n);
            continue;
        }

        int res[MAXN+1] = {0};

        for(int i = n-k+1; i <= n ; ++i)
            multiply(i, res);

        for(int i = 2; i <= n; ++i)
            res[i] *= 2;

        for(int i = 2; i <= k; ++i)
            divide(i, res);

        LL ans = 1;

        for(int i = 2; i <= n; ++i)
            if(res[i] > 0) ans *= getRes(i, res[i]);

        for(int i = 2; i <= n; ++i)
            if(res[i] < 0) ans /= getRes(i, -res[i]);

        printf("%lld\n", ans);
    }

    return 0;
}
