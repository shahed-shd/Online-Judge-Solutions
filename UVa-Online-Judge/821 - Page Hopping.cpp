#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
using namespace std;

typedef long long LL;

int main()
{
    int u, v, tc = 0;

    cout.precision(3);
    fixed(cout);

    while(cin >> u >> v, u != 0 || v != 0) {
        map<int, int> mp;
        vector<int> pairs;

        pairs.push_back(u);
        mp[u];
        pairs.push_back(v);
        mp[v];

        while(cin >> u >> v, u != 0 || v != 0) {
            pairs.push_back(u);
            mp[u];
            pairs.push_back(v);
            mp[v];
        }

        int m = mp.size();
        int idx = 0;
        for(auto& pr : mp) pr.second = idx++;

        int matrix[m][m];
        fill(&matrix[0][0], &matrix[m][0], INT_MAX);
        for(int i = 0; i < m; ++i) matrix[i][i] = 0;

        int sz = pairs.size();
        idx = 0;

        while(idx < sz) {
            u = pairs[idx++];
            v = pairs[idx++];

            matrix[mp[u]][mp[v]] = 1;
        }

        // input complete.

        for(int k = 0; k < m; ++k)          // Floyd-Warshall algorithm.
            for(int i = 0; i < m; ++i)
                for(int j = 0; j < m; ++j)
                    if(matrix[i][j] > LL(matrix[i][k]) + LL(matrix[k][j]))
                        matrix[i][j] = matrix[i][k] + matrix[k][j];

        double sum = 0;
        for_each(&matrix[0][0], &matrix[m][0], [&sum](int x){ sum += x; });

        cout << "Case " << ++tc << ": average length between pages = " << sum / (m*(m-1)) << " clicks\n";
    }

    return 0;
}
