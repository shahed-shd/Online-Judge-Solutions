#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef     pair<int,int>   ii;

vector<vector<int> > table;
vector<ii> pos;

void move_a_onto_b(int a, int b)
{
    // Moving the blocks above a to the initial position.

    int x = pos[a].first;
    int y = table[x].size();
    int temp;

    while(temp = table[x][--y], temp != a) {
        table[temp].push_back(temp);
        pos[temp] = ii(temp, 0);
        table[x].pop_back();
    }

    table[x].pop_back();    // Removing a too.

    // Now, moving the blocks above b to the initial position.

    x = pos[b].first;
    y = table[x].size();

    while(temp = table[x][--y], temp != b) {
        table[temp].push_back(temp);
        pos[temp] = ii(temp, 0);
        table[x].pop_back();
    }

    // Now, placing a onto b.

    table[x].push_back(a);
    pos[a] = ii(x, table[x].size()-1);
}

void move_a_over_b(int a, int b)
{
    // Moving the blocks above a to the initial position.

    int x = pos[a].first;
    int y = table[x].size();
    int temp;

    while(temp = table[x][--y], temp != a) {
        table[temp].push_back(temp);
        pos[temp] = ii(temp, 0);
        table[x].pop_back();
    }

    table[x].pop_back();    // Removing a too.

    // Now, placing a over b.

    x = pos[b].first;

    table[x].push_back(a);
    pos[a] = ii(x, table[x].size()-1);
}

void pile_a_onto_b(int a, int b)
{
    int x = pos[b].first;
    int y = table[x].size();
    int temp;

    while(temp = table[x][--y], temp != b) {
        table[temp].push_back(temp);
        pos[temp] = ii(temp, 0);
        table[x].pop_back();
    }

    x = pos[a].first;
    y = pos[a].second;
    int hold_y = y;
    int sz = table[x].size();

    int x2 = pos[b].first;

    while(y < sz) {
        temp = table[x][y++];
        table[x2].push_back(temp);
        pos[temp] = ii(x2, table[x2].size()-1);
    }

    table[x].erase(table[x].begin() + hold_y, table[x].end());
}

void pile_a_over_b(int a, int b)
{
    int x = pos[a].first;
    int y = pos[a].second;
    int hold_y = y;
    int sz = table[x].size();

    int x2 = pos[b].first;
    int temp;

    while(y < sz) {
        temp = table[x][y++];
        table[x2].push_back(temp);
        pos[temp] = ii(x2, table[x2].size()-1);
    }

    table[x].erase(table[x].begin() + hold_y, table[x].end());
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%d", &n);

    table.resize(n);
    pos.resize(n);

    for(int i = 0; i < n; ++i) {
        table[i].push_back(i);
        pos[i] = ii(i, 0);
    }

    char str1[10], str2[10];
    int a, b;

    while(scanf("%s", str1) && strcmp(str1, "quit")) {
        scanf("%d %s %d", &a, str2, &b);

        if(a == b || pos[a].first == pos[b].first) continue;

        if(!strcmp(str1, "move"))
            (!strcmp(str2, "onto"))? move_a_onto_b(a, b) : move_a_over_b(a, b);
        else
            (!strcmp(str2, "onto"))? pile_a_onto_b(a, b) : pile_a_over_b(a, b);
    }

    for(int i = 0; i < n; ++i) {
        printf("%d:", i);

        for(auto& x : table[i])
            printf(" %d", x);

        putchar('\n');
    }

    return 0;
}
