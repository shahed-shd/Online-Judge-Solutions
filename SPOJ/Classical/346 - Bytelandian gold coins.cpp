// ==================================================
// Problem  :   346 - Bytelandian gold coins
// Run time :   0.21 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const unsigned int N = 1e8 + 3;
unsigned int memo[N];

inline unsigned int get(unsigned a)
{
    if(a < N) return memo[a];

    return max(a, get(a>>1) + get(a/3) + get(a>>2));
}

int main()
{
    memo[0] = 0;
    memo[1] = 1;

    for(unsigned i = 2; i < N; ++i)
        memo[i] = max(i, memo[i>>1] + memo[i/3] + memo[i>>2]);

    unsigned int a;

    while(~scanf("%u", &a))
        printf("%u\n", max(a, get(a>>1) + get(a/3) + get(a>>2)));

    return 0;
}
