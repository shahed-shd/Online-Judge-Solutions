#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<string> beverageList;
map<string, vector<string> > adjList;
map<string, int> indegree;
vector<string> topoSort;
int n, m;

void topologicalSort()
{
    map<string, bool> visited;
    string now;

    while(signed(topoSort.size()) < n) {
        for(auto& bvrg : beverageList) {
            if(!visited[bvrg] && !indegree[bvrg]) {
                now = bvrg;
                break;
            }
        }

        visited[now] = true;
        topoSort.push_back(now);

        for(auto& bvrg : adjList[now]) {
            --indegree[bvrg];
        }
    }
}

int main()
{
    int tc = 0;

    while(cin >> n) {
        beverageList.clear();
        adjList.clear();
        indegree.clear();
        topoSort.clear();

        string beverage, beverage2;

        for(int i = 0; i < n; ++i) {
            cin >> beverage;
            beverageList.push_back(beverage);
        }

        cin >> m;

        while(m--) {
            cin >> beverage >> beverage2;
            adjList[beverage].push_back(beverage2);
            ++indegree[beverage2];
        }

        topologicalSort();

        cout << "Case #" << ++tc << ": Dilbert should drink beverages in this order:";

        for(auto& bvrg : topoSort) {
            cout << ' ' << bvrg;
        }
        cout << ".\n\n";
    }

    return 0;
}
