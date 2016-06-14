#include <cstdio>
using namespace std;

const int MAXN = 15;

int main()
{
    int n;
    bool newline = false;

    while(scanf("%d", &n) != EOF) {
        if(newline) putchar('\n');
        newline = true;

        printf("n=%d, sum=%d\n", n, n * (n*n + 1)/2);

        int mat[MAXN][MAXN] = {{0}};

        int i = 0, j = n/2, i1, j1, upto = n*n;

        for(int num = 1; num <= upto; ++num) {
            mat[i][j] = num;

            i1 = (i-1 < 0)? n-1 : i-1;
            j1 = (j+1 == n)? 0 : j+1;

            if(mat[i1][j1]) {
                i1 = i+1;
                j1 = j;
            }

            i = i1;
            j = j1;
        }

        if(upto < 10) {
            for(i = 0; i < n; ++i, putchar('\n'))
                for(j = 0; j < n; ++j)
                    printf("%2d", mat[i][j]);
        }
        else if(upto < 100) {
            for(i = 0; i < n; ++i, putchar('\n'))
                for(j = 0; j < n; ++j)
                    printf("%3d", mat[i][j]);
        }
        else {
            for(i = 0; i < n; ++i, putchar('\n'))
                for(j = 0; j < n; ++j)
                    printf("%4d", mat[i][j]);
        }
    }

    return 0;
}
