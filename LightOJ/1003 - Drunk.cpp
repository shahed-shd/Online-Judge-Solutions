#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 10000+3;

vector<vector<int> > adjList;
int indegree[MAXN];

bool topoSort()
{
    queue<int> q;
    int sz = adjList.size();

    for(int i = 0; i < sz; ++i)
        if(!indegree[i])
            q.push(i);

    int takenCnt = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        ++takenCnt;

        int s = adjList[u].size();

        for(int i = 0; i < s; ++i) {
            int v = adjList[u][i];
            --indegree[v];
            if(!indegree[v]) q.push(v);
        }
    }

    return (takenCnt == sz);
}

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; ++tc) {
        adjList.clear();
        fill(indegree, indegree+MAXN, 0);

        map<string,int> mp;

        int m, cnt = 0;
        cin >> m;

        string s1, s2;

        while(m--) {
            cin >> s1 >> s2;

            if(mp.find(s1) == mp.end()) {
                mp[s1] = cnt++;
                adjList.push_back(vector<int>());
            }

            if(mp.find(s2) == mp.end()) {
                mp[s2] = cnt++;
                adjList.push_back(vector<int>());
            }

            int tmp = mp[s2];

            adjList[mp[s1]].push_back(tmp);
            ++indegree[tmp];
        }

        cout << "Case " << tc << ": "
            << ((topoSort())? "Yes\n" : "No\n");
    }

    return 0;
}
