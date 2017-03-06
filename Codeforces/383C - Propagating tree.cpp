// ==================================================
// Problem   :   383C - Propagating tree
// Run time  :   0.358 sec.
// Language  :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

#define     offset(x)       (x & (-x))
#define     ff              first
#define     ss              second

typedef     pair<int,int>   ii;

const int MAXN = 200000 + 3;
const int INF = INT_MAX;

struct bit {
    int tree[MAXN] = {0};
    int N;

    void init(int tot) { N = tot; }

    void update(int idx, int val) {
        while(idx <= N) {
            tree[idx] += val;
            idx += offset(idx);
        }
    }

    int query(int idx) {
        int sum = 0;

        while(idx > 0) {
            sum += tree[idx];
            idx -= offset(idx);
        }

        return sum;
    }
};

int n, m, a[MAXN];
vector<vector<int> > adjList;
vector<vector<int> > queryCommand;
vector<vector<ii> > addCommand;
int queryRes[MAXN];
bit b[2];

void dfs(int u, int par = 0, bool idx = 0)
{
    for(auto &pr : addCommand[u])
        b[idx].update(pr.ff, pr.ss);

    for(auto &s : queryCommand[u])
        queryRes[s] = a[u] + b[idx].query(s) - b[!idx].query(s);

    for(auto &v : adjList[u])
        if(v != par)
            dfs(v, u, !idx);

    for(auto &pr : addCommand[u])
        b[idx].update(pr.ff, -pr.ss);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    adjList.resize(n+3);
    addCommand.resize(m+3);
    queryCommand.resize(m+3);

    for(int i = 1; i <= n; ++i) scanf("%d", a+i);

    int u, v;

    for(int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int type;

    for(int i = 1; i <= m; ++i) {
        scanf("%d", &type);

        if(type == 1) {
            scanf("%d %d", &u, &v);
            addCommand[u].push_back(ii(i, v));
        }
        else {
            scanf("%d", &u);
            queryCommand[u].push_back(i);
        }
    }

    b[0].init(m);
    b[1].init(m);
    fill(queryRes, queryRes+m+3, INF);

    dfs(1);

    for(int i = 1; i <= m; ++i) {
        if(queryRes[i] != INF)
            printf("%d\n", queryRes[i]);
    }

    return 0;
}
