// ==================================================
// Problem  :   1065 - Number Sequence
// Run time :   0.020 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

int mod;

struct mat2x2 {
    int a, b;
    int c, d;

    mat2x2(int aa = 0, int bb = 0, int cc = 0, int dd = 0) {
        a = aa, b = bb, c = cc, d = dd;
    }

    mat2x2 mul(mat2x2 &ob) {
        mat2x2 ret;

        ret.a = (a * ob.a + b * ob.c) % mod;
        ret.b = (a * ob.b + b * ob.d) % mod;
        ret.c = (c * ob.a + d * ob.c) % mod;
        ret.d = (c * ob.b + d * ob.d) % mod;

        return ret;
    }

    mat2x2 expo(int pw) {
        mat2x2 ret;

        if(pw == 1) {
            ret.a = a, ret.b = b, ret.c = c, ret.d = d;
            return ret;
        }

        if(pw & 1) {
            ret = expo(pw - 1);
            ret = this->mul(ret);
        }
        else {
            ret = expo(pw >> 1);
            ret = ret.mul(ret);
        }

        return ret;
    }
};

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int a, b, n, m;
        scanf("%d %d %d %d", &a, &b, &n, &m);

        mod = pow(10, m);

        mat2x2 T(0, 1, 1, 1);
        T = T.expo(n);

        int res = (T.a * a + T.b * b) % mod;

        printf("Case %d: %d\n", tc, res);
    }

    return 0;
}
