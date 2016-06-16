// Algorithm    :   Knuth-Morris-Pratt (KMP) algorithm.
// Run time : 0.068 sec.

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 1e6 + 3;

void computeLPSArray(char b[], int m, int lps[])
{
    lps[0] = 0;
    int len = 0;

    for(int i = 1; i < m; ) {
        if(b[i] == b[len]) {
            lps[i++] = ++len;
        }
        else {
            if(len != 0)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
    }
}

int KMPSearch(char a[], char b[])
{
    int n = strlen(a), m = strlen(b);

    int lps[m+3];
    computeLPSArray(b, m, lps);

    int i = 0, j = 0, cnt = 0;

    while(i < n) {
        if(a[i] == b[j]) {
            ++i, ++j;
        }

        if(j == m) {
            ++cnt;
            j = lps[j-1];
        }

        else if(i < n && a[i] != b[j]) {
            if(j != 0) j = lps[j-1];
            else ++i;
        }
    }

    return cnt;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc){
        char a[MAXL], b[MAXL];
        scanf("%s %s", a, b);

        printf("Case %d: %d\n", tc, KMPSearch(a, b));
    }
    return 0;
}



// ------------------------------ Alternatively ------------------------------
// Algorithm    :   Rabin-Karp algorithm (modified).
// Run time     :   0.120 sec.
/*
#include <cstdio>
#include <cstring>
using namespace std;

typedef     long long       LL;

const int MAXL = 1e6 + 3, BASE1 = 31, BASE2 = 37, MOD1 = 1e9+7, MOD2 = 1e9+9;

LL modular_pow(LL base, LL exponent, LL modulus)
{
    if(modulus == 1) return 0;

    LL result = 1;
    base %= modulus;

    while(exponent > 0) {
        if(exponent & 1) {
            result = (result * base) % modulus;
        }

        exponent >>= 1;
        base = (base * base) % modulus;
    }

    return result;
}

int Rabin_Karp_modified(char a[], char b[])
{
    int n = strlen(a), m = strlen(b);

    LL h1 = modular_pow(BASE1, m-1, MOD1), h2 = modular_pow(BASE2, m-1, MOD2);
    LL hash_a1 = 0, hash_a2 = 0, hash_b1 = 0, hash_b2 = 0;

    for(int i = 0; i < m; ++i) {
        hash_b1 = (hash_b1 * BASE1 + b[i]) % MOD1;
        hash_b2 = (hash_b2 * BASE2 + b[i]) % MOD2;

        hash_a1 = (hash_a1 * BASE1 + a[i]) % MOD1;
        hash_a2 = (hash_a2 * BASE2 + a[i]) % MOD2;
    }

    int cnt = 0;

    for(int i = 0; i <= n-m; ++i) {
        if(hash_b1 == hash_a1 && hash_b2 == hash_a2) ++cnt;

        if(i < n-m) {
            hash_a1 = ((hash_a1 - a[i]*h1) * BASE1 + a[i+m]) % MOD1;
            hash_a2 = ((hash_a2 - a[i]*h2) * BASE2 + a[i+m]) % MOD2;

            if(hash_a1 < 0) hash_a1 += MOD1;
            if(hash_a2 < 0) hash_a2 += MOD2;
        }
    }

    return cnt;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc){
        char a[MAXL], b[MAXL];
        scanf("%s %s", a, b);

        printf("Case %d: %d\n", tc, Rabin_Karp_modified(a, b));
    }

    return 0;
}
*/
