// ==================================================
// Problem  :   Chef and Cake
// Run time :   1.690 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

#define     ff              first
#define     ss              second

typedef     long long       LL;
typedef     pair<int,int>   ii;

const int MAXN = 1e7 + 3;
const int MOD = 1e9 + 7;

int swm[MAXN];      // Sliding window minimum

int main()
{
    //freopen("in.txt", "r", stdin);

    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);

    int a, b, c, d, e, f, r, s, t, m;
    LL prevAi, currAi;
    scanf("%d %d %d %d %d %d %d %d %d %d %lld", &a, &b, &c, &d, &e, &f, &r, &s, &t, &m, &prevAi);

    swm[1] = prevAi;
    deque<ii> Q;
    Q.push_back(ii(prevAi, 1));
    prevAi %= m;

    LL tt = t;

    for(int i = 2; i <= n; ++i) {
        tt = (tt * t) % s;
        if(tt <= r) {
            currAi = (a * ((prevAi * prevAi) % m)) % m;
            currAi += (b * prevAi) % m;
            currAi += c;
            currAi %= m;
        }
        else {
            currAi = (d * ((prevAi * prevAi) % m)) % m;
            currAi += (e * prevAi) % m;
            currAi += f;
            currAi %= m;
        }

        while(!Q.empty() && Q.back().ff >= currAi)
            Q.pop_back();

        Q.push_back(ii(currAi, i));

        while(!Q.empty() && Q.front().ss <= i-k)
            Q.pop_front();

        swm[i] = Q.front().ff;
        prevAi = currAi;
    }

    LL L1, La, Lc, Lm, D1, Da, Dc, Dm;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &L1, &La, &Lc, &Lm, &D1, &Da, &Dc, &Dm);

    LL sum = 0, prod = 1;

    while(q--) {
        L1 = (La * L1 + Lc) % Lm;
        D1 = (Da * D1 + Dc) % Dm;
        int L = L1 + 1;
        int R = min(L+k-1+D1, LL(n));

        int mn = min(swm[L+k-1], swm[R]);
        sum += mn;
        prod = (prod * mn) % MOD;
    }

    printf("%lld %lld\n", sum, prod);

    return 0;
}
