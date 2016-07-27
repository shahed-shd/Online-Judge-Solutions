#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

const int MAXNUM =  60000+3;

vector<int> primes;

void sieve()
{
    primes.push_back(2);

    bitset<MAXNUM> status;
    int rt = sqrt(MAXNUM);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < MAXNUM; j+=(i<<1))
                status[j] = true;

    for(int i = 3; i < MAXNUM; i+=2)
        if(!status[i])
            primes.push_back(i);
}

int sum_of_all_divisors(int n)
{
    int sum = 1;

    for(int i = 0; primes[i]*primes[i] <= n; ++i) {
        if(n % primes[i] == 0) {
            int pw_res = 1;

            while(n % primes[i] == 0) {
                pw_res *= primes[i];
                n /= primes[i];
            }

            pw_res *= primes[i];

            sum *= (pw_res - 1) / (primes[i] - 1);
        }
    }

    if(n != 1) sum *= (1 + n);

    return sum;
}

int main()
{
    sieve();

    puts("PERFECTION OUTPUT");
    int n;

    while(scanf("%d", &n), n) {
        printf("%5d  ", n);

        int s = sum_of_all_divisors(n);
        s -= n;

        if(s == n) puts("PERFECT");
        else if(s < n) puts("DEFICIENT");
        else puts("ABUNDANT");
    }

    puts("END OF OUTPUT");

    return 0;
}
