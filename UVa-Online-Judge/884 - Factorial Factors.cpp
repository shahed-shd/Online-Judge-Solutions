#include <cstdio>
#include <bitset>
using namespace std;

const int MAXN = 1000000+3;
int memo[MAXN] = {0};

int howMany(int num, int p)
{
    int cnt = 0;

    while(num % p == 0)
        num /= p, ++cnt;

    return cnt;
}

void sieve()
{
    bitset<MAXN> status;

    memo[2] = 1;

    for(int i = 4; i < MAXN; i+=2)
        memo[i] = howMany(i, 2);

    for(int i = 3; i < MAXN; i+=2) {
        if(!status[i]) {
            memo[i] = 1;

            for(int j = i+i; j < MAXN; j+=i) {
                status[j] = true;
                memo[j] += howMany(j, i);
            }
        }
    }

    for(int i = 3; i < MAXN; ++i)
        memo[i] += memo[i-1];
}

int main()
{
    sieve();

    int n;

    while(scanf("%d", &n) != EOF)
        printf("%d\n", memo[n]);

    return 0;
}
