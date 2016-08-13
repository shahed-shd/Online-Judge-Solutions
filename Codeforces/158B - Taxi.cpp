// ==================================================
// Problem  :   158B - Taxi
// Run time :   0.062 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    int n;

    while(~scanf("%d", &n)) {
        int s, cnt[5] = {0};

        while(n--) {
            scanf("%d", &s);
            ++cnt[s];
        }

        int ans = cnt[4];

        ans += cnt[2] >> 1;         // cnt[2] / 2
        cnt[2] = cnt[2] & 1;

        if(cnt[1] <= cnt[3]) {
            ans += cnt[1];
            ans += cnt[2];
            ans += cnt[3] - cnt[1];
        }
        else {                      // cnt[1] > cnt[3]
            ans += cnt[3];
            cnt[1] -= cnt[3];
            ans += cnt[1] >> 2;     // cnt[1] / 4
            cnt[1] %= 4;

            if(cnt[1] + cnt[2]*2 > 0)
                ans += (cnt[1] + cnt[2]*2 <= 4)? 1 : 2;
        }

        printf("%d\n", ans);
    }

    return 0;
}
