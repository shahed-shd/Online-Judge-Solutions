// ==================================================
// Problem  :   Unique Code
// Runtime  :   0.000 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

int main()
{
    LL num;
    scanf("%lld", &num);

    while(num >= 10) {
        LL prod = 1;

        while(num) {
            int dig = num % 10;
            if(dig) prod *= dig;
            num /= 10;
        }

        num = prod;
    }

    printf("%lld\n", num);

    return 0;
}
