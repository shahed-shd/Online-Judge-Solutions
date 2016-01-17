// Run time: 0.000 s

#include <cstdio>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int m, n;

    while(scanf("%d %d", &m, &n), m || n) {
        int matrix[m][n];

        int tmp;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            matrix[0][i] = !tmp;
        }

        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &tmp);
                tmp = !tmp;
                matrix[i][j] = tmp;
                if(tmp) matrix[i][j] += matrix[i-1][j];
            }
        }

        int mx = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j]) {
                    int sum = tmp = matrix[i][j];

                    int j1 = j;
                    while(++j1 < n && matrix[i][j1] >= tmp)
                        sum += tmp;

                    j1 = j;
                    while(--j1 >= 0 && matrix[i][j1] >= tmp)
                        sum += tmp;

                    if(sum > mx) mx = sum;
                }
            }
        }

        printf("%d\n", mx);

    }

    return 0;
}


// ------------------------- Alternatively -------------------------
// Run time: 0.049 s

/*
#include <cstdio>
#include <bitset>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int m, n;

    while(scanf("%d %d", &m, &n), m || n) {
        bitset<105> inputMatrix[m];
        int matrix[m][n];

        int tmp;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &tmp);

                inputMatrix[i][j] = tmp;

                if(i) tmp += matrix[i-1][j];
                if(j) tmp += matrix[i][j-1];
                if(i && j) tmp -= matrix[i-1][j-1];
                matrix[i][j] = tmp;
            }
        }

        int mx = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(inputMatrix[i][j]) continue;

                for(int x = i; x < m; ++x) {
                    for(int y = j; y < n; ++y) {
                        if(inputMatrix[i][j]) continue;

                        tmp = matrix[x][y];
                        if(i) tmp -= matrix[i-1][y];
                        if(j) tmp -= matrix[x][j-1];
                        if(i && j) tmp += matrix[i-1][j-1];

                        if(!tmp && (x-i+1)*(y-j+1) > mx)
                            mx = (x-i+1)*(y-j+1);
                    }
                }
            }
        }

        printf("%d\n", mx);
    }

    return 0;
}
*/
