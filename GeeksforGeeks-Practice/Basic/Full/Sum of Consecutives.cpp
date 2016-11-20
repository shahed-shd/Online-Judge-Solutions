// ==================================================
// Problem  :   Sum of Consecutives
// Run time :   0.084 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        long long n;
        scanf("%lld", &n);

        puts(((n & (n-1)) && n > 1)? "1" : "0");
    }

    return 0;
}
