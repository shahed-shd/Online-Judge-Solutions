// ==================================================
// Problem  :   705B - Spider Man
// Run time :   0.046 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

int main()
{
    int n;

    while(~scanf("%d", &n)) {
        LL cumulative = 0, curr;

        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", &curr);

            cumulative += curr;

            LL rem = cumulative - i;

            puts((rem & 1)? "1" : "2");
        }
    }

    return 0;
}
