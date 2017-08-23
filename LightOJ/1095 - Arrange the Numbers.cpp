// ==================================================
// Problem  :   1095 - Arrange the Numbers
// Run time :   0.008 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

const int MAXN = 1000 + 3;
const int MOD = 1000000007;

int nCr[MAXN][MAXN], fact[MAXN];

int perm(int n, int k)      // Permutations with k non-fixed points.
{
    LL res = fact[n];

    for(int i = 1; i <= k; ++i) {
        res += ((i & 1)? -1: 1) * LL(nCr[k][i]) * fact[n-i];    // Inclusion–exclusion principle.
        res = (res + MOD) % MOD;
    }

    return res;
}

int main()
{
    for(int i = 0; i < MAXN; ++i)
        nCr[i][0] = nCr[i][i] = 1;

    for(int i = 2; i < MAXN; ++i)
        for(int j = 1; j < i; ++j)
            nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % MOD;

    fact[0] = 1;
    for(int i = 1; i < MAXN; ++i)
        fact[i] = (LL(i) * fact[i-1]) % MOD;

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        int res = (LL(nCr[m][k]) * perm(n-k, m-k)) % MOD;

        printf("Case %d: %d\n", tc, res);
    }

    return 0;
}



// -------------------- Alternatively --------------------
// Run time :   0.016 sec.

/*
#include <cstdio>
using namespace std;

typedef     long long       LL;

const int MAXN = 1000 + 3;
const int MOD = 1000000007;

int nCr[MAXN][MAXN], fact[MAXN], perm[MAXN][MAXN];

int main()
{
    for(int i = 0; i < MAXN; ++i)
        nCr[i][0] = nCr[i][i] = 1;

    for(int i = 2; i < MAXN; ++i)
        for(int j = 1; j < i; ++j)
            nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % MOD;

    fact[0] = 1;
    for(int i = 1; i < MAXN; ++i)
        fact[i] = (LL(i) * fact[i-1]) % MOD;

    perm[0][0] = 1;
    perm[1][0] = 1, perm[1][1] = 0;

    for(int i = 2; i < MAXN; ++i) {
        perm[i][0] = fact[i];
        perm[i][1] = (LL(i-1) * perm[i-1][0]) % MOD;

        for(int j = 2; j <= i; ++j) {
            LL a = LL(i - j) * perm[i-1][j-1];
            LL b = LL(j - 1) * (perm[i-1][j-1] + perm[i-2][j-2]);
            perm[i][j] = (a + b) % MOD;
        }
    }

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        int res = (LL(nCr[m][k]) * perm[n-k][m-k]) % MOD;

        printf("Case %d: %d\n", tc, res);
    }

    return 0;
}
*/
