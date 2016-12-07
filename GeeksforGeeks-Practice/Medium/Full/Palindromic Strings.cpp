// ==================================================
// Problem  :   Palindromic Strings
// Run time :   0.077 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 3;

char str[MAXN];

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, k;
        scanf("%d %d %s", &n, &k, str);

        int memo[n+3][n+3];
        for(int i = 0; i <= n; ++i) memo[n][i] = memo[i][n] = 0;

        for(int i = n-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                if(str[i] == str[n-j-1])
                    memo[i][j] = 1 + memo[i+1][j+1];
                else
                    memo[i][j] = max(memo[i][j+1], memo[i+1][j]);
            }
        }

        int lcs = memo[0][0];

        int minInsertion = n - lcs;

        puts((k >= minInsertion)? "YES" : "NO");
    }

    return 0;
}
