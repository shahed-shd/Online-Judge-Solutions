// ==================================================
// Problem  :   1231C - Increasing Matrix
// Run time :   0.078 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;


const int MAXN = 500 + 3;


int mat[MAXN][MAXN];


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    int ans = 0;

    for(int i = n; i > 0 and ans != -1; --i) {
        for(int j = m; j > 0; --j) {
            if(mat[i][j] == 0) {
                mat[i][j] = min(mat[i+1][j], mat[i][j+1]) - 1;      // As per problem statement, here (i < n and j < m).

                if(mat[i][j] == 0) {                                // It is necessary to replace each value of 0 with some positive integer.
                    ans = -1;
                    break;
                }
            } else {
                if((i < n and  mat[i][j] >= mat[i+1][j]) or (j < m and mat[i][j] >= mat[i][j+1])) {     // That is, non-increasing.
                    ans = -1;
                    break;
                }
            }

            ans += mat[i][j];
        }
    }

    printf("%d\n", ans);

    return 0;
}
