#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);

        int n2 = n+n, table[160][160] = {0};

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%d", &table[i][j]);
                table[i+n][j+n] = table[i][j+n] = table[i+n][j] = table[i][j];
            }
        }

        for(int i = 1; i <= n2; ++i)
            for(int j = 1; j <= n2; ++j)
                table[i][j] += table[i-1][j] + table[i][j-1] - table[i-1][j-1];

        int mx = INT_MIN;

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                for(int x = i; x < i+n; ++x)
                    for(int y = j; y < j+n; ++y)
                        mx = max(mx, table[x][y] - table[i-1][y] - table[x][j-1] + table[i-1][j-1]);

        printf("%d\n", mx);
    }

    return 0;
}
