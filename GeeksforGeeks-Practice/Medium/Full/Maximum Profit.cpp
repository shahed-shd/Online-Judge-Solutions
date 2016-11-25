// ==================================================
// Problem  :   Maximum Profit
// Run time :   0.077 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int k, n, tmp;
        scanf("%d %d", &k, &n);

        vector<int> V;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            V.push_back(tmp);
        }

        vector<vector<int> > memo(k+3, vector<int>(n+3, 0));

        int mx = 0;

        for(int i = n-1; i >= 0; --i) {
            for(int j = i+1; j < n; ++j) {
                int profit = V[j] - V[i];

                for(int tr = 1; tr <= k; ++tr)
                    memo[tr][i] = max(max(memo[tr][i], profit+memo[tr-1][j+1]), memo[tr][i+1]);
            }
        }

        for(int i = 0; i <= k; ++i)
            mx = max(mx, memo[i][0]);

        printf("%d\n", mx);
    }

    return 0;
}
