// ==================================================
// Problem  :   472A - Design Tutorial: Learn from Math
// Run time :   0.030 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(!(n & 1)) return false;

    int rt = sqrt(n);

    for(int i = 3; i <= rt; i += 2)
        if(n % i == 0)
            return false;

    return true;
}

int main()
{
    int n;

    while(~scanf("%d", &n)) {
        int x = 4, y;

        while(y = n-x, isPrime(y)) x += 2;

        printf("%d %d\n", x, y);
    }

    return 0;
}
