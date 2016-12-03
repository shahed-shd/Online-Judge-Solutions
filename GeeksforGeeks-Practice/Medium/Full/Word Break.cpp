// ==================================================
// Problem  :   Word Break
// Run time :   0.066 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int MAXL = 1000 + 3;

struct node {
    int len;
    node *next[26+1];

    node() {
        len = 0;
        for(int i = 0; i < 27; ++i) next[i] = NULL;
    }
};

class trie {
    node *root;

    void clr(node *curr) {
        if(curr == NULL) return;

        for(int i = 0; i < 27; ++i)
            clr(curr->next[i]);

        delete curr;
    }

public:
    void init() { root = new node(); }

    void insertWord(string str) {
        node *curr = root;

        for(auto &x : str) {
            if(curr->next[x-'a'] == NULL) curr->next[x-'a'] = new node();
            curr = curr->next[x-'a'];
        }

        curr->len = str.length();
    }

    void queryWords(string str, vector<int> &qryV) {
        qryV.clear();
        node *curr = root;

        for(auto &x : str) {
            if(curr->next[x-'a'] == NULL) return;
            curr = curr->next[x-'a'];
            if(curr->len) qryV.push_back(curr->len);
        }
    }

    void clearTrie() { clr(root); }
};

trie tr;
int memo[MAXL];

char str[MAXL];
int strLen;

int fn(int idx)
{
    if(idx == strLen) return 1;
    if(idx > strLen) return 0;

    if(memo[idx] != -1) return memo[idx];

    vector<int> qryV;
    tr.queryWords(&str[idx], qryV);

    memo[idx] = 0;

    for(auto &x : qryV) {
        if(fn(idx+x)) {
            memo[idx] = 1;
            break;
        }
    }

    return memo[idx];
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        tr.init();

        int n;
        scanf("%d", &n);

        char word[20];

        for(int i = 0; i < n; ++i) {
            scanf("%s", word);
            tr.insertWord(word);
        }

        scanf("%s", str);
        strLen = strlen(str);

        fill(memo, memo+MAXL, -1);

        int ans = fn(0);

        puts((ans)? "1" : "0");

        tr.clearTrie();
    }

    return 0;
}
