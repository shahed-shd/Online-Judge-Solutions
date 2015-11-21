#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define     dp(i,j)         (*(dp+2*i+j))
#define     dpCount(i,j)    (*(dpCount+2*i+j))

vector<vector<int> > adjList;
vector<bool> visited;
int *dp, *dpCount;

int f(int u, bool isTaken, int parent, int &cnt)
{
    visited[u] = true;

    if(adjList[u].size() == 0) { cnt = 0; return 0; }

    if(dp(u, isTaken) != -1) { cnt = dpCount(u, isTaken); return dp(u, isTaken); }

    int sum = 0, withNode, withoutNode, withNodeCnt, withoutNodeCnt, v, sz = adjList[u].size();
    cnt = 0;

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(v != parent) {
            if(!isTaken) {
                sum += f(v, true, u, withNodeCnt);
                cnt += withNodeCnt;
            }
            else {
                withNode = f(v, true, u, withNodeCnt);
                withoutNode = f(v, false, u, withoutNodeCnt);

                if(withNode < withoutNode) {
                    sum += withNode;
                    cnt += withNodeCnt + 1;
                }
                else if(withNode > withoutNode) {
                    sum += withoutNode;
                    cnt += withoutNodeCnt;
                }
                else {      // withNode == withoutNode
                    sum += withNode;
                    cnt += max(withNodeCnt+1, withoutNodeCnt);
                }
            }
        }
    }

    dpCount(u, isTaken) = cnt;
    return dp(u, isTaken) = sum + isTaken;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        visited.clear();

        int n, m, u, v;
        scanf("%d %d", &n, &m);

        dp = new int [n*2];
        dpCount = new int [n*2];
        fill(dp, dp+n*2, -1);
        adjList.resize(n);
        visited.assign(n, false);

        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int ans = 0, cnt = 0;

        for(int root = 0; root < n; ++root) {
            if(!visited[root]) {
                int withNode, withoutNode, withNodeCnt, withoutNodeCnt;

                withNode = f(root, true, -1, withNodeCnt);
                withoutNode = f(root, false, -1, withoutNodeCnt);

                if(withNode < withoutNode) {
                    ans += withNode;
                    cnt += withNodeCnt;
                }
                else if(withNode > withoutNode) {
                    ans += withoutNode;
                    cnt += withoutNodeCnt;
                }
                else {
                    ans += withNode;
                    cnt += max(withNodeCnt, withoutNodeCnt);
                }
            }
        }

        printf("Case %d: %d %d %d\n", tc, ans, cnt, m-cnt);

        delete [] dp;
        delete [] dpCount;
    }

    return 0;
}
