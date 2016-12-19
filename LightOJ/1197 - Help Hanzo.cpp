// ==================================================
// Problem  :   1197 - Help Hanzo
// Run time :   0.128 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

typedef     long long       LL;
                            // MAXN = 2147483647;
const int RT = 46340 + 3;   // 46340 = floor(sqrt(MAXN));

vector<int> primes;

void sieve()
{
    bitset<RT> status;
    int rt = sqrt(RT);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < RT; j += (i<<1))
                status[j] = true;

    for(int i = 3; i < RT; i+=2)
        if(!status[i])
            primes.push_back(i);
}

int getPrimeCnt(LL low, LL upto)
{
    LL high = min(low+RT, upto);
    int cnt = 0, sz = primes.size();

    while(low <= upto) {
        bitset<RT+3> status;

        for(int i = 0; i < sz; ++i) {
            LL s = ceil(1.0 * low / primes[i]) * primes[i];
            if(!(s & 1)) s += primes[i];

            for(LL j = s; j <= high; j += (primes[i] << 1))
                status[j-low] = true;
        }

        for(LL i = low + !(low&1); i <= high; i+=2)
            if(!status[i-low])
                ++cnt;

        low = high + 1;
        high = min(low+RT, upto);
    }

    return cnt;
}

int main()
{
    sieve();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int a, b;
        scanf("%d %d", &a, &b);

        int ans = (a <= 2 && 2 <= b);

        if(b < RT) {
            ans += distance(lower_bound(primes.begin(), primes.end(), a), upper_bound(primes.begin(), primes.end(), b));
        }
        else {
            ans += distance(lower_bound(primes.begin(), primes.end(), a), primes.end());
            ans += getPrimeCnt(max(a, RT), b);
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
