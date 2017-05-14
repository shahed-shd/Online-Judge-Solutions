// ==================================================
// Problem  :   DCP-324: Special Matrix
// Run time :   0.03 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    while(q--) {
        int m;
        scanf("%d", &m);

        int rt = sqrt(m);

        int r, c;

        if(rt*rt == m and (rt & 1) == (n & 1)) {
            r = c = ((n - rt) / 2) + 1;
            printf("%d, %d\n", r, c);
            continue;
        }
        else {
            int k;

            if(((rt+1) & 1) == (n & 1)) {
                r = c = ((n - (rt+1)) / 2) + 1;
                k = rt + 1;
            }
            else {
                r = c = ((n - (rt+2)) / 2) + 1;
                k = rt + 2;
            }

            int kk = k*k;

            if(kk - m <= k-1) {
                c += kk - m;
                printf("%d, %d\n", r, c);
                continue;
            }

            c += k - 1;
            kk -= k - 1;

            if(kk - m <= k-1) {
                r += kk - m;
                printf("%d, %d\n", r, c);
                continue;
            }

            r += k - 1;
            kk -= k - 1;

            if(kk - m <= k-1) {
                c -= kk - m;
                printf("%d, %d\n", r, c);
                continue;
            }

            c -= k - 1;
            kk -= k - 1;

            r -= kk - m;
            printf("%d, %d\n", r, c);
        }
    }

    return 0;
}
