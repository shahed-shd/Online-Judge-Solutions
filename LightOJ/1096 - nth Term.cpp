// ==================================================
// Problem  :   1096 - nth Term
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MOD = 10007;

struct mat4x4 {
    int mat[4][4];

    mat4x4() {
        fill(&mat[0][0], &mat[4][0], 0);
    }

    mat4x4 mul(mat4x4 &ob) {
        mat4x4 ret;

        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                for(int k = 0; k < 4; ++k)
                    ret.mat[i][j] += mat[i][k] * ob.mat[k][j], ret.mat[i][j] %= MOD;

        return ret;
    }

    mat4x4 expo(int pw) {
        mat4x4 ret;

        if(pw == 1) {
            copy(&mat[0][0], &mat[4][0], &ret.mat[0][0]);
            return ret;
        }

        if(pw & 1) {
            ret = expo(pw-1);
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
        int n, a, b, c;
        scanf("%d %d %d %d", &n, &a, &b, &c);

        int res = 0;

        if(n > 2) {
            mat4x4 T;
            T.mat[0][0] = a, T.mat[0][2] = b, T.mat[0][3] = 1;
            T.mat[1][0] = 1, T.mat[2][1] = 1, T.mat[3][3] = 1;

            T = T.expo(n-2);

            res = (T.mat[0][3] * c) % MOD;
        }

        printf("Case %d: %d\n", tc, res);
    }

    return 0;
}
