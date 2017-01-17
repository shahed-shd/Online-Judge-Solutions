// ==================================================
// Problem  :   1356 - Prime Independence
// Run time :   0.480 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <bitset>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

const int MAXN = 40000 + 3;
const int MAXX = 500000 + 3;
const int INF = INT_MAX;
const int NIL = 0;

vector<int> primes;
int primeCnt[MAXX] = {0};
vector<vector<int> > adjList;

int U, V, pairU[MAXN], pairV[MAXN], dist[MAXN];

void sieve()
{
    bitset<MAXX> status;

    primeCnt[1] = 1;

    for(int i = 2; i < MAXX; ++i) {
        if(!status[i]) {
            primes.push_back(i);

            for(int j = i+i; j < MAXX; j+=i) {
                status[j] = true;
                int num = j;

                while(num % i == 0)
                    ++primeCnt[j], num /= i;
            }
        }
    }
}

bool bfs()
{
    queue<int> q;

    for(int u = 1; u <= U; ++u) {
        if(pairU[u] == NIL) {
            dist[u] = 0;
            q.push(u);
        }
        else dist[u] = INF;
    }

    dist[NIL] = INF;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        if(dist[u] < dist[NIL]) {
            int v, sz = adjList[u].size();

            for(int i = 0; i < sz; ++i) {
                v = adjList[u][i];

                if(dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }

    return (dist[NIL] != INF);
}

bool dfs(int u)
{
    if(u == NIL) return true;

    int v, sz = adjList[u].size();

    for(int i = 0; i < sz; ++i) {
        v = adjList[u][i];

        if(dist[pairV[v]] == dist[u]+1 && dfs(pairV[v])) {
            pairV[v] = u;
            pairU[u] = v;
            return true;
        }
    }

    dist[u] = INF;
    return false;
}

int hopcroft_karp()
{
    fill(pairU+1, pairU+U+1, NIL);
    fill(pairV+1, pairV+V+1, NIL);

    int matching = 0;

    while(bfs()) {
        for(int u = 1; u <= U; ++u)
            if(pairU[u] == NIL && dfs(u))
                ++matching;
    }

    return matching;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    sieve();

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; ++tc) {
        adjList.clear();

        int n;
        scanf("%d", &n);

        int arr[MAXN], whichIndex[MAXX] = {0};

        for(int i = 1; i <= n; ++i) {
            scanf("%d", arr+i);
            whichIndex[arr[i]] = i;
        }

        adjList.resize(n+3);
        int sz = primes.size();

        for(int i = 1; i <= n; ++i) {
            int num = arr[i];

            for(int j = 0; j < sz && primes[j]*primes[j] <= num; ++j) {
                if(num % primes[j] == 0) {
                    int idx = whichIndex[arr[i] / primes[j]];

                    if(idx) {
                        if(primeCnt[arr[i]] & 1)
                            adjList[i].push_back(idx);
                        else
                            adjList[idx].push_back(i);
                    }

                    while(num % primes[j] == 0) num /= primes[j];
                }
            }

            if(num != 1) {
                int idx = whichIndex[arr[i] / num];

                if(idx) {
                    if(primeCnt[arr[i]] & 1)
                        adjList[i].push_back(idx);
                    else
                        adjList[idx].push_back(i);
                }
            }
        }

        U = V = n;
        int ans = n - hopcroft_karp();

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
