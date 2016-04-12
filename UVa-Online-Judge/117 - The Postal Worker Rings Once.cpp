#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

typedef     pair<int,int>   ii;

vector<vector<ii> > adjList;

int dijkstra(int s, int t)
{
    priority_queue<ii, vector<ii>, greater<ii> > q;
    int dist[26];

    fill_n(dist, 26, INT_MAX);

    dist[s] = 0;
    q.push(ii(0, s));

    while(!q.empty()) {
        int u = q.top().second; q.pop();

        if(u == t) return dist[u];

        for(auto& pr : adjList[u]) {
            int v = pr.first;

            if(dist[v] > dist[u] + pr.second) {
                dist[v] = dist[u] + pr.second;
                q.push(ii(dist[v], v));
            }
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in", "r", stdin);

    string input;

    while(cin >> input) {
        adjList.clear();
        adjList.resize(26);

        int tour = 0, countDegree[26] = {0};

        do {
            int u = input.front()-'a', v = input.back()-'a', len = input.length();

            adjList[u].push_back(ii(v, len));
            adjList[v].push_back(ii(u, len));

            tour += len;
            ++countDegree[u];
            ++countDegree[v];
        }while(cin >> input, input != "deadend");

        vector<int> oddDegreeNodes;

        for(int i = 0; i < 26; ++i)
            if(countDegree[i] & 1) oddDegreeNodes.push_back(i);

        if(!oddDegreeNodes.size()) cout << tour << '\n';
        else cout << tour + dijkstra(oddDegreeNodes[0], oddDegreeNodes[1]) << '\n';
    }

    return 0;
}
