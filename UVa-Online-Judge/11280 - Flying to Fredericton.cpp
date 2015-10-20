#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

typedef    pair<string,int>    p_si;

unordered_map<string, vector<p_si> > adjList;
vector<string> serial;
unordered_map<string, long long> dist;
vector<long long> storeCost;
int n;

void bellman()
{
    dist["Calgary"] = 0;

    for(int step = 1; step < n; ++step) {
        for(int i = n-2; i >= 0; --i) {
            string u(serial[i]);
            int sz = adjList[u].size();

            for(int j = 0; j < sz; ++j) {
                p_si pr(adjList[u][j]);
                string v(pr.first);

                if(dist[v] > dist[u] + pr.second)
                    dist[v] = dist[u] + pr.second;
            }
        }

        storeCost.push_back(dist["Fredericton"]);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        serial.clear();
        dist.clear();
        storeCost.clear();

        cin >> n;
        string city;

        for(int i = 0; i < n; ++i) {
            cin >> city;
            serial.push_back(city);
            dist[city] = INT_MAX;
            adjList[city];
        }

        int m, cost;
        cin >> m;

        string city2;

        while(m--) {
            cin >> city >> city2 >> cost;
            adjList[city].push_back(p_si(city2, cost));
        }

        bellman();

        cout << "Scenario #" << tc << '\n';

        int q, stopover;
        cin >> q;

        while(q--) {
            cin >> stopover;

            if(stopover > n-2) stopover = n-2;

            if(storeCost[stopover] == INT_MAX)
                cout << "No satisfactory flights\n";
            else
                cout << "Total cost of flight(s) is $" << storeCost[stopover] << '\n';
        }

        if(tc != t) cout << '\n';
    }

    return 0;
}
