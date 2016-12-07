// ==================================================
// Problem  :   546A - Soldier and Bananas
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    int k, n, w;

    while(~scanf("%d %d %d", &k, &n, &w)) {
        int ans = ((k * w * (w + 1)) / 2) - n;
        printf("%d\n", (ans < 0)? 0 : ans);
    }

    return 0;
}
