#include <iostream>
#include <cstring>
using namespace std;

int n, m;

void find_square_for(int sqrHand, bool **H, bool **V, int cnt[])
{
    for(int i = 0; i < n-sqrHand; ++i) {
        for(int j = 0; j < n-sqrHand; ++j) {
            int lines = 0;

            if( H[i][j] ) {
                ++lines;
                for(int k = 1; k < sqrHand; ++k) if( H[i][j+k] ) ++lines;
            }
            else continue;

            if( H[i+sqrHand][j] ) {
                ++lines;
                for(int k = 1; k < sqrHand; ++k) if( H[i+sqrHand][j+k] ) ++lines;
            }
            else continue;

            if( V[j][i] ) {
                ++lines;
                for(int k = 1; k < sqrHand; ++k) if( V[j][i+k] ) ++lines;
            }
            else continue;

            if(V[j+sqrHand][i]) {
                ++lines;
                for(int k = 1; k < sqrHand; ++k) if( V[j+sqrHand][i+k] ) ++lines;
            }
            else continue;

            if(lines == 4 * sqrHand) ++cnt[sqrHand-1];
        }
    }
}

int main()
{
    int i, j, tc;
    char ch;
    bool output_separator = false;

    tc = 0;

    while(cin >> n >> m) {
        bool *H[n], *V[n];

        for(int k = 0; k < n; ++k) H[k] = new bool [n];
        for(int k = 0; k < n; ++k) V[k] = new bool [n];

        int cnt[n];

        memset(cnt, 0, sizeof(cnt));

        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < n; ++c) {
                H[r][c] = V[r][c] = false;
            }
        }

        while(m--) {
            cin >> ch >> i >> j;

            if(ch == 'H') H[i-1][j-1] = true;
            else if(ch == 'V') V[i-1][j-1] = true;
        }

        for(int sqrHand = 1; sqrHand <= n; ++sqrHand) {
            find_square_for(sqrHand, H, V, cnt);
        }

        if(output_separator) cout << "\n**********************************\n\n";
        output_separator = true;

        cout << "Problem #" << ++tc << "\n\n";

        bool noSqrFound = true;
        for(int k = 0; k < n; ++k) {
            if(cnt[k]) {
                cout << cnt[k] << " square (s) of size " << k+1 << '\n';
                noSqrFound = false;
            }
        }

        if(noSqrFound) cout << "No completed squares can be found.\n";

        for(int k = 0; k < n; ++k) {
            delete [] H[k];
            delete [] V[k];
        }
    }

    return 0;
}

