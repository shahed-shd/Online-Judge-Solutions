// ==================================================
// Problem  :   1229 - Sub-dictionary
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <iostream>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;


const int MAXN = 100 + 3;

unordered_map<string, int> word_id;
vector<string> id_word;
vector<vector<int> > adjList;
bitset<MAXN> vis;

vector<int> sccId;
vector<int> disc, low;
stack<int> stk;
bitset<MAXN> isInStack;
int sccCnt, timeCnt;


void tarjan_scc(int u)
{
    disc[u] = low[u] = ++timeCnt;
    stk.push(u);
    isInStack[u] = true;

    for(auto &v : adjList[u]) {
        if(disc[v] == -1) {
            tarjan_scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if(isInStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if(disc[u] == low[u]) {
        int tp;

        do {
            tp = stk.top(); stk.pop();
            isInStack[tp] = false;
            sccId[tp] = sccCnt;
        } while(tp != u);

        ++sccCnt;
    }
}


void dfs(int u)
{
    vis[u] = true;

    for(auto &v : adjList[u])
        if(!vis[v])
            dfs(v);
}


int word_id_mapping(string &word)
{
    auto it = word_id.find(word);

    if(it == word_id.end()) {
        int sz = word_id.size();;

        word_id[word] = sz;
        id_word[sz] = word;
    }

    return word_id[word];
}


int main()
{
    //freopen("in.txt", "r", stdin);

    ios::sync_with_stdio(false);

    int n;

    while(cin >> n, n) {
        word_id.clear();
        id_word.clear();
        adjList.clear();

        // Forming adjList

        id_word.resize(n+3);
        adjList.resize(n+3);

        cin.ignore(100, '\n');

        for(int i = 0; i < n; ++i) {
            string s, word;
            getline(cin, s);
            stringstream ss(s);

            ss >> word;
            int u = word_id_mapping(word);
            bitset<MAXN> isLinked;

            while(ss >> word) {
                int v = word_id_mapping(word);

                if(!isLinked[v]) {
                    isLinked[v] = true;
                    adjList[u].push_back(v);
                }
            }
        }

        // SCC

        sccId.assign(n+3, -1);
        disc.assign(n+3, -1);
        low.assign(n+3, -1);
        isInStack.reset();
        sccCnt = 0;
        timeCnt = 0;

        for(int i = 0; i < n; ++i)
            if(disc[i] == -1)
                tarjan_scc(i);

        // Each SCC size

        vector<int> sccSize(sccCnt+3, 0);

        for(int i = 0; i < n; ++i)
            ++sccSize[sccId[i]];

        // Take words which is in any SCC of size greater than 1
        // and the words on which SCC words depend.

        vector<string> ansWords;
        vis.reset();

        for(int i = 0; i < n; ++i)
            if(sccSize[sccId[i]] > 1 and !vis[i])
                    dfs(i);

        for(int i = 0; i < n; ++i)
            if(vis[i])
                ansWords.push_back(id_word[i]);

        // Output

        sort(ansWords.begin(), ansWords.end());
        int sz = ansWords.size();

        cout << sz << '\n';

        for(int i = 0; i < sz; ++i)
            cout << ansWords[i] << ((i == sz-1)? '\n' : ' ');
    }

    return 0;
}
