// ==================================================
// Problem  :   1100 - Again Array Queries
// Run time :   0.060 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

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

const int MAXN = 1e5 + 3;
const int MAXV = 1000 + 3;

int arr[MAXN];

int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>(), q = fastIn<int>();

        for(int i = 0; i < n; ++i) arr[i] = fastIn<int>();

        printf("Case %d:\n", tc);

        int s, t;

        while(q--) {
            s = fastIn<int>(), t = fastIn<int>();

            int mx = 0, mn = MAXV, buckets[MAXV] = {0}, ans = -1;

            for(int i = s; i <= t; ++i) {
                ++buckets[arr[i]];
                if(buckets[arr[i]] > 1) {
                    ans = 0;
                    break;
                }

                mx = max(mx, arr[i]);
                mn = min(mn, arr[i]);
            }

            if(ans != -1) {
                puts("0");
                continue;
            }

            ans = MAXV;
            int prevFound = mn;

            for(int i = mn+1; i <= mx; ++i) {
                if(buckets[i]) {
                    ans = min(ans, i - prevFound);
                    prevFound = i;
                }
            }

            printf("%d\n", ans);
        }
    }

    return 0;
}
