// ==================================================
// Problem  :   Sansa and XOR
// Score    :   30 /30
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

        int res = 0;

        if(n & 1) { // If n is odd, the result will be xor of a1, a3, a5 ... an
            int a;
            scanf("%d", &a);

            res ^= a;

            int k = (n-1) / 2;

            while(k--) {
                scanf("%*d %d", &a);
                res ^= a;
            }
        }
        else {      // If n is even, the result is 0.
            for(int i = 1; i <= n; ++i)
                scanf("%*d");
        }

        printf("%d\n", res);
    }

    return 0;
}
