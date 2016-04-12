// Run time : 0.000 sec
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1e9+3;
const int SQRT = sqrt(MAXN);

vector<int> primes;
short divisorCount[MAXN] = {0};

void sieve()
{
    bitset<SQRT+2> status;

    for(int i = 4; i <= SQRT; i+=2) status[i] = true;

    for(int i = 3; i <= SQRT; i+=2)
        if(!status[i])
            for(int j = i*i; j <= SQRT; j+=(i<<1))
                status[j] = true;

    primes.push_back(2);
    for(int i = 3; i <= SQRT; i+=2)
        if(!status[i]) primes.push_back(i);
}

int howManyDivisors(int n)
{
    if(divisorCount[n]) return divisorCount[n];
    int n1 = n;

    int cnt = 1;

    for(int i = 0; primes[i]*primes[i] <= n; ++i) {
        if(i >= int(primes.size())) return divisorCount[n1] = 2;    // As it is prime.

        if(n % primes[i] == 0) {
            int tmp = 0;

            while(n % primes[i] == 0) {
                n /= primes[i];
                ++tmp;
            }

            cnt *= tmp+1;
        }
    }

    if(n != 1) cnt *= 2;

    return divisorCount[n] = cnt;
}

int main()
{
    sieve();

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int lower, upper;
        scanf("%d %d", &lower, &upper);

        int mxDivCnt = 0, mxDivNum;

        for(int i = lower; i <= upper; ++i) {
            if(howManyDivisors(i) > mxDivCnt) {
                mxDivCnt = howManyDivisors(i);
                mxDivNum = i;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n", lower, upper, mxDivNum, mxDivCnt);
    }

    return 0;
}


// ----------------- Alternatively -----------------
// Run time : 0.010 sec.
/*
#include <cstdio>
using namespace std;

const int MAXN = 1e9+3;

short divisorCount[MAXN] = {0};

int howManyDivisors(int n)
{
    if(divisorCount[n]) return divisorCount[n];

    int cnt = 1;

    int pow = 0;
    while(n % 2 == 0) {
        ++pow;
        n /= 2;
    }
    if(pow) cnt *= pow+1;

    for(int i = 3; i*i <= n; i+=2) {
        pow = 0;

        while(n % i == 0) {
            ++pow;
            n /= i;
        }

        if(pow) cnt *= pow+1;
    }

    if(n != 1) cnt *= 2;

    return divisorCount[n] = cnt;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int lower, upper;
        scanf("%d %d", &lower, &upper);

        int mxDivCnt = 0, mxDivNum;

        for(int i = lower; i <= upper; ++i) {
            if(howManyDivisors(i) > mxDivCnt) {
                mxDivCnt = howManyDivisors(i);
                mxDivNum = i;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n", lower, upper, mxDivNum, mxDivCnt);
    }

    return 0;
}
*/
