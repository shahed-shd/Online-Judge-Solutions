#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<string, vector<string> > dictionary;
map<string, vector<string> >::iterator it;

bool is_connected(string s1, string s2)
{
    if(s1.length() == s2.length()) {
        int len = s1.length(), mismatches = 0;

        for(int i = 0; i < len; ++i) {
            if(s1[i] != s2[i]) ++mismatches;

            if(mismatches > 1) return false;
        }

        return true;
    }
    return false;
}

void bfs(string s, string e)
{
    queue<string> q;
    map<string, int> level;
    map<string, bool> visited;

    q.push(s);
    level[s] = 0;
    visited[s] = true;

    string u, v;

    while(!q.empty()) {
        u = q.front();
        q.pop();

        for(unsigned i = 0; i < dictionary[u].size(); ++i) {
            v = dictionary[u][i];

            if(!visited[v]) {
                visited[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
            }

            if(v == e) {
                cout << level[e];
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int tc;
    string word;

    cin >> tc;

    while(tc--) {
        dictionary.clear();

        while(cin >> word, word != "*") {
            dictionary[word];

            for(it = dictionary.begin(); it != dictionary.end(); ++it) {
                if(!word.compare(it->first)) continue;

                if(is_connected(word, it->first)) {
                    dictionary[word].push_back(it->first);
                    dictionary[it->first].push_back(word);
                }
            }
        }

        cin.ignore(1, '\n');

        int pos;
        string starting, ending;

        while(getline(cin, word), word.size() != 0) {
            pos = word.find(" ");
            starting = word.substr(0, pos);
            ending = word.substr(pos+1, string::npos);

            cout << starting << ' ' << ending << ' ';
            bfs(starting, ending);
            cout << '\n';
        }

        if(tc) cout << '\n';
    }

    return 0;
}
