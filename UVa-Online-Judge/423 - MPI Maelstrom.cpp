#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

typedef long long LL;

int main()
{
    ios::sync_with_stdio(false);

    int n;

    while(cin >> n) {
        int matrix[n][n];

        for(int i = 0; i < n; ++i) matrix[i][i] = 0;

        string str;
        int temp;

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                cin >> str;

                if('0' <= str[0] && str[0] <= '9') {
                    temp = atoi(str.c_str());
                    matrix[i][j] = matrix[j][i] = temp;
                }
                else matrix[i][j] = matrix[j][i] = INT_MAX;
            }
        }

        for(int k = 0; k < n; ++k)          // Floyd-Warshall algorithm.
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(matrix[i][j] > LL(matrix[i][k]) + LL(matrix[k][j]))
                        matrix[i][j] = LL(matrix[i][k]) + LL(matrix[k][j]);

        temp = INT_MIN;

        for(int i = 0; i < n; ++i)
            if(matrix[0][i] != INT_MAX)
                temp = max(temp, matrix[0][i]);

        cout << temp << '\n';
    }

    return 0;
}
