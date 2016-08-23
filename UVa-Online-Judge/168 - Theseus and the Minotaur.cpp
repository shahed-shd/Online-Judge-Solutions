// ==================================================
// Problem  :   168 - Theseus and the Minotaur
// Run time :   0.090 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int> > adjList;
bitset<26> isLit;
string ans;
int k;

void process_str(char str[])
{
    int len = strlen(str);

    for(int i = 0; i < len; ++i) {
        int u = str[i] - 'A';
        i += 2;

        for( ; str[i] != ';' && str[i] != '.'; ++i)
            adjList[u].push_back(str[i] - 'A');
    }
}

void dfs(int u, int par, int stepCnt)
{
    for(auto &v : adjList[u]) {
        if(v != par && !isLit[v]) {
            if(stepCnt % k == 0) {
                isLit[u] = true;
                ans.push_back(u+'A');
                ans.push_back(' ');
            }

            dfs(v, u, ++stepCnt);
            return;
        }
    }

    ans.push_back('/');     // Trapped.
    ans.push_back(u+'A');
}

int main()
{
    //freopen("in", "r", stdin);

    char str[260];

    while(scanf("%s", str), str[0] != '#') {
        adjList.clear();
        isLit.reset();
        ans.clear();

        char minotaur_start, theseus_start;
        scanf(" %c %c %d\n", &minotaur_start, &theseus_start, &k);

        adjList.resize(26);
        process_str(str);

        dfs(minotaur_start-'A', theseus_start-'A', 1);

        puts(ans.c_str());
    }

    return 0;
}
