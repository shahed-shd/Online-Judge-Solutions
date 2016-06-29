#include <cstdio>
#include <algorithm>
using namespace std;

typedef     long long       LL;

int mod;

class matrix {
    int mat[2][2];

    void multiply(int a[2][2], int b[2][2], int res[2][2]) {        // (a * b) % mod = res.
        res[0][0] = (LL(a[0][0])*b[0][0] + LL(a[0][1])*b[1][0]) % mod;
        res[0][1] = (LL(a[0][0])*b[0][1] + LL(a[0][1])*b[1][1]) % mod;
        res[1][0] = (LL(a[1][0])*b[0][0] + LL(a[1][1])*b[1][0]) % mod;
        res[1][1] = (LL(a[1][0])*b[0][1] + LL(a[1][1])*b[1][1]) % mod;
    }

    void power(int mt[2][2], int p, int res[2][2]) {                // (mt^p) % mod = res.
        if(p == 0 || p == 1) {
            copy(&mt[0][0], &mt[2][0], &res[0][0]);
            return;
        }

        int tmp[2][2];

        power(mt, p>>1, tmp);
        multiply(tmp, tmp, res);

        if(p & 1) {
            multiply(res, mt, tmp);
            copy(&tmp[0][0], &tmp[2][0], &res[0][0]);
        }
    }

public:
    matrix(int a00, int a01, int a10, int a11) {
        mat[0][0] = a00, mat[0][1] = a01, mat[1][0] = a10, mat[1][1] = a11;
    }

    void raise_to_the_power(int p) {
        int res[2][2];

        power(mat, p, res);
        copy(&res[0][0], &res[2][0], &mat[0][0]);
    }

    int get_first_element() { return mat[0][0]; }
};

int fib(int n)
{
    matrix mtr(1, 1, 1, 0);

    mtr.raise_to_the_power(n-1);

    return mtr.get_first_element();
}


int main()
{
    //freopen("in", "r", stdin);

    int n, m;

    while(~scanf("%d %d", &n, &m)) {
        mod = 1 << m;
        printf("%d\n", ((n)? fib(n) : 0));
    }

    return 0;
}
