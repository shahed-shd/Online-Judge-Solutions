#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <climits>
using namespace std;

typedef    pair<int,int>    ii;     // days, time.

map<char, string> r_adjList;
map<char, ii> info;
string topoSort;

void dfs(char u, map<char,string> &adjList, map<char,bool> &visited)
{
    visited[u] = true;

    for(auto& v : adjList[u]) {
        if(!visited[v]) dfs(v, adjList, visited);
    }

    topoSort.push_back(u);
}

void topologicalSort()
{
    topoSort.clear();

    map<char, string> adjList;
    map<char, bool> visited;

    for(auto& pr : r_adjList) {     // creating adjList from r_adjList.
        adjList[pr.first];
        for(auto& ch: pr.second) {
            adjList[ch].push_back(pr.first);
        }
    }

    char ch;
    for(auto& pr : adjList) {
        ch = pr.first;
        if(!visited[ch]) dfs(ch, adjList, visited);
    }

    reverse(topoSort.begin(), topoSort.end());
}


int main()
{
    int tc;
    cin >> tc;

    cin.ignore(1, '\n');
    cin.ignore(1, '\n');

    while(tc--) {
        r_adjList.clear();
        info.clear();

        string str;
        char ch, ch2;
        int day;

        while(getline(cin, str), !str.empty()) {
            stringstream ss(str);

            ss >> ch;
            ss >> day;

            r_adjList[ch];
            info[ch].first = day;

            if(!ss.eof()) {
                while(ss.tellg() < str.length()) {
                    ss >> ch2;

                    r_adjList[ch2];
                    r_adjList[ch].push_back(ch2);
                }
            }
        }

        // input complete.

        topologicalSort();

        int maxTime;
        for(auto& ch : topoSort) {
            if(r_adjList[ch].size() == 0) info[ch].second = info[ch].first;
            else {
                maxTime = INT_MIN;
                for(auto& c : r_adjList[ch]) {
                    maxTime = max(maxTime, info[c].second);
                }
                info[ch].second = maxTime + info[ch].first;
            }
        }

        maxTime = INT_MIN;
        for(auto& ch : topoSort) {
            maxTime = max(maxTime, info[ch].second);
        }

        cout << maxTime << '\n';
        if(tc) cout << '\n';
    }

    return 0;
}
