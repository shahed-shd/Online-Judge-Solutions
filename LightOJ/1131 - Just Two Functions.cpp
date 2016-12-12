// ==================================================
// Problem  :   1131 - Just Two Functions
// Run time :   0.076 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

int mod;

struct mat6x6 {
    int mat[6][6];

    mat6x6() {
        fill(&mat[0][0], &mat[6][0], 0);
    }

    mat6x6 mul(mat6x6 &ob) {
        mat6x6 prod;

        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j < 6; ++j) {
                int &reff = prod.mat[i][j];

                for(int k = 0; k < 6; ++k) {
                    reff += mat[i][k] * ob.mat[k][j];
                    reff %= mod;
                }
            }
        }

        return prod;
    }

    mat6x6 expo(int pw) {
        if(pw == 1) {
            return *this;
        }

        mat6x6 res;

        res = expo(pw >> 1);
        res = res.mul(res);

        if(pw & 1) res = mul(res);

        return res;
    }
};

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int a1, b1, c1, a2, b2, c2, f[3], g[3], q;

        scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2, f, f+1, f+2, g, g+1, g+2, &mod, &q);

        printf("Case %d:\n", tc);

        mat6x6 T;
        T.mat[0][0] = a1, T.mat[0][1] = b1, T.mat[0][5] = c1;
        T.mat[1][0] = T.mat[2][1] = T.mat[4][3] = T.mat[5][4] = 1;
        T.mat[3][2] = c2, T.mat[3][3] = a2, T.mat[3][4] = b2;

        const int A[6] = {f[2], f[1], f[0], g[2],  g[1], g[0]};

        int n;

        while(q--) {
            scanf("%d", &n);

            if(n <= 2) {
                printf("%d %d\n", f[n] % mod, g[n] % mod);
                continue;
            }

            mat6x6 TT;

            TT = T.expo(n-2);

            int fn = 0, gn = 0;

            for(int i = 0; i < 6; ++i) {
                fn += TT.mat[0][i] * A[i];
                fn %= mod;
            }

            for(int i = 0; i < 6; ++i) {
                gn += TT.mat[3][i] * A[i];
                gn %= mod;
            }

            printf("%d %d\n", fn, gn);
        }
    }

    return 0;
}
