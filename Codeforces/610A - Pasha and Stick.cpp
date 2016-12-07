// ==================================================
// Problem  :   610A - Pasha and Stick
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    int n;

    while(~scanf("%d", &n)) {
        int ans = 0;

        if(!(n & 1)) {
            n >>= 1;
            --n;
            ans = n >> 1;
        }

        printf("%d\n", ans);
    }

    return 0;
}
