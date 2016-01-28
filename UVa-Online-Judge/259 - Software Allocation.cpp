// Run time: 0.000 sec

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct data {
    int howMany = 0;
    unordered_set<int> whichComp;
    bool isTried = false;
};

unordered_map<char, data> mp;
char computer[10+1];

char input()
{
    char ch;

    while(ch = getchar(), ch != '\n' && ch != EOF) {
        int tmp;
        scanf("%d ", &tmp);
        mp[ch].howMany += tmp;

        while(tmp = getchar(), tmp != ';')
            mp[ch].whichComp.insert(tmp-'0');

        getchar();
    }

    return ch;
}

bool replaceApp(char app)
{
    if(mp[app].isTried) return false;

    for(auto& x : mp[app].whichComp) {
        if(computer[x] == '_') {
            computer[x] = app;
            return true;
        }
    }

    // Now, in case of no vacancy.

    for(auto& x : mp[app].whichComp) {
        if(app != computer[x]) {
            mp[app].isTried = true;

            bool isDone = replaceApp(computer[x]);

            mp[app].isTried = false;

            if(isDone) {
                computer[x] = app;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char input_ch;

    do {
        mp.clear();
        input_ch = input();

        fill_n(computer, 10, '_');
        computer[10] = '\0';

        bool isOK = false;

        for(auto& pr : mp) {
            for(int i = 0; i < pr.second.howMany; ++i) {
                isOK = replaceApp(pr.first);
                if(!isOK) break;;
            }

            if(!isOK) break;
        }

        (isOK)? puts(computer) : puts("!");

    } while(input_ch != EOF);

    return 0;
}


// --------------------------- Alternatively ---------------------------
// Run time: 0.003 sec
/*

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

// 0 is source, 1 to 26 are letters (apps), 27 to 36 are computers, 37 is sink.
const int SRC = 0, SINK = 37, INF = INT_MAX / 2;

int matrix[40][40];
char computers[10+1];       // extra 1 for null character.
vector<int> path;
int totalApp;

char input()
{
    char ch;

    while(ch = getchar(), ch != '\n' && ch != EOF) {
        int tmp, app = ch - 'A' + 1;
        scanf("%d ", &tmp);

        matrix[SRC][app] = tmp;
        totalApp += tmp;

        while(tmp = getchar(), tmp != ';')
            matrix[app][tmp-'0'+27] = INF;

        getchar();
    }

    return ch;
}

bool bfs()
{
    bool visited[40] = {false};
    visited[SRC] = true;

    int parent[40] = {0};
    parent[SRC] = -1;

    queue<int> q;
    q.push(SRC);

    while(!q.empty()) {
        int u = q.front(); q.pop();

        if(u == SINK) {
            path.push_back(SINK);
            int p = parent[SINK];

            while(p != -1) {
                path.push_back(p);
                p = parent[p];
            }

            reverse(path.begin(), path.end());
            return true;
        }

        for(int i = 0; i <= SINK; ++i) {
            if(matrix[u][i] > 0 && !visited[i]) {
                visited[i] = true;
                parent[i] = u;
                q.push(i);
            }
        }
    }

    return false;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char input_ch;

    do {
        fill(&matrix[0][0], &matrix[40][0], 0);
        fill_n(computers, 10, '_');
        computers[10] = '\0';

        totalApp = 0;

        input_ch = input();

        for(int i = 27; i <= 36; ++i)
            matrix[i][SINK] = 1;        // every computer to sink, having weigth 1.

        // Now, Max flow algorithm by Ford-Fulkerson method.

        int totalFlow = 0;

        while(path.clear(), bfs()) {
            int sz = path.size() - 1;
            int minResCap = INF;

            for(int i = 0; i < sz; ++i)
                minResCap = min(minResCap, matrix[path[i]][path[i+1]]);

            for(int i = 0; i < sz; ++i) {
                int u = path[i], v = path[i+1];

                matrix[u][v] -= minResCap;
                matrix[v][u] += minResCap;

                if(1 <= u && u <= 26) {
                    computers[v-27] = u + 'A' - 1;
                }
            }

            totalFlow += minResCap;
        }

        (totalFlow == totalApp)? puts(computers) : puts("!");

    } while(input_ch != EOF);

    return 0;
}

*/
