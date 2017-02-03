// ==================================================
// Problem  :   1132 - Summing up Powers
// Run time :   0.972 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <vector>
using namespace std;

typedef     long long           LL;
typedef     unsigned int        UI;

const int MAXK = 50+3;

UI nCr[MAXK][MAXK] = {{0}};

struct mat {
    int row, col;
    vector<vector<UI> > mt;

    mat(int r, int c) {
        row = r, col = c;
        mt.assign(row, vector<UI>(col, 0));
    }

    mat mul(const mat &ob) {
        mat prod(row, col);

        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                for(int x = 0; x < row; ++x)
                    prod.mt[i][j] += mt[i][x] * ob.mt[x][j];

        return prod;
    }

    mat expo(LL pw) {
        if(pw == 1) return *this;

        mat res(row, col);

        res = expo(pw >> 1);
        res = res.mul(res);

        if(pw & 1) res = mul(res);

        return res;
    }
};

void get_nCr()
{
    nCr[0][0] = 1;

    for(int i = 1; i < MAXK; ++i) {
        nCr[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    get_nCr();

    for(int tc = 1; tc <= t; ++tc) {
        LL n;
        int k;
        scanf("%lld %d", &n, &k);

        if(n == 1) {
            printf("Case %d: 1\n", tc);
            continue;
        }

        mat T(k+2, k+2);
        T.mt[0][0] = T.mt[0][1] = 1;

        for(int i = 1; i <= k+1; ++i) {
            int a = k-i+1, b = 0;
            for(int j = i; j <= k+1; ++j)
                T.mt[i][j] = nCr[a][b++];
        }

        T = T.expo(n-1);

        UI res = T.mt[0][0];
        for(int i = 1; i <= k+1; ++i)
            res += T.mt[0][i] * (1LL << (k-i+1));

        printf("Case %d: %u\n", tc, res);
    }

    return 0;
}
