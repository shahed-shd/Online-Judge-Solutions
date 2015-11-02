#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define     dp(i,j)     (*(dp+2*i+j))

vector<vector<int> > adjList;
int *dp, *par;

int f(int u, bool isGuard)          // minimum vertex cover
{
    if(adjList[u].size() == 0) return 0;
    if(dp(u, isGuard) != -1) return dp(u, isGuard);

    int sum = 0, sz = adjList[u].size(), v;

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(v != par[u]) {
            par[v] = u;
            if(!isGuard) sum += f(v, true);
            else sum += min(f(v, true), f(v, false));
        }
    }

    return dp(u, isGuard) = sum + isGuard;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    adjList.resize(n);

    int u, v;

    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        --u, --v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dp = new int [n*2];
    par = new int [n];

    fill(dp, dp+n*2, -1);
    fill(par, par+n, -1);

    cout << min(f(0, false), f(0, true)) << '\n';

    delete [] dp;
    delete [] par;

    return 0;
}
