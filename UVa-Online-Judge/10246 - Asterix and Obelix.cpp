#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long LL;

int main()
{
    ios::sync_with_stdio(false);

    int c, r, q, tc = 0;
    bool newline = false;

    while(cin >> c >> r >> q, c != 0 || r != 0 || q != 0) {
        int feast[c];
        for(int i = 0; i < c; ++i) cin >> feast[i];

        int feastMat[c][c];

        for(int i = 0; i < c; ++i)
            for(int j = 0; j < c; ++j)
                feastMat[i][j] = max(feast[i], feast[j]);

        LL matrix[c][c];

        fill(&matrix[0][0], &matrix[c][0], INT_MAX);
        for(int i = 0; i < c; ++i) matrix[i][i] = 0;

        int u, v, cost;

        while(r--) {
            cin >> u >> v >> cost;
            --u, --v;
            matrix[u][v] = cost;
            matrix[v][u] = cost;
        }

        int times = 2;  // to run Floyd-Warshall algorithm twice,  because of the interaction of the max feast costs.

        while(times--) {
            for(int k = 0; k < c; ++k) {        // Floyd-Warshall algorithm.
                for(int i = 0; i < c; ++i) {
                    for(int j = 0; j < c; ++j) {
                        if(matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX && matrix[i][j] + feastMat[i][j] > matrix[i][k] + matrix[k][j] + max(feastMat[i][k], feastMat[k][j])) {
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
                            feastMat[i][j] = max(feastMat[i][k], feastMat[k][j]);
                        }
                    }
                }
            }
        }

        if(newline) cout << '\n';
        newline = true;

        cout << "Case #" << ++tc << '\n';
        while(q--) {
            cin >> u >> v;
            --u, --v;
            if(matrix[u][v] == INT_MAX) cout << "-1\n";
            else cout << matrix[u][v] + feastMat[u][v] << '\n';
        }
    }

    return 0;
}
