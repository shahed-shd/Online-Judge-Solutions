// ==================================================
// Problem  :   1375 - LCM Extreme
// Run time :   0.604 sec.
// Language :   C++
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;

typedef     unsigned long long      ULL;

const int MAXN = 3e6 + 3;

int phi[MAXN];
ULL ans[MAXN];

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

void sieve1()
{
    for(int i = 0; i < MAXN; ++i) phi[i] = i;

    for(int i = 0; i < MAXN; i+=2) phi[i] >>= 1;

    for(int i = 3; i < MAXN; i+=2) {
        if(phi[i] == i) {
            --phi[i];
            for(int j = i+i; j < MAXN; j+=i) phi[j] -= phi[j] / i;
        }
    }
}

void sieve2()
{
    fill(ans, ans+MAXN, 1);

    for(int i = 2; i < MAXN; ++i)
        for(int j = i; j < MAXN; j+=i)
            ans[j] += ULL(i) * phi[i];
}

int main()
{
    sieve1();
    sieve2();

    ans[0] = 0;
    for(int i = 1; i < MAXN; ++i)
        ans[i] = ans[i-1] + ((ans[i] - 1) >> 1) * i;

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>();
        printf("Case %d: %llu\n", tc, ans[n]);
    }

    return 0;
}
