// ==================================================
// Problem  :   Move the Coins
// Score    :   60 /60
// Language :   C++14
// ==================================================

#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 5e4 + 3;

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

struct node {
    int dist, startTime, finishTime;
    int coinNum, evenXorSum, oddXorSum;
};

node nodes[MAXN];
vector<vector<int> > adjList;
int dfsTime;

void dfs(int u, int par)
{
    nodes[u].startTime = ++dfsTime;
    int evenXorSum = 0, oddXorSum = 0;

    for(auto& v : adjList[u]) {
        if(v != par) {
            nodes[v].dist = nodes[u].dist + 1;
            dfs(v, u);

            evenXorSum ^= nodes[v].oddXorSum;
            oddXorSum ^= nodes[v].evenXorSum ^ nodes[v].coinNum;
        }
    }

    nodes[u].finishTime = ++dfsTime;
    nodes[u].evenXorSum = evenXorSum;
    nodes[u].oddXorSum = oddXorSum;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n = fastIn<int>();

    for(int i = 0; i < n; ++i)
        nodes[i].coinNum = fastIn<int>();

    adjList.resize(n+3);
    int u, v;

    for(int i = 1; i < n; ++i) {
        u = fastIn<int>(), v = fastIn<int>();
        --u, --v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    nodes[0].dist = 0;
    dfsTime = 0;
    dfs(0, -1);

    int q = fastIn<int>();

    while(q--) {
        u = fastIn<int>(), v = fastIn<int>();
        --u, --v;

        node &U = nodes[u], &V = nodes[v];

        if(U.startTime < V.startTime && V.finishTime < U.finishTime) {
            puts("INVALID");
            continue;
        }

        int nim = nodes[0].oddXorSum;

        if(U.dist & 1)
            nim ^= U.evenXorSum ^ U.coinNum;
        else
            nim ^= U.oddXorSum;

        if(V.dist & 1)
            nim ^= U.oddXorSum;
        else
            nim ^= U.evenXorSum ^ U.coinNum;

        puts((nim)? "YES" : "NO");
    }

    return 0;
}
