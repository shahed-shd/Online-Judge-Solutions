#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int dp[(1<<12)+3];

inline int Set(int n, int pos) { return n | (1<<pos); }
inline int Reset(int n, int pos) { return n & ~(1<<pos); }
inline bool Check(int n, int pos) { return n & (1<<pos); }

int fn(int mask)
{
    if(dp[mask] != -1) return dp[mask];

    int mini = INT_MAX;
    bool isMoved = false;

    for(int i = 0; i < 12; ++i) {
        if(Check(mask, i) == 0) {
            if(i-2 >= 0 && Check(mask, i-1) == 1 && Check(mask, i-2) == 1) {
                int tmp = Set(mask, i);
                tmp = Reset(tmp, i-1);
                tmp = Reset(tmp, i-2);

                isMoved = true;
                mini = min(mini, fn(tmp));
            }

            if(i+2 < 12 && Check(mask, i+1) == 1 && Check(mask, i+2) == 1) {
                int tmp = Set(mask, i);
                tmp = Reset(tmp, i+1);
                tmp = Reset(tmp, i+2);

                isMoved = true;
                mini = min(mini, fn(tmp));
            }
        }
    }

    if(!isMoved) {
        mini = 0;
        for(int i = 0; i < 12; ++i)
            if(Check(mask, i)) ++mini;
    }

    return dp[mask] = mini;
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d\n", &tc);

    while(tc--) {
        char str[15];
        fgets(str, sizeof(str), stdin);

        int mask = 0;

        for(int i = 0; i < 12; ++i)
            if(str[i] == 'o')
                mask = Set(mask, i);

        fill_n(dp, (1<<12)+3, -1);

        printf("%d\n", fn(mask));
    }

    return 0;
}
