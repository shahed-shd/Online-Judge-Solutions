// ==================================================
// Problem  :   Composite and Prime
// Run time :   0.570 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1e7 + 3;

vector<int> memo(MAXN, 1);

void sieve()
{
    memo[0] = memo[1] = 0;
    for(int i = 4; i < MAXN; i += 2) memo[i] = 0;

    int rt = sqrt(MAXN);

    for(int i = 3; i <= rt; i += 2)
        if(memo[i])
            for(int j = i*i; j < MAXN; j += (i<<1))
                memo[j] = 0;

    for(int i = 1; i < MAXN; ++i)
        memo[i] += memo[i-1];
}

int main()
{
    sieve();

    int t;
    scanf("%d", &t);

    while(t--) {
        int L, R;
        scanf("%d %d", &L, &R);

        int p = memo[R] - memo[L-1];
        int comp = R-L+1 - p;
        if(L <= 1 && 1 <= R) --comp;

        printf("%d\n", comp - p);
    }

    return 0;
}
