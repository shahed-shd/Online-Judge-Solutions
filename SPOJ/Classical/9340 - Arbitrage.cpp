// ==================================================
// Problem  :   9340 - Arbitrage
// Run time :   0.010 sec.
// Language :   C++11
// ==================================================

#include <iostream>
#include <unordered_map>
using namespace std;

const int MAXN = 30 + 3;

unordered_map<string, int> mp;
double mat[MAXN][MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);

    int n, tc = 0;

    while(cin >> n, n) {
        mp.clear();

        string ci, cj;
        double r;

        for(int i = 0; i < n; ++i) {
            cin >> ci;
            mp[ci] = i;
        }

        fill(&mat[0][0], &mat[MAXN][0], 0);
        for(int i = 0; i < n; ++i) mat[i][i] = 1;

        int m;
        cin >> m;

        while(m--) {
            cin >> ci >> r >> cj;
            mat[mp[ci]][mp[cj]] = r;
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    double exchangeRate = mat[i][k] * mat[k][j];

                    if(exchangeRate > mat[i][j])
                        mat[i][j] = exchangeRate;
                }
            }
        }

        bool ans = false;

        for(int i = 0; i < n && !ans; ++i)
            if(mat[i][i] > 1)
                ans = true;

        cout << "Case " << ++tc << ": " << ((ans)? "Yes\n" : "No\n");
    }

    return 0;
}
