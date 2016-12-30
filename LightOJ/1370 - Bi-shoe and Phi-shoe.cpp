// ==================================================
// Problem  :   1370 - Bi-shoe and Phi-shoe
// Run time :   0.084 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXR = 1e6 + 5;

int phi[MAXR];
int memo[MAXR];

void sieve()
{
    for(int i = 0; i < MAXR; ++i) phi[i] = i;

    phi[2] = 1;
    for(int i = 4; i < MAXR; i+=2) phi[i] >>= 1;

    for(int i = 3; i < MAXR; i+=2) {
        if(phi[i] == i) {
            --phi[i];
            for(int j = i+i; j < MAXR; j+=i)
                phi[j] -= phi[j] / i;
        }
    }
}

int main()
{
    sieve();
    phi[1] = 0; /*
                In problem description,
                "Φ (n) = numbers less than n which are relatively prime"
                But in mathematics,
                "Φ (n) = numbers less than or equal to n which are relatively prime"

                So, In this problem, we have to consider, Φ(1) = 0.
                but Φ(1) = 1.

                Reference link:
                http://oeis.org/A000010
                https://en.wikipedia.org/wiki/Euler's_totient_function
                */

    fill(memo, memo+MAXR, INT_MAX);

    for(int i = 1; i < MAXR; ++i)
        memo[phi[i]] = min(memo[phi[i]], i);

    int currMinLen = memo[MAXR-1];

    for(int i = MAXR-1; i > 0; --i)
        memo[i] = currMinLen = min(memo[i], currMinLen);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        int num;
        long long ans = 0;

        while(n--) {
            scanf("%d", &num);
            ans += memo[num];
        }

        printf("Case %d: %lld Xukha\n", tc, ans);
    }

    return 0;
}
