// ==================================================
// Problem  :   5971 - LCM Sum
// Run time :   0.130 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

typedef     unsigned long long      ULL;

const int MAXN = 1e6 + 3;

int phi[MAXN];
ULL memo[MAXN];

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
    fill(memo, memo+MAXN, 1);

    for(int i = 2; i < MAXN; ++i) {
        ULL tmp = ULL(i) * phi[i];

        for(int j = i; j < MAXN; j+=i)
            memo[j] += tmp;
    }
}

int main()
{
    sieve1();
    sieve2();

    //memo[0] = 0;

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>();

        ULL ans = ((memo[n] + 1) >> 1) * n;

        printf("%llu\n", ans);
    }

    return 0;
}
