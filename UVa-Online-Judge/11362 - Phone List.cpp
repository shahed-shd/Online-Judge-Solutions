#include <cstdio>
#include <cstring>
using namespace std;

bool isConsistent;

struct node {
    bool endMark = false;
    node *next[10] = {NULL};
} *root;

void insert(char str[]) {
    int len = strlen(str);
    node *curr = root;

    for(int i = 0; i < len; ++i) {
        int id = str[i] - '0';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];

        if(curr->endMark) isConsistent = false;
    }

    curr->endMark = true;

    for(int i = 0; i < 10; ++i) {
        if(curr->next[i]) {
            isConsistent = false;
            return;
        }
    }
}

void del(node *curr)
{
    for(int i = 0; i < 10; ++i)
        if(curr->next[i])
            del(curr->next[i]);

    delete(curr);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);

        root = new node();
        isConsistent = true;

        while(n--) {
            char str[15];
            scanf("%s", str);

            if(isConsistent)
                insert(str);
        }

        puts((isConsistent)? "YES" : "NO");

        del(root);
    }

    return 0;
}
