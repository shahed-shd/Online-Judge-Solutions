#include <cstdio>
#include <bitset>
#include <set>
#include <cmath>
using namespace std;

const int MAXN = 1e5 + 3;
bitset<MAXN> status;
double memo[MAXN];

void sieve()
{
    for(int i = 4; i < MAXN; i+=2)
        status[i] = true;

    int rt = sqrt(MAXN);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < MAXN; j+=(i<<1))
                status[j] = true;
}

double expectedValue(int n)
{
    if(n == 1) return 0;
    if(!status[n]) return 2;

    if(memo[n] != -1) return memo[n];

    set<int> factors;
    int rt = sqrt(n);

    for(int i = 2; i <= rt; ++i) {  // factors 1 and n are ignored.
        if(n % i == 0) {
            factors.insert(i);
            factors.insert(n/i);
        }
    }

    int sz = factors.size()+2;
    double& ret = memo[n] = 0;

    for(set<int>::iterator it = factors.begin(); it != factors.end(); ++it)
        ret += expectedValue(*it);

    ret /= sz;
    ret += 1;

    ret /= (1 - 1.0/sz);

    return ret;
}

int main()
{
    sieve();
    fill(memo, memo+MAXN, -1);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);
        printf("Case %d: %.8f\n", tc, expectedValue(n));
    }

    return 0;
}
