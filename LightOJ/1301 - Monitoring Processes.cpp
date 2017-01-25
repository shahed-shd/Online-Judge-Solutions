// ==================================================
// Problem  :   1301 - Monitoring Processes
// Run time :   0.396 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXN = 50000 + 3;

ii ts[MAXN];
multiset<int> mulSet;

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        mulSet.clear();

        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
            scanf("%d %d", &ts[i].first, &ts[i].second);

        sort(ts, ts+n);

        for(int i = 0; i < n; ++i) {
            if(!mulSet.empty()) {
                if(*mulSet.begin() < ts[i].first) {
                    mulSet.erase(mulSet.begin());
                }
            }

            mulSet.insert(ts[i].second);
        }

        printf("Case %d: %lu\n", tc, mulSet.size());
    }

    return 0;
}
