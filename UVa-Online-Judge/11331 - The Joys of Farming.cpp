#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int> > adjList;

string color;
bool isBicolorable;
int white, black;

char dp[2000+5][1000+5];
int sz;
vector<int> diff;

void dfs(int u)
{
    (color[u] == 1)? ++white : ++black;

    for(auto& v : adjList[u]) {
        if(!isBicolorable) return;

        if(!color[v]) {
            color[v] = 0 - color[u];
            dfs(v);
        }
        else if(color[u] == color[v]) {
            isBicolorable = false;
            return;
        }
    }
}

bool fn(int idx, int toTake)
{
    if(toTake == 0) return true;
    if(idx == sz) return false;

    if(dp[idx][toTake] != -1) return dp[idx][toTake];

    bool ret1 = (toTake - diff[idx] >= 0)? fn(idx+1, toTake-diff[idx]) : false;
    bool ret2 = fn(idx+1, toTake);

    dp[idx][toTake] = ret1 || ret2;

    return dp[idx][toTake];
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        adjList.clear();
        color.clear();
        diff.clear();

        int b, c, a, u, v;
        scanf("%d %d %d", &b, &c, &a);

        sz = b+c;

        adjList.resize(sz);
        color.assign(sz, 0);

        while(a--) {
            scanf("%d %d", &u, &v);
            adjList[--u].push_back(--v);
            adjList[v].push_back(u);
        }

        isBicolorable = true;
        int mini = 0;

        for(int i = 0; i < sz && isBicolorable; ++i) {
            if(!color[i]) {
                white = black = 0;
                color[i] = 1;
                dfs(i);

                if(white > black) swap(white, black);
                mini += white;
                if(black-white) diff.push_back(black-white);
            }
        }

        if(!isBicolorable || b < mini || c < mini) {
            puts("no");
            continue;
        }

        memset(dp, -1, sizeof(dp));
        int toTake = min(b, c) - mini;
        sz = diff.size();

        (fn(0, toTake))? puts("yes") : puts("no");
    }

    return 0;
}
