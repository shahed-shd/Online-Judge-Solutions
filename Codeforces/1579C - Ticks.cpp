// ==================================================
// Problem  :   1579C - Ticks
// Run time :   0.015 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <vector>
using namespace std;


const int MAXN = 10 + 3;
const int MAXM = 19 + 3;

char status[MAXN][MAXM];


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        for(int i = 0; i < n; ++i) {
            scanf("%s", status[i]);
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(status[i][j] == '*') {
                    int d;
                    for(d = 1; i - d >= 0 && j - d >= 0 && j + d < m; ++d) {
                        char leftDiag = status[i - d][j - d];
                        char rightDiag = status[i - d][j + d];

                        bool isTick = (leftDiag == '*' || leftDiag == 't') && (rightDiag == '*' || rightDiag == 't');
                        if(!isTick) break;
                    }
                    --d;

                    if(d >= k) {
                        while(d >= 0) {
                            status[i - d][j - d] = status[i - d][j + d] = 't';
                            --d;
                        }
                    }
                }
            }
        }

        bool ans = true;

        for(int i = 0; i < n && ans; ++i) {
            for(int j = 0; j < m && ans; ++j) {
                if(status[i][j] == '*') ans = false;
            }
        }

        printf(ans? "YES\n" : "NO\n");
    }

    return 0;
}
