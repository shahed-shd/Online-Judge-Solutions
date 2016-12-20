// ==================================================
// Problem  :   1210 - Efficient Traffic System
// Run time :   0.152 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int> > adjList;

struct tarjan_ssc {
    vector<bool> isInStack;
    vector<int> disc, low, whichSSC;
    stack<int> stk;
    int totNode, currTick, currSSC;

    tarjan_ssc(int n) {
        totNode = n;
        isInStack.assign(n, false);
        disc.assign(n, -1);
        low.assign(n, -1);
        whichSSC.assign(n, -1);
        currTick = 0;
        currSSC = 0;
    }

    void dfs(int u) {
        disc[u] = low[u] = currTick++;
        isInStack[u] = true;
        stk.push(u);

        int v, sz = adjList[u].size();

        for(int i = 0; i < sz; ++i) {
            v = adjList[u][i];

            if(disc[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if(isInStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if(disc[u] == low[u]) {
            do {
                v = stk.top();
                stk.pop();
                isInStack[v] = false;
                whichSSC[v] = currSSC;
            } while(v != u);

            ++currSSC;
        }
    }

    void findSSC() {
        for(int i = 0; i < totNode; ++i) {
            if(disc[i] == -1) {
                dfs(i);
            }
        }
    }
};

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();

        int n, m;
        scanf("%d %d", &n, &m);

        adjList.resize(n+3);

        int u, v;

        while(m--) {
            scanf("%d %d", &u, &v);
            adjList[--u].push_back(--v);
        }

        tarjan_ssc tssc(n);
        tssc.findSSC();
        int totSSC = tssc.currSSC;

        if(totSSC <= 1) {
            printf("Case %d: 0\n", tc);
            continue;
        }

        vector<int> inDeg(totSSC, 0), outDeg(totSSC, 0);

        for(int u = 0; u < n; ++u) {
            int sz = adjList[u].size();

            for(int i = 0; i < sz; ++i) {
                int v = adjList[u][i];

                if(tssc.whichSSC[u] != tssc.whichSSC[v]) {
                    ++outDeg[tssc.whichSSC[u]];
                    ++inDeg[tssc.whichSSC[v]];
                }
            }
        }

        int inDegZeroCnt = 0, outDegZeroCnt = 0;

        for(int i = 0; i < totSSC; ++i) {
            if(inDeg[i] == 0) ++inDegZeroCnt;
            if(outDeg[i] == 0)  ++outDegZeroCnt;
        }

        printf("Case %d: %d\n", tc, max(inDegZeroCnt, outDegZeroCnt));
    }

    return 0;
}
