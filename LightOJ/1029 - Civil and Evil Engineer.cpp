#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef     long long           LL;
typedef     pair<int,int>       ii;
typedef     pair<int, ii>       iii;

const int MAXN = 100+3;

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

class UFDS {
    int par[MAXN], rnk[MAXN] = {0};
public:
    UFDS(int n) {
        for(int i = 0; i <= n; ++i)
            par[i] = i;
    }

    int findSet(int n) {
        return ((par[n] == n)? n : par[n] = findSet(par[n]));
    }

    bool unionSet(int a, int b) {
        if(findSet(a) == findSet(b)) return false;

        int p1 = findSet(a), p2 = findSet(b);

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

int kruskal_min(int n, vector<iii> &edges)
{
    int u, v, houseCnt = 1, cost = 0;
    UFDS uf(n);

    for(int i = 0; houseCnt <= n; ++i) {
        u = edges[i].second.first, v = edges[i].second.second;

        if(uf.unionSet(u, v))
            cost += edges[i].first, ++houseCnt;
    }

    return cost;
}

int kruskal_max(int n, vector<iii> &edges)
{
    int u, v, houseCnt = 1, cost = 0;
    UFDS uf(n);

    for(int i = edges.size()-1; houseCnt <= n; --i) {
        u = edges[i].second.first, v = edges[i].second.second;

        if(uf.unionSet(u, v))
            cost += edges[i].first, ++houseCnt;
    }

    return cost;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n, u, v, w;
        n = fastIn<int>();

        vector<iii> edges;

        while(u = fastIn<int>(), v = fastIn<int>(), w = fastIn<int>(), u || v || w)
            edges.push_back(iii(w, ii(u, v)));

        sort(edges.begin(), edges.end());

        LL cost = kruskal_min(n, edges);
        cost += kruskal_max(n, edges);

        printf("Case %d: ", tc);

        (cost & 1)? printf("%lld/2\n", cost) : printf("%lld\n", cost/2);
    }

    return 0;
}
