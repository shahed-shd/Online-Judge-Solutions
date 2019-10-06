// ==================================================
// Problem  :   1231E - Middle-Out
// Run time :   0.046 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;


const int MAXN = 100 + 3;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int q;
    scanf("%d", &q);

    while(q--) {
        int n;
        char s[MAXN], t[MAXN];

        scanf("%d %s %s", &n, s, t);

        char ss[MAXN], tt[MAXN];

        strcpy(ss, s);
        strcpy(tt, t);

        sort(ss, ss+n);
        sort(tt, tt+n);

        int ans;

        if(strcmp(ss, tt)) {
            ans = -1;               // Impossible to transform.
        } else {
            ans = INT_MAX;

            for(int i = 0; i < n; ++i) {
                int ti = i, cnt = 0;

                for(int j = 0; j < n; ++j) {
                    if(t[ti] == s[j]) {
                        ++cnt;
                        ++ti;
                    }
                }

                ans = min(ans, n - cnt);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
