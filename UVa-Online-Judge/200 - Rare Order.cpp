#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<char, unordered_set<char> > adjList;
unordered_map<char, bool> visited;
string topoSort;

void dfs(char u)
{
    visited[u] = true;

    for(auto& v : adjList[u])
        if(!visited[v]) dfs(v);

    topoSort.push_back(u);
}

int main()
{
    ios::sync_with_stdio(false);

    //freopen("in", "r", stdin);

    string str1, str2;

    while(cin >> str1) {
        adjList.clear();
        visited.clear();
        topoSort.clear();

        while(cin >> str2, str2 != "#") {
            auto pr = mismatch(str1.begin(), str1.end(), str2.begin());

            if(*pr.first != 0 && *pr.second != 0)
                adjList[*pr.first].insert(*pr.second);

            str1 = str2;
        }

        for(auto& pr : adjList)
            if(!visited[pr.first])
                dfs(pr.first);

        cout << string(topoSort.rbegin(), topoSort.rend()) << '\n';
    }

    return 0;
}
