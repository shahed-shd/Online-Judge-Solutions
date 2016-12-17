// ==================================================
// Problem  :   350 - Pseudo-Random Numbers
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    int z, i, m, l, tc = 0;

    while(scanf("%d %d %d %d", &z, &i, &m, &l), z || i || m || l) {
        l = (z * l + i) % m;
        int s = l, ans = 0;

        do {
            l = (z * l + i) % m;
            ++ans;
        } while(l != s);

        printf("Case %d: %d\n", ++tc, ans);
    }

    return 0;
}
