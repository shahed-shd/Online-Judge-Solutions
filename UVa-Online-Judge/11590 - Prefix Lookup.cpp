#include <iostream>
#include <vector>
using namespace std;

typedef     unsigned long long      ULL;

struct node {
    ULL cnt = 0;
    node *next[2] = {NULL};
} *root;

void insert(const char str[], ULL n)
{
    node *curr = root;

    for(int i = 0; str[i]; ++i) {
        int id = str[i] - '0';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }

    curr->cnt = n;
}

ULL dfs(node *curr)
{
    if(curr == NULL) return 0ULL;
    if(curr->cnt) return curr->cnt;

    ULL ret = 0;

    for(int i = 0; i < 2; ++i)
        if(curr->next[i])
            ret += dfs(curr->next[i]);

    return ret;
}

ULL search(const char str[])
{
    node *curr = root;

    for(int i = 0; str[i]; ++i) {
        int id = str[i] - '0';
        curr = curr->next[id];
    }

    return curr->cnt - dfs(curr->next[0]) - dfs(curr->next[1]);
}

void del(node *curr)
{
    for(int i = 0; i < 2; ++i)
        if(curr->next[i])
            del(curr->next[i]);

    delete(curr);
}

int main()
{
    ios::sync_with_stdio(false);

    //freopen("in", "r", stdin);

    int n, m;

    while(cin >> n >> m, n || m) {
        root = new node();

        string str;

        while(n--) {
            cin >> str;
            str.pop_back();

            insert(str.c_str(), 1ULL << (m - str.length()));
        }

        str = string();
        insert(str.c_str(), 1ULL << (m - str.length()));

        int k;
        cin >> k;

        while(k--) {
            cin >> str;
            str.pop_back();

            if(str.length() == 0 && m == 64) {
                cout << ((1ULL << 64)-1) - dfs(root->next[0]) - dfs(root->next[1]) + 1 << '\n';
                continue;
            }

            cout << search(str.c_str()) << '\n';
        }

        cout << '\n';

        del(root);
    }

    return 0;
}
