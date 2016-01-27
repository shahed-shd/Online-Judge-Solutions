#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

const int MAXN = 200+5;

const short dr[] = {-1, -1, 0, 0, 1, 1};
const short dc[] = {-1, 0, -1, 1, 0, 1};

vector<string> board;
vector<bitset<MAXN> > visited;
int n;
bool isW;

void dfs(int row, int col)
{
    if(isW || row < 0 || row >= n || col < 0 || col >= n) return;
    if(board[row][col] != 'w' || visited[row][col]) return;
    if(col == n-1) {
        isW = true;
        return;
    }

    visited[row][col] = true;

    for(int i = 0; i < 6; ++i)
        dfs(row+dr[i], col+dc[i]);
}

int main()
{
    ios::sync_with_stdio(false);

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int tc = 0;

    while(cin >> n, n) {
        board.clear();
        visited.clear();

        board.resize(n);

        for(auto& s : board) cin >> s;

        visited.resize(n);
        isW = false;

        for(int i = 0; i < n; ++i)
            if(board[i][0] == 'w' && !visited[i][0])
                dfs(i, 0);

        cout << ++tc << ((isW)? " W\n" : " B\n");   // This game cannot end in a draw (that is, without winner).
    }

    return 0;
}
