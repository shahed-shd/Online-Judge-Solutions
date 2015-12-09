#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> placeNames;
vector<vector<int> > adjList;
vector<int> disc, low;
vector<string> ans;
int discTime;

void dfs(int u, int parent = -1)
{
    low[u] = disc[u] = ++discTime;

    int childCount = 0;
    bool isArticulationPoint = false;

    for(auto& v : adjList[u]) {
        if(!disc[v]) {
            ++childCount;
            dfs(v, u);

            if((parent == -1 && childCount > 1) || (parent != -1 && low[v] >= disc[u]))
                isArticulationPoint = true;

            low[u] = min(low[u], low[v]);
        }
        else if(v != parent)
            low[u] = min(low[u], disc[v]);
    }

    if(isArticulationPoint)
        ans.push_back(placeNames[u]);
}

int main()
{
    ios::sync_with_stdio(false);

    int n, tc = 0;

    while(cin >> n, n) {
        placeNames.clear();
        adjList.clear();
        disc.clear();
        low.clear();
        ans.clear();

        string str;
        unordered_map<string, int> mp;

        for(int i = 0; i < n; ++i) {
            cin >> str;
            placeNames.push_back(str);
            mp[str] = i;
        }

        adjList.resize(n);
        disc.assign(n, 0);
        low.resize(n);

        int r, u, v;
        cin >> r;
        string str2;

        while(r--) {
            cin >> str >> str2;
            u = mp[str], v = mp[str2];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        discTime = 0;

        for(int i = 0; i < n; ++i)
            if(!disc[i])
                dfs(i);

        sort(ans.begin(), ans.end());

        if(tc) cout << '\n';

        cout << "City map #" << ++tc << ": " << ans.size() << " camera(s) found\n";

        for(auto& s : ans)
            cout << s << '\n';
    }

    return 0;
}
