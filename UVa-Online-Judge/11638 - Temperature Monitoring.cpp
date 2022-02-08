// ==================================================
// Problem  :   11638 - Temperature Monitoring
// Run time :   0.000 sec
// Language :   C++11
// ==================================================


#include <cstdio>
using namespace std;


typedef     long long       LL;


inline bool checkBit(int n, int pos) { return n & (1 << pos); }


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; ++tc) {
        int m, s, thresholds[4], c, k;
        scanf("%d %d", &m, &s);

        for (int i = 0; i < 4; ++i) {
            scanf("%d", thresholds + i);
        }

        scanf("%d %d", &c, &k);

        LL currTime = 0;
        bool ans[4] = {false, false, false, false};

        while(k--) {
            int time, temp;
            scanf("%d %d", &time, &temp);

            int left = currTime, right = currTime + time;
            int recentRead = right / m * m;

            if (s <= recentRead && left <= recentRead) {
                for (int i = 0; i < 4; ++i) {
                    if (checkBit(c, i)) {
                        bool ishighTrigger = checkBit(c, 4 + i);
                        
                        if ((!ishighTrigger && temp < thresholds[i]) || (ishighTrigger && thresholds[i] < temp)) {
                            ans[i] = true;
                        } 
                    }
                }
            }

            currTime = right;
        }

        printf("Case %d:", tc);

        for (int i = 0; i < 4; ++i) {
            printf(" %s", ans[i]? "yes" : "no");
        }

        printf("\n");
    }

    return 0;
}
