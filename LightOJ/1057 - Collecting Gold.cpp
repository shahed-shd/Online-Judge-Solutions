#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

typedef     pair<int,int>   ii;
typedef     pair<ii,ii>     iiii;

const int MAXN = 20, MAXG = 15;

const int dr[] = {0, 0, -1, 1, -1, 1, -1, 1};
const int dc[] = {-1, 1, 0, 0, -1, 1, 1, -1};

int r, c, goldCnt, start_r, start_c;
vector<ii> goldPos;
map<iiii, int> distMemo;
int memo[1<<MAXG][MAXG];

inline bool bitcheck(int n, int pos) { return (n>>pos) & 1; }
inline int biton(int n, int pos) { return n | (1<<pos); }

int bfs(int sr, int sc, int tr, int tc)
{
    int ret = distMemo[iiii(ii(sr, sc), ii(tr, tc))];
    if(ret) return ret;

    queue<ii> q;
    int level[r][c];
    fill(&level[0][0], &level[r][0], -1);

    q.push(ii(sr, sc));
    level[sr][sc] = 0;

    while(!q.empty()) {
        ii u = q.front(); q.pop();

        if(u.first == tr && u.second == tc) {
            ret = level[tr][tc];

            distMemo[iiii(ii(sr, sc), ii(tr, tc))] = ret;
            distMemo[iiii(ii(tr, tc), ii(sr, sc))] = ret;

            return ret;
        }

        for(int i = 0; i < 8; ++i) {
            int vr = u.first+dr[i], vc = u.second+dc[i];

            if(0 <= vr && vr < r && 0 <= vc && vc < c && level[vr][vc] == -1) {
                level[vr][vc] = level[u.first][u.second] + 1;
                q.push(ii(vr, vc));
            }
        }
    }

    return 0;   // Just to avoid warning while compiling.
}

int fn(int mask, int idx)
{
    if(mask == (1<<goldCnt)-1)
        return bfs(goldPos[idx].first, goldPos[idx].second, start_r, start_c);

    int& ret = memo[mask][idx];
    if(ret != -1) return ret;

    ret = INT_MAX;

    for(int i = 0; i < goldCnt; ++i)
        if(!bitcheck(mask, i))
            ret = min(ret, bfs(goldPos[idx].first, goldPos[idx].second, goldPos[i].first, goldPos[i].second) + fn(biton(mask, i), i));

    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        goldPos.clear();
        distMemo.clear();
        fill(&memo[0][0], &memo[1<<MAXG][0], -1);

        scanf("%d %d", &r, &c);

        char str[MAXN+5];

        for(int i = 0; i < r; ++i) {
            scanf("%s", str);

            for(int j = 0; str[j]; ++j) {
                if(str[j] == 'g')
                    goldPos.push_back(ii(i, j));
                else if(str[j] == 'x')
                    start_r = i, start_c = j;
            }
        }

        goldCnt = goldPos.size();

        int ans = ((goldCnt)? INT_MAX : 0);

        for(int i = 0; i < goldCnt; ++i)
            ans = min(ans, bfs(start_r, start_c, goldPos[i].first, goldPos[i].second) + fn(biton(0, i), i));

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
