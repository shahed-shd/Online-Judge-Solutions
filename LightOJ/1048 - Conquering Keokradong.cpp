// ==================================================
// Problem  :   1048 - Conquering Keokradong
// Run time :   0.048 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

const int MAXN = 1000 + 3;

int dist[MAXN];
int n, k;

bool isPossible(int d)
{
    int dayRemain = k + 1;
    int distReamin = n + 1;
    int camp = 0;

    while(camp <= n) {
        int go = 0;
        while(camp <= n && go + dist[camp] <= d) {
            if(dayRemain == distReamin) return true;
            go += dist[camp++];
            --distReamin;
        }

        --dayRemain;
    }

    return (dayRemain == distReamin);
}

int binSearch(int s, int t)
{
    int ret;

    while(s <= t) {
        int mid = (s + t) >> 1;

        if(isPossible(mid)) {
            ret = mid;
            t = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return ret;
}

void print_ans(int d)
{
    int dayRemain = k + 1;
    int distReamin = n + 1;
    int camp = 0;

    while(camp <= n) {
        int go = 0;
        while(camp <= n && go + dist[camp] <= d) {
            if(dayRemain == distReamin) {
                printf("%d\n", go + dist[camp++]);

                while(camp <= n)
                    printf("%d\n", dist[camp++]);
                return;
            }

            go += dist[camp++];
            --distReamin;
        }

        printf("%d\n", go);
        --dayRemain;
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &n, &k);

        int mx = -1, sum = 0;

        for(int i = 0; i <= n; ++i) {
            scanf("%d", dist+i);

            sum += dist[i];
            if(dist[i] > mx) mx = dist[i];
        }

        int cost = binSearch(mx, sum);

        printf("Case %d: %d\n", tc, cost);
        print_ans(cost);
    }

    return 0;
}
