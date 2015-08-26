#include <iostream>
#include <queue>
using namespace std;

void bfs(short r1, short c1, short r2, short c2)
{
    queue<pair<short, short> > q;
    pair<short, short> u;

    bool board[8][8] = {0};
    short level[8][8] = {0};

    short fx[] = {-2, -2, -1, 1, 2, 2, -1, 1};
    short fy[] = {-1, 1, 2, 2, 1, -1, -2, -2};

    q.push(make_pair(r1, c1));
    board[r1][c1] = true;
    level[r1][c1] = 0;

    short x, y;

    while(!q.empty()) {
        u = q.front();

        for(short i = 0; i < 8; ++i) {
            x = u.first + fx[i];
            y = u.second + fy[i];

            if(0 <= x && x < 8 && 0 <= y && y < 8 && board[x][y] == false) {
                board[x][y] = true;
                level[x][y] = level[u.first][u.second] + 1;
                q.push(make_pair(x, y));
            }

            if(x == r2 && y == c2) {
                cout << "To get from " << char(c1+'a') << r1+1 << " to " << char(c2+'a') << r2+1 << " takes " << level[r2][c2] << " knight moves.\n";
                return;
            }
        }

        q.pop();
    }
}

int main()
{
    char ch1, ch2;
    short r1, r2;

    while(cin >> ch1 >> r1 >> ch2 >> r2) {
        bfs(r1-1, ch1 - 'a', r2-1, ch2 - 'a');
    }

    return 0;
}
