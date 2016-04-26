#include <cstdio>
using namespace std;

struct node {
    bool endMark;
    node *next[2];

    node() {
        endMark = false;
        next[0] = next[1] = NULL;
    }
} *root;

bool isDecodable;

void insert(const char str[])
{
    node *curr = root;

    for(int i = 0; str[i]; ++i) {
        int id = str[i] - '0';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];

        if(curr->endMark) {
            isDecodable = false;
            return;
        }
    }

    curr->endMark = true;

    if(curr->next[0] || curr->next[1])
        isDecodable = false;
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
    //freopen("in", "r", stdin);

    int tc = 0;
    char str[15];

    while(scanf("%s", str) != EOF) {
        root = new node();
        isDecodable = true;

        insert(str);

        while(scanf("%s", str), str[0] != '9')
            if(isDecodable)
                insert(str);

        printf("Set %d %s immediately decodable\n", ++tc, (isDecodable)? "is" : "is not");

        del(root);
    }

    return 0;
}
