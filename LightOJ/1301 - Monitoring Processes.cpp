// ==================================================
// Problem  :   1301 - Monitoring Processes
// Run time :   0.288 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef     pair<int,int>       ii;

vector<ii> V;

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        V.clear();

        int n;
        scanf("%d", &n);

        int si, ti;

        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &si, &ti);

            V.push_back(ii(si, 0));
            V.push_back(ii(ti, 1));
        }

        sort(V.begin(), V.end());

        int curr = 0, mx = 0, sz = V.size();

        for(int i = 0; i < sz; ++i) {
            curr += ((V[i].second)? -1 : 1);
            mx = max(mx, curr);
        }

        printf("Case %d: %d\n", tc, mx);
    }

    return 0;
}


/// -------------------- Alternatively --------------------
// Run time :   0.396 sec.
/*
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
*/


/// -------------------- Alternatively --------------------
// Run time	: 0.436 sec.
/*
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXN = 50000 + 3;

ii ts[MAXN];
multiset<int> mulSet;

bool cmpr(const ii &a, const ii &b)
{
    if(a.second != b.second)
        return (a.second < b.second);
    return (a.first < b.first);
}

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

        sort(ts, ts+n, cmpr);       	// sort by second element of pair.
		
        multiset<int>::iterator it;

        for(int i = 0; i < n; ++i) {
            if(!mulSet.empty()) {
                it = mulSet.lower_bound(ts[i].first);
                if(it != mulSet.begin()) mulSet.erase(--it);
            }

            mulSet.insert(ts[i].second);
        }

        printf("Case %d: %lu\n", tc, mulSet.size());
    }

    return 0;
}
*/
