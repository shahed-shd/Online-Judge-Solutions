// ==================================================
// Problem  :   1426 - Blind Escape
// Runtime  :   2.124 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <vector>
using namespace std;

typedef         pair<int,int>       ii;

const int MAXN = 12 + 3;
const int dr[] = {0, -1, 1, 0};
const int dc[] = {1, 0, 0, -1};
const char dchar[] = "ENSW";

int m, n;
char maze[MAXN][MAXN];
ii nextMost[MAXN][MAXN][4];
vector<ii> uPoints, vPoints;
bitset<MAXN> vis[MAXN];

inline bool isInMaze(int r, int c)
{
    return (1 <= r and r <= m and 1 <= c and c <= n);
}

void dfs_getNext_most(int ur, int uc, int d)
{
    if(nextMost[ur][uc][d].first != -1) return;

    int vr = ur + dr[d], vc = uc + dc[d];
    ii &rf = nextMost[ur][uc][d];

    if(!isInMaze(vr, vc)) {
        rf = ii(vr, vc);
    }
    else if(maze[vr][vc] == '#') {
        rf = ii(ur, uc);
    }
    else {
        dfs_getNext_most(vr, vc, d);
        rf = nextMost[vr][vc][d];
    }
}

void preprocess()
{
    fill(&nextMost[0][0][0], &nextMost[MAXN][0][0], ii(-1, -1));

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(maze[i][j] == '.') {
                for(int d = 0; d < 4; ++d)
                    dfs_getNext_most(i, j, d);
            }
        }
    }
}

bool dfs_canGetOut(int r, int c)
{
    if(!isInMaze(r, c)) return true;
    if(vis[r][c]) return false;

    vis[r][c] = true;

    for(int d = 0; d < 4; ++d)
        if(dfs_canGetOut(nextMost[r][c][d].first, nextMost[r][c][d].second))
            return true;

    return false;
}

bool isPossible()
{
    uPoints.clear();

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(maze[i][j] == '.') {
                for(int k = 0; k <= m; ++k) vis[k].reset();
                if(!dfs_canGetOut(i, j)) return false;
                uPoints.push_back(ii(i, j));
            }
        }
    }

    return true;
}

string bfs()
{
    map<vector<ii>, string> mp;
    queue<vector<ii> > q;

    mp[uPoints] = "";
    q.push(uPoints);

    while(!q.empty()) {
        uPoints = q.front(); q.pop();

        if(uPoints.empty()) return mp[uPoints];
        string uStr = mp[uPoints];

        for(int d = 0; d < 4; ++d) {
            vPoints.clear();

            for(vector<ii>::iterator it = uPoints.begin(); it != uPoints.end(); ++it) {
                int r = it->first, c = it->second;
                int rr = nextMost[r][c][d].first, cc = nextMost[r][c][d].second;

                if(isInMaze(rr, cc)) vPoints.push_back(ii(rr, cc));
            }

            sort(vPoints.begin(), vPoints.end());
            vPoints.erase(unique(vPoints.begin(), vPoints.end()), vPoints.end());

            if(mp.find(vPoints) == mp.end()) {
                mp[vPoints] = uStr + dchar[d];
                q.push(vPoints);
            }
        }
    }

    return "";
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &m, &n);

        for(int i = 1; i <= m; ++i)
            scanf("%s", &maze[i][1]);

        printf("Case %d: ", tc);

        preprocess();

        if(isPossible())
            puts(bfs().c_str());
        else
            puts("Impossible");
    }

    return 0;
}
