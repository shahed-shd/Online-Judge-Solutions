#include <iostream>
#include <bitset>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 300;

unordered_map<string, int> str_num;
vector<string> num_str;
int totalPerson;

vector<vector<int> > adjList;
int group_mark[MAXN] = {0};

class lowestCommonAncestor {
    int n, table[MAXN][MAXN], level[MAXN];
    bitset<MAXN> visited;


    void dfs(int u) {
        visited[u] = true;

        for(auto& v : adjList[u]) {
            table[v][0] = u;
            if(!visited[v]) dfs(v);
        }
    }

    void formSparseTable() {
        visited.reset();

        for(int i = 0; i < n; ++i)
            if(!visited[i]) dfs(i);

        for(int j = 1; (1<<j) < n; ++j)
            for(int i = 0; i < n; ++i)
                if(table[i][j-1] != -1)
                    table[i][j] = table[table[i][j-1]][j-1];
    }

    void dfs_level(int u) {
        visited[u] = true;

        for(auto& v : adjList[u]) {
            level[v] = level[u] + 1;
            dfs_level(v);
        }

    }

    void formLevel() {
        visited.reset();

        for(int i = 0; i < n; ++i) {
            if(table[i][0] == -1) {
                level[i] = 0;
                dfs_level(i);
            }
        }
    }

public:
    lowestCommonAncestor(int n) {
        this->n = n;

        fill(&table[0][0], &table[MAXN][0], -1);
        formSparseTable();

        formLevel();
    }

    int get_lca(int a, int b) {
        if(level[a] < level[b]) swap(a, b);

        for(int i = log2(n); i >= 0; --i)
            if(level[a] - (1<<i) >= level[b])
                a = table[a][i];

        for(int i = log2(n); i >= 0; --i)
            if(table[a][i] != -1 && table[a][i] != table[b][i])
                a = table[a][i], b = table[b][i];

        if(a == b) return a;

        return table[a][0];
    }

    int get_level(int a) { return level[a]; }
};

void keepRecord(string name)
{
    static int n = 0;

    if(str_num.find(name) == str_num.end()) {
        str_num[name] = n++;
        num_str.push_back(name);
    }
}

void dfs(int u, int mark)
{
    group_mark[u] = mark;

    for(auto& v : adjList[u])
        dfs(v, mark);
}

int main()
{
    ios::sync_with_stdio(false);

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    string str1, str2;
    adjList.resize(300+5);

    while(cin >> str1 >> str2, str1 != "no.child") {
        keepRecord(str1);
        keepRecord(str2);

        adjList[str_num[str2]].push_back(str_num[str1]);
    }

    totalPerson = num_str.size();
    adjList.resize(totalPerson);

    lowestCommonAncestor lca(totalPerson);

    int mark = 0;
    for(int i = 0; i < totalPerson; ++i)
        if(!group_mark[i]) dfs(i, ++mark);

    while(cin >> str1 >> str2) {
        if(str_num.find(str1) == str_num.end() || str_num.find(str2) == str_num.end()) {
            cout << "no relation\n";
            continue;
        }

        int a = str_num[str1], b = str_num[str2];

        if(group_mark[a] == group_mark[b]) {
            int ancestor = lca.get_lca(a, b);

            int level_a = lca.get_level(a);
            int level_b = lca.get_level(b);

            if(ancestor == a || ancestor == b) {
                int level_diff = abs(level_a - level_b);

                while(level_diff > 2) {
                    cout << "great ";
                    --level_diff;
                }

                if(level_diff > 1)
                    cout << "grand ";

                if(level_a > level_b) cout << "child\n";
                else cout << "parent\n";
            }
            else {
                int csn = min(level_a, level_b) - lca.get_level(ancestor) - 1;
                int rmv = abs(level_a - level_b);

                if(csn == 0 && rmv == 0) cout << "sibling";
                else {
                    cout << csn << " cousin";
                    if(rmv) cout << " removed " << rmv;
                }

                cout << '\n';
            }
        }
        else cout << "no relation\n";
    }

    return 0;
}
