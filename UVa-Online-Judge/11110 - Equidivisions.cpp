// ==================================================
// Problem  :   11110 - Equidivisions
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


const int MAXN = 100 + 3;

const int dr[] = {0, 0, -1, 1};
const int dc[] = {1, -1, 0, 0};

int n, grid[MAXN][MAXN];


int flood_fill(int r, int c)
{
    int ret = 1;
    int val = grid[r][c];
    grid[r][c] = -1;

    for(int i = 0; i < 4; ++i) {
        int rr = r + dr[i], cc = c + dc[i];

        if(1 <= rr and rr <= n and 1 <= cc and cc <= n and grid[rr][cc] == val)
            ret += flood_fill(rr, cc);
    }

    return ret;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    ios::sync_with_stdio(false);

    while(cin >> n, n) {
        cin.ignore(100, '\n');

        for(int i = 1; i <= n; ++i)
            fill(&grid[i][1], &grid[i][n+1], n);

        int r, c;
        bool ans = true;

        for(int i = 1; i < n; ++i) {
            string s;
            getline(cin, s);

            stringstream ss(s);

            while(ss >> r >> c)
                grid[r][c] = i;
        }

        for(int i = 1; i <= n and ans; ++i) {
            for(int j = 1; j <= n and ans; ++j) {
                if(grid[i][j] != -1) {
                    int cnt = flood_fill(i, j);

                    if(cnt != n) {
                        ans = false;
                    }
                }
            }
        }

        cout << (ans ? "good\n" : "wrong\n");
    }

    return 0;
}
