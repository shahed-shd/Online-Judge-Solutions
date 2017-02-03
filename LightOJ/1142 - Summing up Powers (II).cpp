// ==================================================
// Problem  :   1142 - Summing up Powers (II)
// Run time :   0.120 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <vector>
using namespace std;

const int MOD = 10;
int n;

struct matrix {
    vector<vector<int> > mt;

    matrix() {
        mt.assign(n, vector<int>(n, 0));
    }

    matrix operator+(const matrix &ob) {
        matrix sum;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                sum.mt[i][j] = (mt[i][j] + ob.mt[i][j]) % MOD;

        return sum;
    }

    matrix operator*(const matrix &ob) {
        matrix prod;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    prod.mt[i][j] += mt[i][k] * ob.mt[k][j];
                }

                prod.mt[i][j] %= MOD;
            }
        }

        return prod;
    }
};

struct mat {
    matrix mm[2][2];

    mat operator+(const mat &ob) {
        mat sum;

        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 2; ++j)
                sum.mm[i][j] = mm[i][j] + ob.mm[i][j];

        return sum;
    }

    mat operator*(const mat &ob) {
        mat prod;

        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 2; ++k)
                    prod.mm[i][j] = prod.mm[i][j] + (mm[i][k] * ob.mm[k][j]);

        return prod;
    }

    mat expo(int pw) {
        if(pw == 1) return *this;

        mat res = expo(pw >> 1);
        res = res * res;

        if(pw & 1) res = (*this) * res;

        return res;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int k;
        scanf("%d %d", &n, &k);

        matrix a;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &a.mt[i][j]);

        mat b;
        b.mm[0][0] = b.mm[0][1] = a;            // A A
        b.mm[1][0] = b.mm[1][1] = matrix();     // O I

        matrix &I = b.mm[1][1];
        for(int i = 0; i < n; ++i) I.mt[i][i] = 1;

        vector<vector<int> > ans = (b.expo(k).mm[0][1]).mt;

        printf("Case %d:\n", tc);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                printf("%d", ans[i][j]);
            }
            putchar('\n');
        }
    }

    return 0;
}
