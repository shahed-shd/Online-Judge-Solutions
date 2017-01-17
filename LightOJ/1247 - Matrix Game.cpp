// ==================================================
// Problem  :   1247 - Matrix Game
// Run time :   0.024 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

int main()
{
    //freopen("in.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; ++tc) {
        int m, n, a;
        scanf("%d %d", &m, &n);

        LL xorRes = 0, sum;

        while(m--) {
            sum = 0;

            for(int i = 0; i < n; ++i) {
                scanf("%d", &a);
                sum += a;
            }

            xorRes ^= sum;
        }

        printf("Case %d: %s\n", tc, (xorRes)? "Alice" : "Bob");
    }

    return 0;
}
