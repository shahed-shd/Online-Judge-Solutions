// ==================================================
// Problem  :   610 - Street Directions
// Run time :   0.020 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


const int MAXN = 1000 + 3;
enum visColor {WHITE, GRAY, BLACK};

vector<vector<int> > adjList;
int visTime[MAXN];
visColor color[MAXN];
int hitNode[MAXN];
int vtime;


void dfs(int u, int p)
{
    visTime[u] = ++vtime;
    color[u] = GRAY;

    for(auto &v : adjList[u]) {
        if(!visTime[v]) {
            dfs(v, u);

            if(hitNode[v] != v) {
                printf("%d %d\n", u, v);

                if(visTime[hitNode[v]] < visTime[hitNode[u]])
                    hitNode[u] = hitNode[v];
            }
            else {
                printf("%d %d\n%d %d\n", u, v, v, u);
            }
        }
        else if(v != p and color[v] == GRAY) {
            printf("%d %d\n", u, v);

            if(visTime[v] < visTime[hitNode[u]])
                hitNode[u] = v;
        }
    }

    color[u] = BLACK;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int n, m, tc = 0;

    while(scanf("%d %d", &n, &m), n and m) {
        adjList.clear();

        adjList.resize(n+3);
        int u, v;

        while(m--) {
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        printf("%d\n\n", ++tc);


        fill_n(visTime, n+3, 0);
        fill_n(color, n+3, WHITE);
        for(int i = 0; i < n+3; ++i) hitNode[i] = i;
        vtime = 0;

        dfs(1, -1);

        puts("#");
    }

    return 0;
}
