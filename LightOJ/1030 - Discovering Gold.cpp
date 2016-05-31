#include <cstdio>
using namespace std;

const int MAXN = 100+3;

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, cave[MAXN];
        scanf("%d", &n);

        for(int i = 1; i <= n; ++i) scanf("%d", cave+i);

        double expVal[MAXN], cumulative;

        cumulative = expVal[n] = cave[n];

        for(int i = 1; i < n; ++i) {
            int pos = n-i;

            if(pos+6 < n) cumulative -= expVal[pos+7];

            expVal[pos] = cave[pos] + cumulative / ((i > 6)? 6 : i);
            cumulative += expVal[pos];
        }

        printf("Case %d: %.8f\n", tc, expVal[1]);
    }

    return 0;
}
