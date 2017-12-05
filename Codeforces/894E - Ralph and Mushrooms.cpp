// ==================================================
// Problem  :   894E - Ralph and Mushrooms
// Run time :   1.075 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
#include <stack>
#include <vector>
using namespace std;


typedef     long long           LL;
typedef     pair<int, int>      ii;


const int MAXN = 1e6 + 3;
const int MAXK = 14141 + 3;

vector<vector<ii> > adjList, adj;
vector<LL> sccCollect, visMemo;
vector<int> sccId;

vector<int> disc, low;
stack<int> stk;
bitset<MAXN> isInStack;
int sccCnt, timeCnt;


void tarjan_scc(int u)
{
    disc[u] = low[u] = ++timeCnt;
    stk.push(u);
    isInStack[u] = true;

    for(auto &pr : adjList[u]) {
        int v = pr.first;

        if(disc[v] == -1) {
            tarjan_scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if(isInStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if(disc[u] == low[u]) {
        int tp;

        do {
            tp = stk.top(); stk.pop();
            isInStack[tp] = false;
            sccId[tp] = sccCnt;
        } while(tp != u);

        ++sccCnt;
    }
}


LL dfs(int u)
{
    if(visMemo[u] != -1) return visMemo[u];

    LL mx = 0;

    for(auto &pr : adj[u]) {
        int v = pr.first, w = pr.second;
        mx = max(mx, w + dfs(v));
    }

    return visMemo[u] = mx + sccCollect[u];
}


int binSearch(int w, int s, int t)
{
    int ret;

    while(s <= t) {
        int mid = (s + t) >> 1;
        int sum = (mid * (mid+1)) >> 1;

        if(sum < w) {
            ret = mid;
            s = mid+1;
        }
        else if(sum > w) {
            t = mid-1;
        }
        else {
            ret = mid;
            break;
        }
    }

    return ret;
}


LL w_to_collection(int w)
{
    LL k = binSearch(w, 0, MAXK);
    return w * (k+1) - (k*k*k + 3*k*k + 2*k) / 6;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    adjList.resize(n+3);
    int u, v, w, s;

    while(m--) {
        scanf("%d %d %d", &u, &v, &w);
        adjList[u].push_back(ii(v, w));
    }

    scanf("%d", &s);

    // SCC

    sccId.assign(n+3, -1);

    disc.assign(n+3, -1);
    low.assign(n+3, -1);
    isInStack.reset();
    sccCnt = 0;
    timeCnt = 0;

    for(int i = 1; i <= n; ++i)
        if(disc[i] == -1)
            tarjan_scc(i);

    // Constructing DAG

    adj.resize(sccCnt+3);
    sccCollect.assign(sccCnt+3, 0);

    for(int u = 1; u <= n; ++u) {
        for(auto &pr : adjList[u]) {
            int uu = sccId[u], vv = sccId[pr.first], w = pr.second;

            if(uu == vv) sccCollect[uu] += w_to_collection(w);
            else adj[uu].push_back(ii(vv, w));
        }
    }

    // Get ans.

    visMemo.assign(sccCnt+3, -1);

    s = sccId[s];

    LL ans = dfs(s);

    printf("%I64d\n", ans);

    return 0;
}


// -------------- Alternatively (Kosaraju’s algorithm for SCC) --------------
// Run time :   1.341 sec.
/*
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;


typedef     long long           LL;
typedef     pair<int, int>      ii;


const int MAXN = 1e6 + 3;
const int MAXK = 14141 + 3;

vector<vector<ii> > adjList, adj;
vector<vector<int> > r_adjList;
vector<LL> sccCollect, visMemo;
vector<int> topoSort, sccId;
bitset<MAXN> vis;


void dfs_topoSort(int u)
{
    vis[u] = true;

    for(auto &pr : adjList[u])
        if(!vis[pr.first])
            dfs_topoSort(pr.first);

    topoSort.push_back(u);
}


void dfs_scc(int u)
{
    vis[u] = true;

    for(auto &v : r_adjList[u]) {
        if(!vis[v]) {
            sccId[v] = sccId[u];
            dfs_scc(v);
        }
    }
}


LL dfs(int u)
{
    if(visMemo[u] != -1) return visMemo[u];

    LL mx = 0;

    for(auto &pr : adj[u]) {
        int v = pr.first, w = pr.second;
        mx = max(mx, w + dfs(v));
    }

    return visMemo[u] = mx + sccCollect[u];
}


int binSearch(int w, int s, int t)
{
    int ret;

    while(s <= t) {
        int mid = (s + t) >> 1;
        int sum = (mid * (mid+1)) >> 1;

        if(sum < w) {
            ret = mid;
            s = mid+1;
        }
        else if(sum > w) {
            t = mid-1;
        }
        else {
            ret = mid;
            break;
        }
    }

    return ret;
}


LL w_to_collection(int w)
{
    LL k = binSearch(w, 0, MAXK);
    return w * (k+1) - (k*k*k + 3*k*k + 2*k) / 6;
}


int main()
{
    // freopen("in.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    adjList.resize(n+3);
    r_adjList.resize(n+3);

    int u, v, w, s;

    while(m--) {
        scanf("%d %d %d", &u, &v, &w);

        adjList[u].push_back(ii(v, w));
        r_adjList[v].push_back(u);
    }

    scanf("%d", &s);

    // SCC

    vis.reset();

    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs_topoSort(i);

    vis.reset();
    sccId.resize(n+3, -1);
    int sccCnt = 0;

    for(int i = n-1; i >= 0; --i) {
        u = topoSort[i];

        if(sccId[u] == -1) {
            sccId[u] = sccCnt++;
            dfs_scc(u);
        }
    }

    // Constructing DAG

    adj.resize(sccCnt+3);
    sccCollect.assign(sccCnt+3, 0);

    for(int u = 1; u <= n; ++u) {
        for(auto &pr : adjList[u]) {
            int uu = sccId[u], vv = sccId[pr.first], w = pr.second;

            //if(0 <= uu and uu < sccCnt and 0 <= vv and vv < sccCnt) {
                if(uu == vv) sccCollect[uu] += w_to_collection(w);
                else adj[uu].push_back(ii(vv, w));
            //}
        }
    }

    // Get ans.

    visMemo.assign(sccCnt+3, -1);

    s = sccId[s];

    LL ans = dfs(s);

    printf("%I64d\n", ans);

    return 0;
}
*/
