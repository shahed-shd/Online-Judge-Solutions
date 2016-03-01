#include <cstdio>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

typedef     tuple<int,int,int>   iii;

const int MAXN = 1000+1;

vector<iii> V;
int n, dp[MAXN], nxt[MAXN];

int LIS(int u)
{
    if(dp[u] != -1) return dp[u];

    int mx = 0, tmp = get<1>(V[u]);

    for(int v = u+1; v < n; ++v)
        if(tmp > get<1>(V[v]) && mx < LIS(v))
            mx = LIS(v), nxt[u] = v;

    return dp[u] = 1 + mx;
}

int main()
{
    //freopen("in", "r", stdin);

    int a, b;
    n = 0;

    while(scanf("%d %d", &a, &b) != EOF)
        V.push_back(iii(a, b, ++n));

    sort(V.begin(), V.end());

    fill_n(dp, MAXN, -1);
    fill_n(nxt, MAXN, -1);

    int mx = 0, start;

    for(int i = 0; i < n; ++i)
        if(mx < LIS(i))
            mx = LIS(i), start = i;

    printf("%d\n", mx);

    while(start != -1) {
        printf("%d\n", get<2>(V[start]));
        start = nxt[start];
    }

    return 0;
}
