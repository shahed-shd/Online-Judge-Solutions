#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char, string> adjList;
map<char, bool> visited;
map<char, int> indegree;
string topoSort;
unsigned n;     // number of variables.

void topologicalSort(char ch)
{
    visited[ch] = true;
    topoSort.push_back(ch);

    for(auto& c : adjList[ch]) {
        --indegree[c];
    }

    char c;
    for(auto& pr : adjList) {
        c = pr.first;
        if(!indegree[c] && !visited[c]) {
            topologicalSort(c);
        }
    }

    if(topoSort.length() == n) {
        cout << topoSort << '\n';
    }

    visited[ch] = false;
    topoSort.pop_back();
    for(auto& c : adjList[ch]) {
        ++indegree[c];
    }
}

int main()
{
    string str;
    bool newline = false;

    while(getline(cin, str)) {
        adjList.clear();
        visited.clear();
        indegree.clear();
        topoSort.clear();

        n = 0;
        for(auto& ch : str) {
            if('a' <= ch && ch <= 'z') {
                adjList[ch];
                visited[ch];
                ++n;
            }
        }

        getline(cin, str);

        char ch, ch2;
        int len = str.length();

        for(int i = 0; i < len; ++i) {
            ch = str[i++];
            ch2 = str[++i];
            ++i;

            adjList[ch].push_back(ch2);
            ++indegree[ch2];
        }

        // input complete.

        if(newline) cout << '\n';
        newline = true;

        for(auto& pr : adjList) {
            ch = pr.first;
            if(!indegree[ch]) {
                topologicalSort(ch);
            }
        }
    }

    return 0;
}
