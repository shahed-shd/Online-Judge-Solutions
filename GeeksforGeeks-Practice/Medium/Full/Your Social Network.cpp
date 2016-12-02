// ==================================================
// Problem  :   Your Social Network
// Run time :   0.073 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int connectedTo[n+3];

        for(int i = 2; i <= n; ++i)
            scanf("%d", connectedTo+i);

        int u;

        printf("2 1 1");

        for(int i = 3; i <= n; ++i) {
            u = i;
            vector<int> V;

            while(u != 1) {
                V.push_back(connectedTo[u]);
                u = connectedTo[u];
            }

            for(int j = V.size()-1; j >= 0; --j)
                printf(" %d %d %d", i, V[j], j+1);
        }

        putchar('\n');
    }

    return 0;
}
