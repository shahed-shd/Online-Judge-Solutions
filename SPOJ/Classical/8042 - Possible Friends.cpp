#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    cin.ignore(1, '\n');

    while(tc--) {
        string str;
        getline(cin, str);

        int m = str.length();
        bool matrix[m][m];

        memset(matrix, false, sizeof(matrix));

        for(int i = 0; i < m; ++i) {
            if(str[i] == 'Y') matrix[0][i] = true;
        }

        char ch;
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> ch;
                if(ch == 'Y') matrix[i][j] = true;
            }
        }
        if(m > 1) cin.ignore(1, '\n');

        // input complete.

        bool temp[m][m];
        int frndCount[m];

        memset(temp, false, sizeof(temp));
        memset(frndCount, 0, sizeof(frndCount));

        for(int k = 0; k < m; ++k) {
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(matrix[i][k] && matrix[k][j] && !matrix[i][j] && i != j && !temp[i][j]) {
                        temp[i][j] = temp[j][i] = true;
                        ++frndCount[i];
                        ++frndCount[j];
                    }
                }
            }
        }

        // Now, observing max possible friends.

        int id, mx = INT_MIN;

        for(int i = 0; i < m; ++i) {
            if(frndCount[i] > mx) {
                id = i;
                mx = frndCount[i];
            }
        }

        cout << id << ' ' << mx << '\n';
    }

    return 0;
}
