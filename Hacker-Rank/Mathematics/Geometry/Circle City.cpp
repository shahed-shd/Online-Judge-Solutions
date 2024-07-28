// ==================================================
// Problem  :   Circle City
// Score    :   30 /30
// Language :   C++14
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int d, k;
        scanf("%d %d", &d, &k);

        int r = sqrt(d);
        int latticePointCount = 0;

        for (int x = 0; x <= r; ++x) {
            int y = sqrt(d - x * x);

            if (x * x + y * y == d) {
                ++latticePointCount;
            }
        }

        latticePointCount *= 4; // 4 quadrants

        if (r * r == d) {
            // Points on X-axis and Y-axis already taken twice
            latticePointCount -= 4;
        }

        printf(k < latticePointCount ? "impossible\n" : "possible\n");
    }

    return 0;
}
