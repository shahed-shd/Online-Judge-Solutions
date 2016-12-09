// ==================================================
// Problem  :   10870 - Recurrences
// Run time :   0.010 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <vector>
using namespace std;

int d, m;

struct matrix {
    vector<vector<int> > mat;

    matrix(int row, int col) {
        mat.resize(row, vector<int>(col, 0));
    }

    matrix mul(matrix &ob) {
        matrix prod(d, d);

        for(int i = 0; i < d; ++i) {
            for(int j = 0; j < d; ++j) {
                int &reff = prod.mat[i][j];
                reff = 0;

                for(int k = 0; k < d; ++k) {
                    reff += mat[i][k] * ob.mat[k][j];
                    reff %= m;
                }
            }
        }

        return prod;
    }

    matrix expo(int pw) {
        matrix res(d, d);

        if(pw == 1) {
            res.mat = mat;
            return res;
        }

        if(pw & 1) {
            res = expo(pw-1);
            res = mul(res);
        }
        else {
            res = expo(pw >> 1);
            res = res.mul(res);
        }

        return res;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);

    int n;

    while(scanf("%d %d %d", &d, &n, &m), d || n || m) {
        int coefficients[d+3], f[d+3];

        for(int i = 1; i <= d; ++i) {
            scanf("%d", coefficients+i);
            coefficients[i] %= m;
        }

        for(int i = 1; i <= d; ++i) {
            scanf("%d", f+i);
            f[i] %= m;
        }

        if(n <= d) {
            printf("%d\n", f[n]);
            continue;
        }

        matrix T(d, d);

        for(int i = 0; i < d; ++i)
            T.mat[0][i] = coefficients[i+1];

        for(int i = 1; i < d; ++i)
            T.mat[i][i-1] = 1;

        T = T.expo(n-d);

        int ans = 0;

        for(int i = 0; i < d; ++i) {
            ans += T.mat[0][i] * f[d-i];
            ans %= m;
        }

        printf("%d\n", ans);
    }

    return 0;
}
