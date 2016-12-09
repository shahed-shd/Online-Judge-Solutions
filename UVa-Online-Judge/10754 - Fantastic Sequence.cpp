// ==================================================
// Problem  :   10754 - Fantastic Sequence
// Run time :   0.040 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <vector>
using namespace std;

typedef     long long       LL;

int k, m;

struct matrix {
    vector<vector<LL> > mat;

    matrix(int dim = k+1) {
        mat.resize(dim, vector<LL>(dim, 0));
    }

    matrix mul(matrix &ob) {
        matrix prod;

        for(int i = 0; i <= k; ++i) {
            for(int j = 0; j <= k; ++j) {
                LL &reff = prod.mat[i][j];
                reff = 0;

                for(int kk = 0; kk <= k; ++kk) {
                    reff += mat[i][kk] * ob.mat[kk][j];
                    reff %= m;
                }
            }
        }

        return prod;
    }

    matrix expo(int pw) {
        matrix res;

        if(pw == 1) {
            res.mat = mat;
            return res;
        }

        if(pw & 1) {
            res = expo(pw - 1);
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
    //freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d %d %d", &k, &m, &n);

        LL c[k+3], a[k+3];

        for(int i = 1; i <= k+1; ++i) {
            scanf("%lld", c+i);
            c[i] = ((c[i] % m) + m) % m;
        }

        for(int i = 0; i < k; ++i) {
            scanf("%lld", a+i);
            a[i] = ((a[i] % m) + m) % m;
        }

        if(n < k) {
            printf("%lld\n", a[n]);
            if(t) putchar('\n');
            continue;
        }

        matrix T;

        for(int i = 0; i < k; ++i)
            T.mat[0][i] = c[i+1];

        T.mat[0][k] = 1;

        for(int i = 1; i < k; ++i)
            T.mat[i][i-1] = 1;

        T.mat[k][k] = 1;

        T = T.expo(n-k+1);

        LL ans = 0;

        for(int i = 0; i < k; ++i) {
            ans += T.mat[0][i] * a[k-1-i];
            ans %= m;
        }

        ans += T.mat[0][k] * c[k+1];
        ans %= m;

        printf("%lld\n", ans);
        if(t) putchar('\n');
    }

    return 0;
}
