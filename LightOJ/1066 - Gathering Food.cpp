#include <cstdio>
#include <bitset>
#include <queue>
#include <utility>
using namespace std;

typedef     pair<int,int>       ii;
typedef     pair<int,ii>        iii;

const int MAXN = 11+3;
const int dr[] = {0, 0, -1, 1};
const int dc[] = {-1, 1, 0, 0};

int n;
char grid[MAXN][MAXN];

int bfs(int sr, int sc, int tr, int tc)
{
    queue<iii> q;
    bitset<MAXN> vis[MAXN];

    q.push(iii(0, ii(sr, sc)));
    vis[sr][sc] = true;

    while(!q.empty()) {
        int w = q.front().first;
        int ur = q.front().second.first;
        int uc = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int vr = ur + dr[i], vc = uc + dc[i];

            if(0 <= vr && vr < n && 0 <= vc && vc < n && !vis[vr][vc]) {
                if(grid[vr][vc] == '.') q.push(iii(w+1, ii(vr, vc))), vis[vr][vc] = true;
                else if(vr == tr && vc == tc) return w+1;
            }
        }
    }

    return -1;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        ii letterPos[26];
        char mxLetter = 'A';

        for(int i = 0; i < n; ++i) {
            scanf("%s", grid[i]);

            for(int j = 0; j < n; ++j) {
                char ch = grid[i][j];
                if('A' <= ch && ch <= 'Z')
                    letterPos[ch - 'A'] = ii(i, j), mxLetter = max(mxLetter, ch);
            }
        }

        printf("Case %d: ", tc);

        mxLetter -= 'A';
        grid[letterPos[0].first][letterPos[0].second] = '.';
        int moveCnt = 0, idx = 0;

        while(idx < mxLetter) {
            int tmp = bfs(letterPos[idx].first, letterPos[idx].second, letterPos[idx+1].first, letterPos[idx+1].second);
            if(tmp == -1) break;

            moveCnt += tmp;
            ++idx;
            grid[letterPos[idx].first][letterPos[idx].second] = '.';
        }

        (idx == mxLetter)? printf("%d\n", moveCnt) : puts("Impossible");
    }

    return 0;
}
