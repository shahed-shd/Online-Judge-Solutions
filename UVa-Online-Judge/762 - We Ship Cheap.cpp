#include <iostream>
#include <map>
#include <queue>
using namespace std;

map<string, vector<string> > adjList;

void print_path(string a, string src, map<string,string> &parent)
{
    if(parent[a] == src) {
        cout << a << '\n' << a << ' ';
        return;
    }

    print_path(parent[a], src, parent);

    cout << a << '\n' << a << ' ';
}

void bfs(string src, string dest)
{
    queue<string> q;
    map<string, string> parent;
    map<string, bool> visited;

    q.push(src);
    visited[src] = true;

    string u, v;

    while(!q.empty()) {
        u  = q.front();

        size_t sz = adjList[u].size();
        for(unsigned i = 0; i < sz; ++i) {
            v = adjList[u][i];

            if(!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }

            if(v == dest) {
                cout << src << ' ';

                if(parent[dest] != src) print_path(parent[dest], src, parent);

                cout << dest << '\n';

                return;
            }
        }

        q.pop();
    }

    cout << "No route\n";
}


int main()
{
    ios::sync_with_stdio(false);

    int links;
    bool newline = false;

    while(cin >> links) {
        adjList.clear();

        string city1, city2;

        while(links--) {
            cin >> city1 >> city2;
            adjList[city1].push_back(city2);
            adjList[city2].push_back(city1);
        }

        cin >> city1 >> city2;

        if(newline) cout << '\n';
        newline = true;

        bfs(city1, city2);
    }

    return 0;
}
