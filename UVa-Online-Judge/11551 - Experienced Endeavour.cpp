// ==================================================
// Problem  :   11551 - Experienced Endeavour
// Run time :   0.020 sec
// Language :   C++11
// ==================================================


#include <cstdio>
#include <vector>
using namespace std;


typedef     long long       LL;


const int MOD = 1000;


class Matrix {
public:
    vector<vector<int>> mat;

    Matrix(int row, int col, int value = 0) {
        mat.resize(row, vector<int>(col, value));
    }

    inline int getRowCount() const { return mat.size(); }

    inline int getColumnCount() const { return mat[0].size(); }

    Matrix multiply(const Matrix &other) const {
        int prodRowCount = getRowCount();
        int prodColCount = other.getColumnCount();
        int eachElemLoopCount = getColumnCount();

        Matrix prod(prodRowCount, prodColCount, 0);

        for (int r = 0; r < prodRowCount; ++r) {
            for (int c = 0; c < prodColCount; ++c) {
                int &ref = prod.mat[r][c] = 0;

                for (int i = 0; i < eachElemLoopCount; ++i) {
                    ref += mat[r][i] * other.mat[i][c];
                    if (ref >= MOD) ref %= MOD;
                }
            }
        }

        return prod;
    }

    Matrix expo(int pw) const {
        int dim = getRowCount(); // Must be a square matrix
        Matrix res(dim, dim);

        if (pw == 1) {
            res.mat = mat;
            return res;
        }

        if (pw & 1) {
            Matrix tmp = expo(pw - 1);
            res = multiply(tmp);
        }
        else {
            Matrix tmp = expo(pw >> 1);
            res = tmp.multiply(tmp);
        }

        return res;
    }

    void print() const {
        for (auto &vec : mat) {
            for (auto &x : vec) {
                printf(" %d", x);
            }
            printf("\n");
        }
    }
};


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, r;
        scanf("%d %d", &n, &r);

        Matrix columnMatrix(n, 1);

        for (int i = 0; i < n; ++i) {
            LL val;
            scanf("%lld", &val);
            columnMatrix.mat[i][0] = val % MOD;
        }

        Matrix matrix(n, n);

        for(int line = 0; line < n; ++line) {
            int x, b;
            scanf("%d", &x);

            while(x--) {
                scanf("%d", &b);
                matrix.mat[line][b] = 1;
            }
        }

        Matrix expoRes = matrix.expo(r);
        
        Matrix res = expoRes.multiply(columnMatrix);

        for (int i = 0; i < n; ++i) {
            if (i > 0) printf(" ");
            printf("%d", res.mat[i][0]);
        }
        printf("\n");
    }

    return 0;
}
