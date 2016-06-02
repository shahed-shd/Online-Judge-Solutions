#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXS = 333+3;

map<string, int> step_id;
vector<string> id_step;
int n;

int get_id(string str)
{
    if(step_id.find(str) == step_id.end()) {
        step_id[str] = n++;
        id_step.push_back(str);

        return n-1;
    }

    return step_id[str];
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        step_id.clear();
        id_step.clear();
        n = 0;

        int s;
        scanf("%d", &s);

        ii consecutive[s];
        fill(consecutive, consecutive+s, ii(-1, -1));

        char str1[100], str2[100];

        for(int i = 1; i < s; ++i) {
            scanf("%s %s", str1, str2);
            int id1 = get_id(str1), id2 = get_id(str2);

            consecutive[id1].second = id2;
            consecutive[id2].first = id1;
        }

        int start;
        for(start = 0; consecutive[start].first != -1; ++start);

        printf("Case %d:\n", tc);

        for(int i = 0; i < s; ++i) {
            puts(id_step[start].c_str());
            start = consecutive[start].second;
        }

        putchar('\n');
    }

    return 0;
}
