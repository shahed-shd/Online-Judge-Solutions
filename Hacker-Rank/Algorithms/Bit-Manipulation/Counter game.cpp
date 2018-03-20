// ==================================================
// Problem  :   Counter game
// Score    :   30 /30
// Language :   C++14
// ==================================================


#include <cstdio>
using namespace std;


typedef     unsigned long long      ULL;


int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        ULL n;
        scanf("%llu", &n);

        ULL p = n & (-n);
        ULL k = n - p;

        int turn_cnt = 0;

        // If 'n' is not a power of 2, reduce the counter by the largest power of 2 less than 'n'.
        while(k) {
            if(k & 1) ++turn_cnt;
            k >>= 1;
        }

        // If 'n' is a power of 2, reduce the counter by half of 'n'.
        while(p != 1) {
            p >>= 1;
            ++turn_cnt;
        }

        puts((turn_cnt & 1)? "Louise" : "Richard");
    }

    return 0;
}
