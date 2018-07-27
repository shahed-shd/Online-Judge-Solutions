// ==================================================
// Problem  :   11643 - Knight Tour
// Run time :   0.170 sec
// Language :   C++11
// ==================================================


#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;


typedef     pair<int,int>       ii;


const int INF = INT_MAX;
const int MAXN = 1e3 + 3;
const int MAXK = 16 + 3;

const int dr[] = {2, 2, -2, -2, 1, -1, 1, -1};
const int dc[] = {1, -1, 1, -1, 2, 2, -2, -2};


int dist_pre[MAXN][MAXN];
int dist_tmp[MAXN][MAXN], curr_case[MAXN][MAXN] = {0};
int dist[MAXK][MAXK];
vector<ii> interesting_points;
int memo[1 << MAXK][MAXK];
int n, k;


inline bool bitcheck(int n, int pos) { return n & (1 << pos); }
inline int biton(int n, int pos) { return n | (1 << pos); }


void bfs_pre()   // Preprocess the distances.
{
    fill(&dist_pre[0][0], &dist_pre[MAXN][0], -1);

    queue<ii> q;
    q.push(ii(0, 0));
    dist_pre[0][0] = 0;

    while(!q.empty()) {
        int ur = q.front().first;
        int uc = q.front().second;
        q.pop();

        for(int i = 0; i < 8; ++i) {
            int vr = ur + dr[i], vc = uc + dc[i];

            if(0 <= vr and vr < MAXN and 0 <= vc and vc < MAXN and dist_pre[vr][vc] == -1) {
                dist_pre[vr][vc] = dist_pre[ur][uc] + 1;
                q.push(ii(vr, vc));
            }
        }
    }
}


int bfs(int sr, int sc, int tr, int tc)
{
    static int curr = 0;
    ++curr;

    queue<ii> q;
    q.push(ii(sr, sc));
    dist_tmp[sr][sc] = 0;
    curr_case[sr][sc] = curr;

    while(!q.empty()) {
        int ur = q.front().first;
        int uc = q.front().second;
        q.pop();

        if(dist_tmp[ur][uc] > 30) break;

        for(int i = 0; i < 8; ++i) {
            int vr = ur + dr[i], vc = uc + dc[i];

            if(0 <= vr and vr < n and 0 <= vc and vc < n and curr_case[vr][vc] != curr) {
                curr_case[vr][vc] = curr;
                dist_tmp[vr][vc] = dist_tmp[ur][uc] + 1;

                if(vr == tr and vc == tc)
                    return dist_tmp[vr][vc];

                q.push(ii(vr, vc));
            }
        }
    }

    return INF;
}


int dp(int mask, int last)
{
    if(mask == ((1 << k) - 1)) {
        return dist[last][0];
    }

    int &ret = memo[mask][last];
    if(ret != -1) return ret;

    ret = INF;

    for(int i = 0; i < k; ++i) {
        if(!bitcheck(mask, i)) {
            ret = min(ret, dist[last][i] + dp(biton(mask, i), i));
        }
    }

    return ret;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    bfs_pre();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        interesting_points.clear();

        scanf("%d %d", &n, &k);

        int a, b;

        for(int i = 0; i < k; ++i) {
            scanf("%d %d", &a, &b);
            interesting_points.push_back(ii(a-1, b-1));
        }

        for(int i = 0; i < k; ++i) {
            for(int j = 0; j < i; ++j) {
                ii &x = interesting_points[i], &y = interesting_points[j];
                int row_diff = abs(x.first - y.first);
                int col_diff = abs(x.second - y.second);

                if(row_diff + row_diff < 20) {
                    int b = bfs(x.first, x.second, y.first, y.second);
                    dist[i][j] = dist[j][i] = (b != INF)? b : dist_pre[row_diff][col_diff];
                }
                else {
                    dist[i][j] = dist[j][i] = dist_pre[row_diff][col_diff];
                }
            }

            dist[i][i] = 0;
        }

        fill(&memo[0][0], &memo[1 << k][0], -1);

        int ans = dp(biton(0, 0), 0);

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
