// ==================================================
// Problem  :   1389 - Scarecrow
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

const int MAXN = 100 + 3;

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    char land[MAXN];

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        scanf("%s", land);

        int i = 0, cnt = 0;

        while(i < n) {
            if(land[i] == '.') {
                ++cnt;
                i += 3;
            }
            else ++i;
        }

        printf("Case %d: %d\n", tc, cnt);
    }

    return 0;
}
