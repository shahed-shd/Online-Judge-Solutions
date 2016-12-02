// ==================================================
// Problem  :   Longest Common Substring
// Run time :   0.078 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 3;

int memo[MAXN][MAXN];

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int a, b;
        char strX[MAXN], strY[MAXN];

        scanf("%d %d %s %s", &a, &b, strX, strY);

        int ans = 0;

        for(int i = 0; i < a; ++i) {
            for(int j = 0; j < b; ++j) {
                if(strX[i] == strY[j]) {
                    memo[i][j] = 1 + ((i && j)? memo[i-1][j-1] : 0);
                    ans = max(ans, memo[i][j]);
                }
                else memo[i][j] = 0;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
