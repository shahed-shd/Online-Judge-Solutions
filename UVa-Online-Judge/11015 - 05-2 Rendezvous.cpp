#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

typedef long long LL;

int main()
{
    int n, m, tc = 0;

    while(cin >> n, n != 0) {
        cin >> m;

        vector<string> names;
        string str;

        for(int i = 0; i < n; ++i) {
            cin >> str;
            names.push_back(str);
        }

        int u, v, cost, matrix[n][n];

        fill(&matrix[0][0], &matrix[n][0], INT_MAX);
        for(int i = 0; i < n; ++i) matrix[i][i] = 0;

        while(m--) {
            cin >> u >> v >> cost;
            --u, --v;
            matrix[u][v] = cost;
            matrix[v][u] = cost;
        }

        // input complete.

        for(int k = 0; k < n; ++k)          // Floyd-Warshall algorithm.
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(matrix[i][j] > LL(matrix[i][k]) + LL(matrix[k][j]))
                        matrix[i][j] = matrix[i][k] + matrix[k][j];

        int minCost = INT_MAX, id;

        for(int i = 0; i < n; ++i) {
            LL sum = 0;
            for_each(&matrix[i][0], &matrix[i][n], [&sum](int x){ sum += x; });

            if(sum < minCost) minCost = sum, id = i;
        }

        cout << "Case #" << ++tc << " : " << names[id] << '\n';
    }

    return 0;
}
