// ==================================================
// Problem  :   Find the pattern
// Run time :   0.084 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

const int MOD = 1e9 + 7;

struct matrix {
    LL a, b, c, d;      //  a b
                        //  c d
    matrix mul(const matrix ob) {
        matrix prod;

        prod.a = (a*ob.a + b*ob.c) % MOD;
        prod.b = (a*ob.b + b*ob.d) % MOD;
        prod.c = (c*ob.a + d*ob.c) % MOD;
        prod.d = (c*ob.b + d*ob.d) % MOD;

        return prod;
    }

    matrix pow(int p) {
        if(p == 1) {
            return {2, 5, 1, 0};
        }

        if(p & 1) {
            return pow(p-1).mul({2, 5, 1, 0});
        }
        else {
            matrix m = pow(p/2);
            return m.mul(m);
        }
    }
};

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int ans;

        if(n == 1) ans = 1;
        else if(n == 2) ans = 1;
        else {
            matrix m = {2, 5, 1, 0};
            matrix mm = m.pow(n-2);
            ans = (mm.a + mm.b) % MOD;
        }

        printf("%d\n", ans);
    }

    return 0;
}
