// ==================================================
// Problem  :   1261 - K-SAT Problem
// Run time :   0.004 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <bitset>
using namespace std;

const int MAXN = 30 + 3;

int n, k;
int wishes[MAXN][MAXN];
bitset<MAXN> isTaken;

int isValid()
{
    for(int i = 0; i < n; ++i) {
        int *wish = wishes[i];
        bool isHappy = false;

        for(int j = 0; j < k; ++j) {
            if((wish[j] > 0 && isTaken[wish[j]]) || (wish[j] < 0 && !isTaken[-wish[j]])) {
                isHappy = true;
                break;
            }
        }

        if(!isHappy) return false;
    }

    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int m;
        scanf("%d %d %d", &n, &m, &k);

        for(int i = 0; i < n; ++i) {
            int *wish = wishes[i];

            for(int j = 0; j < k; ++j)
                scanf("%d", wish+j);
        }

        int p, obj;
        scanf("%d", &p);

        isTaken.reset();

        for(int i = 0; i < p; ++i) {
            scanf("%d", &obj);
            isTaken[obj] = true;
        }

        printf("Case %d: %s\n", tc, ((isValid())? "Yes" : "No"));
    }

    return 0;
}
