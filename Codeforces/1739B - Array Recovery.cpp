// ==================================================
// Problem  :   1739B - Array Recovery
// Run time :   0.015 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <vector>
using namespace std;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        vector<int> a(n);
        scanf("%d", &a[0]);

        bool isMultiplePossilbe = false;

        for (int i = 1; i < n; ++i) {
            int d;
            scanf("%d", &d);

            if (!isMultiplePossilbe) {
                if (d == 0 || a[i - 1] - d < 0) {
                    a[i] = a[i - 1] + d;
                } else {
                    isMultiplePossilbe = true;
                }
            }
        }

        if (isMultiplePossilbe) {
            printf("-1\n");
        } else {
            printf("%d", a[0]);

            for (int i = 1; i < n; ++i) {
                printf(" %d", a[i]);
            }

            printf("\n");
        }
    }

    return 0;
}
