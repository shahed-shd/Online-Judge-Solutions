// ==================================================
// Problem  :   1525B - Permutation Sort
// Run time :   0.031 sec
// Language :   C++17
// ==================================================


#include <cstdio>
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

        int a1, ax, an;
        bool isSorted = true;

        scanf("%d", &a1);
        if(a1 != 1) isSorted = false;

        for(int i = 2; i < n; ++i) {
            scanf("%d", &ax);
            if(ax != i) isSorted = false;
        }

        scanf("%d", &an);
        if(an != n) isSorted = false;

        int ans;

        if(isSorted) {
            ans = 0;
        } else if(a1 == 1 || an == n) {
            ans = 1;
        } else if(a1 == n && an == 1) {
            ans = 3;
        } else {
            ans = 2;
        }

        printf("%d\n", ans);
    }

    return 0;
}
