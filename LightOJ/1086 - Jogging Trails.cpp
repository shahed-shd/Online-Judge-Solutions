// Run time : 0.004 sec.

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 15+1, INF = INT_MAX/2;

int tc, adjMat[MAXN][MAXN];
int oddVertices[MAXN], oddV_Cnt;
int memo[1<<MAXN];
short memoCase[1<<MAXN] = {0};

inline bool bitcheck(int n, int pos) { return (n>>pos) & 1; }
inline int biton(int n, int pos) { return n | (1<<pos); }

template<class T>
inline T fastIn()
{
    register char ch = 0;
    register T a = 0;
    bool neg = false;

    while(ch < 33) ch = getchar();

    if(ch == '-') neg = true;
    else a = ch - '0';

    while(ch = getchar(), ch > 33)
        a = a * 10 + ch - '0';

    return (neg? -a : a);
}

int fn(int mask)
{
    if(mask == (1<<oddV_Cnt)-1) return 0;

    if(memoCase[mask] == tc) return memo[mask];

    int &ret = memo[mask];

    int u = -1;
    for(int i = 0; i < oddV_Cnt && u == -1; ++i)
        if(!bitcheck(mask, i))
            u = i, mask = biton(mask, i);

    ret = INF;

    for(int i = u+1; i < oddV_Cnt; ++i)
        if(!bitcheck(mask, i))
            ret = min(ret, adjMat[oddVertices[u]][oddVertices[i]] + fn(biton(mask, i)));

    memoCase[mask] = tc;
    return ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>(), m = fastIn<int>();

        fill(&adjMat[0][0], &adjMat[MAXN][0], INF);
        for(int i = 0; i < n; ++i) adjMat[i][i] = 0;

        int u, v, w, degree[MAXN] = {0}, costSum = 0;

        while(m--) {
            u = fastIn<int>(), v = fastIn<int>(), w = fastIn<int>();
            --u, --v;

            ++degree[u], ++degree[v], costSum += w;

            if(adjMat[u][v] > w)
                adjMat[u][v] = adjMat[v][u] = w;
        }

        for(int k = 0; k < n; ++k)      // Floyd-Warshall.
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(adjMat[i][j] > adjMat[i][k] + adjMat[k][j])
                        adjMat[i][j] = adjMat[i][k] + adjMat[k][j];

        oddV_Cnt = 0;

        for(int i = 0; i < n; ++i)
            if(degree[i] & 1) oddVertices[oddV_Cnt++] = i;

        printf("Case %d: %d\n", tc, costSum+fn(0));
    }

    return 0;
}
