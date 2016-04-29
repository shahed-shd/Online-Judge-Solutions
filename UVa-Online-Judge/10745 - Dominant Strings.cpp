// Run time : 0.050 sec.

#include <cstring>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

struct node {
    vector<int> labels;
    node *next[11] = {NULL};
} *root;

vector<string> inputStr;
bitset<15000+3> isClear;
vector<string> dominantStr;

void insert(int cnt[], int label)
{
    node *curr = root;

    for(int i = 0; i < 26; ++i) {
        int id = cnt[i];
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }

    curr->labels.push_back(label);
}

void clearTrie(int cnt[], int pos, node *curr, bool flag)
{
    if(pos == 26) {
        if(flag) {
            for(auto& x : curr->labels)
                isClear[x] = true;
            curr->labels.clear();
        }
        return;
    }

    for(int i = 0; i <= cnt[pos]; ++i)
        if(curr->next[i])
            clearTrie(cnt, pos+1, curr->next[i], flag || (cnt[pos] != i));
}

void dfsFind(int pos, node *curr)
{
    if(pos == 26) {
        if(curr->labels.size() == 1)
            dominantStr.push_back(inputStr[curr->labels[0]]);
        return;
    }

    for(int i = 0; i <= 10; ++i)
        if(curr->next[i])
            dfsFind(pos+1, curr->next[i]);
}

int main()
{
    //freopen("in", "r", stdin);

    char str[15];
    int n = 0;
    root = new node();

    while(scanf("%s", str) != EOF) {
        inputStr.push_back(string(str));

        int cnt[26] = {0};

        for(int i = 0; str[i]; ++i)
                ++cnt[str[i]-'a'];

        insert(cnt, n++);
    }

    for(int i = 0; i < n; ++i) {
        if(!isClear[i]) {
            int cnt[26] = {0};

            for(auto& x : inputStr[i])
                ++cnt[x - 'a'];

            clearTrie(cnt, 0, root, false);
        }
    }

    dfsFind(0, root);

    sort(dominantStr.begin(), dominantStr.end());

    for(auto& s : dominantStr)
        puts(s.c_str());

    return 0;
}
