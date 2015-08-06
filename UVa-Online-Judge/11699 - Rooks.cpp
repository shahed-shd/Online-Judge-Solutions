#include <iostream>
using namespace std;

char board[15][15];

int solve(int mask)
{
    char temp[15][15];
    copy(&board[0][0], &board[14][15], &temp[0][0]);

    int cnt = 0;

    for(int i = 0; i < 15; ++i) {
        if(mask & (1 << i)) {
            ++cnt;
            for(int row = 0; row < 15; ++row) temp[row][i] = '.';
        }
    }

    int ex = 0;

    for(int i = 0; i < 15; ++i) {
        for(int j = 0; j < 15; ++j) {
            if(temp[i][j] == '#') {
                ++ex;
                break;
            }
        }
    }

    return (ex <= cnt)? cnt : (1 << 17);
}

int main()
{
    while(cin >> board[0], string(board[0]) != "END") {
        for(int i = 1; i < 15; ++i) cin >> board[i];

        int ans = 1 << 17;

        for(int i = 0; i < (1 << 16); ++i) {
            ans = min(ans, solve(i));
        }

        cout << ans << '\n';
    }

    return 0;
}
