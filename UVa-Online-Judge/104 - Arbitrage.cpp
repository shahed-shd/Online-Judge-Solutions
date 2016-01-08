#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int n;

    while(scanf("%d", &n) != EOF) {
        double table[n][n][n];
        short next[n][n][n];

        fill_n(&table[0][0][0], n*n*n, 0);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                (i == j)? table[i][j][0] = 1 : scanf("%lf", &table[i][j][0]);
                next[i][j][0] = j;
            }
        }

        double tmp;

        for(int step = 1; step < n; ++step) {
            for(int k = 0; k < n; ++k) {
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < n; ++j) {
                        tmp = table[i][k][step-1] * table[k][j][0];

                        if(tmp > table[i][j][step]) {
                            table[i][j][step] = tmp;
                            next[i][j][step] = next[i][k][step-1];
                        }
                    }
                }
            }
        }

        bool isFound = false;

        for(int step = 1; step < n; ++step) {
            for(int i = 0; i < n; ++i) {
                if(table[i][i][step] > 1.01) {
                    printf("%d", i+1);

                    int tmp = i, cnt = step;

                    while(cnt--) {
                        tmp = next[tmp][i][step];
                        printf(" %d", tmp+1);
                    }

                    printf(" %d\n", i+1);

                    isFound = true;
                    break;
                }
            }
            if(isFound) break;
        }

        if(!isFound) printf("no arbitrage sequence exists\n");
    }

    return 0;
}
