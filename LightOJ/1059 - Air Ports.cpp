#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

typedef     pair<int,int>       ii;
typedef     pair<int,ii>        iii;

const int MAXN = 10000+3, MAXM = 100000+3;

template<class T>
inline T fastIn()
{
    register char ch = 0;
    register T a = 0;
    bool neg = false;

    while(ch < 33) ch = getchar();

    if(ch == '-') neg = true;
    else a = ch - '0';

    while(ch = getchar(), ch > 33)
        a = a * 10 + (ch - '0');

    return (neg? -a : a);
}

class UFDS {
    int par[MAXN], rnk[MAXN] = {0};
    int numOfSets;
public:
    UFDS(int node) {
        for(int i = 0; i < node; ++i) par[i] = i;
        numOfSets = node;
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

        --numOfSets;

        return true;
    }

    int sets() { return numOfSets; }
};

int main()
{
    //freopen("in.txt", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>(), m = fastIn<int>(), a = fastIn<int>();

        iii edges[MAXM];
        int u, v, w;

        for(int i = 0; i < m; ++i) {
            u = fastIn<int>(), v = fastIn<int>(), w = fastIn<int>();
            edges[i] = iii(w, ii(--u, --v));
        }

        sort(edges, edges+m);

        UFDS uf(n);
        int cost = 0;

        for(int i = 0; i < m && uf.sets() > 1 && edges[i].first < a; ++i)
            if(uf.unionSet(edges[i].second.first, edges[i].second.second))
                cost += edges[i].first;

        cost += uf.sets() * a;

        printf("Case %d: %d %d\n", tc, cost, uf.sets());
    }

    return 0;
}
