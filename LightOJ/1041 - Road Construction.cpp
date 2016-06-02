#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef     pair<int,int>       ii;
typedef     pair<int,ii>        iii;

const int MAXL = 50+3;

map<string, int> city_id;
int n;

class UFDS {
    int par[MAXL], rnk[MAXL] = {0};
public:
    UFDS(int node) {
        for(int i = 0; i < node; ++i) par[i] = i;
    }

    int findSet(int i) {
        return ((par[i] == i)? i : par[i] = findSet(par[i]));
    }

    bool unionSet(int i, int j) {
        if(findSet(i) == findSet(j)) return false;

        int p1 = findSet(i), p2 = findSet(j);

        if(rnk[p1] > rnk[p2]) {
            par[p2] = p1;
        }
        else {
            par[p1] = p2;
            if(rnk[p1] == rnk[p2]) ++rnk[p2];
        }

        return true;
    }
};

int get_id(string str)
{
    if(city_id.find(str) == city_id.end()) {
        city_id[str] = n++;
        return n-1;
    }

    return city_id[str];
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        city_id.clear();
        n = 0;

        int m, cost;
        scanf("%d", &m);

        char city1[MAXL], city2[MAXL];

        vector<iii> edges;

        while(m--) {
            scanf("%s %s %d", city1, city2, &cost);
            edges.push_back(iii(cost, ii(get_id(city1), get_id(city2))));
        }

        // Kruskal's algorithm.
        
        sort(edges.begin(), edges.end());

        UFDS uf(n);

        m = edges.size(), cost = 0;
        int roadCnt = 0;

        for(int i = 0; i < m && roadCnt < n-1; ++i)
            if(uf.unionSet(edges[i].second.first, edges[i].second.second))
                ++roadCnt, cost += edges[i].first;

        printf("Case %d: ", tc);

        (roadCnt == n-1)? printf("%d\n", cost) : puts("Impossible");
    }

    return 0;
}
