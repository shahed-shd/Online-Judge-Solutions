// Run time : 0.030 sec.

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

typedef     tuple<int,int,char>  iic;

unordered_map<string, int> lang_int;
vector<vector<iic> > adjList;        // tuple holds vertex, edge length, first character.

int dijkstra()
{
    priority_queue<iic, vector<iic>, greater<iic> > q;  // tuple holds distance, vertex, first character.
    q.push(iic(0, 0, '%'));     // vertex 0 is the source & vertex 1 is the destination.

    int sz = adjList.size();

    int dist[sz][26];
    fill(&dist[0][0], &dist[sz][0], INT_MAX);

    for(int i = 0; i < 26; ++i) dist[0][i] = 0;

    while(!q.empty()) {
        iic tpl = q.top(); q.pop();

        int d, u, u_ch;
        tie(d, u, u_ch) = tpl;

        if(u == 1) return d;

        for(auto& ttt : adjList[u]) {
            int v, len, v_ch;
            tie(v, len, v_ch) = ttt;

            if(u_ch != v_ch && d+len < dist[v][v_ch-'a']) {
                q.push(iic(d+len, v, v_ch));
                dist[v][v_ch-'a'] = d+len;
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int m;

    while(cin >> m, m) {
        lang_int.clear();
        adjList.clear();

        int id = 0;
        string s1, s2, s3;

        cin >> s1 >> s2;

        lang_int[s1] = id++;
        lang_int[s2] = id++;
        adjList.resize(2);

        while(m--) {
            cin >> s1 >> s2 >> s3;

            if(lang_int.find(s1) == lang_int.end()) {
                lang_int[s1] = id++;
                adjList.push_back(vector<iic>());
            }

            if(lang_int.find(s2) == lang_int.end()) {
                lang_int[s2] = id++;
                adjList.push_back(vector<iic>());
            }

            int u = lang_int[s1], v = lang_int[s2], len = s3.length();

            adjList[u].push_back(iic(v, len, s3.front()));
            adjList[v].push_back(iic(u, len, s3.front()));
        }

        int ans = dijkstra();

        if(ans == -1) cout << "impossivel\n";
        else cout << ans << '\n';
    }

    return 0;
}
