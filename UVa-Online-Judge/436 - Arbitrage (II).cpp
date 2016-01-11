#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n, tc = 0;

    while(cin >> n, n) {
        unordered_map<string, int> mp;
        string str;

        for(int i = 0; i < n; ++i) {
            cin >> str;
            mp[str] = i;
        }

        double table[n][n];

        fill_n(&table[0][0], n*n, 0);
        for(int i = 0; i < n; ++i)
            table[i][i] = 1;

        int m;
        double exchangeRate;
        string str2;

        cin >> m;

        while(m--) {
            cin >> str >> exchangeRate >> str2;
            table[mp[str]][mp[str2]] = exchangeRate;
        }

        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    exchangeRate = table[i][k] * table[k][j];

                    if(table[i][j] < exchangeRate)
                        table[i][j] = exchangeRate;
                }
            }
        }

        bool flag = false;

        for(int i = 0; i < n && !flag; ++i)
            if(table[i][i] > 1)
                flag = true;

        cout << "Case " << ++tc << ": ";

        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
