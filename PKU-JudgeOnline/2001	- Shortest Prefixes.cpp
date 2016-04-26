#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

struct node {
    int goCount;
    node *next[26];

    node() {
        goCount = 0;
        for(int i = 0; i < 26; ++i) next[i] = NULL;
    }
} *root;

void insert(char str[])
{
    int len = strlen(str);
    node *curr = root;

    for(int i = 0; i < len; ++i) {
        ++(curr->goCount);

        int id = str[i] - 'a';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }

    ++(curr->goCount);
}

void abbreviation(const char str[], int len)
{
    node *curr = root;

    for(int i = 0; i < len; ++i) {
        putchar(str[i]);

        curr = curr->next[str[i]-'a'];

        if(curr->goCount == 1) return;
    }
}

void del(node *curr)
{
    for(int i = 0; i < 26; ++i)
        if(curr->next[i])
            del(curr->next[i]);

    delete(curr);
}

int main()
{
    //freopen("in", "r", stdin);

    vector<string> words;
    char str[25];

    root = new node();

    while(scanf("%s", str) != EOF) {
        words.push_back(string(str));
        insert(str);
    }

    int sz = words.size();

    for(int i = 0; i < sz; ++i) {
        printf("%s ", words[i].c_str());
        abbreviation(words[i].c_str(), words[i].length());
        putchar('\n');
    }

    del(root);

    return 0;
}
