// ==================================================
// Problem  :   1192 - Left Right
// Run time :   0.004 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; ++tc) {
        int k;
        scanf("%d", &k);

        int g, w, xorRes = 0;

        while(k--) {
            scanf("%d %d", &g, &w);
            xorRes ^= w - g - 1;
        }

        printf("Case %d: %s\n", tc, (xorRes)? "Alice" : "Bob");
    }

    return 0;
}
