// ==================================================
// Problem  :   1538D - Another Problem About Dividing Numbers
// Run time :   0.187 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;


const int PRIMES_UPTO = 31622 + 3; // 31622 = sqrt(1e9)
vector<int> primes;


void sieve()
{
    bitset<PRIMES_UPTO> status;
    primes.push_back(2);
    int rt = sqrt(PRIMES_UPTO);

    for (int i = 3; i <= rt; i += 2) {
        if (!status[i]) {
            primes.push_back(i);

            for (int j = i * i; j < PRIMES_UPTO; j += (i << 1)) {
                status[j] = true;
            }
        }
    }

    for (int i = rt + ((rt & 1) == 0); i < PRIMES_UPTO; i += 2) {
        if (!status[i]) {
            primes.push_back(i);
        }
    }
}


int calcMaxTurn(int x)
{
    int cnt = 0;
    int rt = sqrt(x);

    for (const int& prime : primes) {
        if (prime > rt) break;
        
        while (x % prime == 0) {
            ++cnt;
            x /= prime;
        }
    }

    if (x != 1) ++cnt;
    return cnt;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    sieve();

    int t;
    scanf("%d", &t);

    while (t--) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);

        bool ans;

        if (k == 1) {
            if (a == b) {
                ans = false;
            }
            else if (a % b == 0 || b % a == 0) {
                ans = true;
            }
            else {
                ans = false;
            }
        } else {
            int max_turn = calcMaxTurn(a) + calcMaxTurn(b);
            ans = (k <= max_turn);
        }
        printf("%s\n", ans? "YES" : "NO");
    }

    return 0;
}
