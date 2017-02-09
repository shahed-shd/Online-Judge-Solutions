// ==================================================
// Problem  :   11 - Factorial
// Run time :   0.020 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int a = 5, r = 0;

        while(n/a > 0) r += n/a, a *= 5;

        printf("%d\n", r);
    }

    return 0;
}
