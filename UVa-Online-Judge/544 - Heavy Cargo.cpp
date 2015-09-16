#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

typedef    tuple<int, string, string>   tpl;    //weight, from, to.

int primsMax(map<string, vector<pair<string, int> > > &adjList, string &start, string &dest)
{
    priority_queue<tpl> q;
    map<string, bool> visited;
    int res = INT_MAX;

    for(unsigned i = 0; i < adjList[start].size(); ++i) {
        q.push(tpl(adjList[start][i].second, start, adjList[start][i].first));
    }
    visited[start] = true;

    tpl top;
    string v;

    while(!q.empty()) {
        top = q.top(); q.pop();
        v = get<2>(top);

        if(visited[v]) continue;

        visited[v] = true;

        if(get<0>(top) < res) res = get<0>(top);

        if(v == dest) break;

        for(unsigned i = 0; i < adjList[v].size(); ++i) {
            q.push(tpl(adjList[v][i].second, v, adjList[v][i].first));
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, r, tc = 0;

    while(cin >> n >> r, n != 0 || r != 0) {
        map<string, vector<pair<string, int> > > adjList;

        string city1, city2;
        int w;

        while(r--) {
            cin >> city1 >> city2 >> w;

            adjList[city1].push_back(make_pair(city2, w));
            adjList[city2].push_back(make_pair(city1, w));
        }

        cin >> city1 >> city2;

        cout << "Scenario #" << ++tc << '\n';
        cout << primsMax(adjList, city1, city2) << " tons\n\n";
    }

    return 0;
}
