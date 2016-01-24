#include <iostream>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

struct data {
    int v, uTime, vTime;
    data(int x, int y, int z) { v = x, uTime = y, vTime = z; }
};

unordered_map<string, int> name_id;
vector<string> id_name;
vector<vector<data> > adjList;
vector<bool> visited;
int startTime, startTimeTmp, dest, destTime;

void dfs(int u, int nowTime)
{
    if(u == dest) {
        if(destTime > nowTime) {
            destTime = nowTime;
            startTime = startTimeTmp;
        }
        else if(destTime == nowTime)
            startTime = max(startTime, startTimeTmp);

        return;
    }

    visited[u] = true;

    for(auto& x : adjList[u]) {
        if(x.uTime < nowTime) continue;
        if(!visited[x.v]) dfs(x.v, x.vTime);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int cases;
    cin >> cases;

    for(int tc = 1; tc <= cases; ++tc) {
        name_id.clear();
        id_name.clear();
        adjList.clear();
        visited.clear();

        int c;
        cin >> c;

        adjList.resize(c);

        string str;

        for(int i = 0; i < c; ++i) {
            cin >> str;
            id_name.push_back(str);
            name_id[str] = i;
        }

        int t;
        cin >> t;

        while(t--) {
            int t_i;
            cin >> t_i;

            vector<pair<int, int> > train;
            int timing;

            while(t_i--) {
                cin >> timing >> str;
                train.push_back(make_pair(timing, name_id[str]));
            }

            sort(train.begin(), train.end());

            int sz = train.size() - 1;

            for(int i = 0; i < sz; ++i)
                adjList[train[i].second].push_back(data(train[i+1].second, train[i].first, train[i+1].first));
        }

        int time, start;
        cin >> time >> str;
        start = name_id[str];
        cin >> str;
        dest = name_id[str];

        destTime = INT_MAX;

        for(auto& x : adjList[start]) {
            if(x.uTime < time) continue;

            visited.assign(c, false);

            visited[start] = true;
            startTimeTmp = x.uTime;

            dfs(x.v, x.vTime);
        }

        cout << "Scenario " << tc << '\n';

        if(destTime == INT_MAX) cout << "No connection\n\n";
        else {
            cout << "Departure " << setw(4) << setfill('0') << startTime << ' ' << id_name[start] << '\n'
                << "Arrival   " << setw(4) << setfill('0') << destTime << ' ' << id_name[dest] << "\n\n";
        }
    }

    return 0;
}
