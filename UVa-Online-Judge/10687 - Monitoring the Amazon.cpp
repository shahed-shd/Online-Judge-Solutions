// ==================================================
// Problem  :   10687 - Monitoring the Amazon
// Run time :   0.020 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
#include <queue>
#include <utility>
#include <vector>
#include <climits>
using namespace std;


typedef     pair<int, int>      ii;


const int MAXN = 1000 + 3;

ii stations[MAXN];
vector<vector<int> > adjList;


bool bfs(int n)
{
    queue<int> q;
    bitset<MAXN> vis;

    q.push(0);
    vis[0] = true;

    while(!q.empty()) {
        int u_idx = q.front(); q.pop();

        for(auto &v_idx : adjList[u_idx]) {
            if(!vis[v_idx]) {
                vis[v_idx] = true;
                q.push(v_idx);
            }
        }
    }

    return (int(vis.count()) == n);
}


void form_adjList(int n)
{
    adjList.resize(n+3);

    for(int i = 0; i < n; ++i) {
        ii u = stations[i];
        int d1 = INT_MAX, d2 = INT_MAX, idx1, idx2;

        for(int j = 0; j < n; ++j) {
            if(i == j) continue;

            ii v = stations[j];
            int d = (u.first - v.first) * (u.first - v.first) + (u.second - v.second) * (u.second - v.second);

            if(d < d1) {
                d2 = d1, idx2 = idx1;
                d1 = d, idx1 = j;
            }
            else if(d == d1) {
                ii old_v = stations[idx1];

                if(old_v.first > v.first or (old_v.first == v.first and old_v.second > v.second)) {
                    d2 = d1, idx2 = idx1;
                    idx1 = j;
                }
            }
            else if(d < d2) {
                d2 = d, idx2 = j;
            }
            else if(d == d2) {
                ii old_v = stations[idx2];

                if(old_v.first > v.first or (old_v.first == v.first and old_v.second > v.second)) {
                    idx2 = j;
                }
            }
        }

        adjList[i].push_back(idx1);
        adjList[i].push_back(idx2);
    }
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int n;

    while(scanf("%d", &n), n) {
        adjList.clear();

        int x, y;

        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &x,  &y);
            stations[i] = ii(x, y);
        }

        form_adjList(n);

        puts((bfs(n))? "All stations are reachable." : "There are stations that are unreachable.");
    }

    return 0;
}
