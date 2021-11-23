// ==================================================
// Problem  :   1607F - Robot on the Board 2
// Run time :   0.795 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <deque>
#include <bitset>
#include <vector>
#include <utility>
using namespace std;


typedef     pair<int, int>      ii;

const int MAXN = 2e3 + 3;

char board[MAXN][MAXN];


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; ++i) {
            scanf("%s", board[i]);
        }

        vector<vector<int>> distances(n, vector<int>(m, -1));
        vector<bitset<MAXN>> isInQueue(n, bitset<MAXN>());
        int maxDist = -1, startRow, startCol;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (distances[i][j] == -1) {
                    int r = i, c = j;
                    deque<ii> q;

                    bool isInBoard;

                    do {
                        q.push_back(ii(r, c));
                        isInQueue[r][c] = true;

                        char cmd = board[r][c];

                        if (cmd == 'L') {
                            --c;
                        }
                        else if (cmd == 'R') {
                            ++c;
                        }
                        else if (cmd == 'D') {
                            ++r;
                        }
                        else {
                            --r;
                        }

                        isInBoard = 0 <= r && r < n && 0 <= c && c < m;
                    } while (isInBoard && !isInQueue[r][c] && distances[r][c] == -1);

                    int dist = q.size();

                    if (isInBoard && distances[r][c] != -1) {
                        dist += distances[r][c];
                    }

                    if (dist > maxDist) {
                        maxDist = dist;
                        startRow = q.front().first;
                        startCol = q.front().second;
                    }

                    bool isInLoop = false;

                    while (!q.empty()) {
                        ii front = q.front();
                        q.pop_front();
                        int row = front.first, col = front.second;

                        if (row == r && col == c) {
                            isInLoop = true;
                        }

                        isInQueue[row][col] = false;
                        distances[row][col] = dist;

                        if (!isInLoop) {
                            --dist;
                        }
                    }
                }
            }
        }

        printf("%d %d %d\n", startRow + 1, startCol + 1, maxDist);
    }

    return 0;
}
