// ==================================================
// Problem  :   1711A - Perfect Permutation
// Run time :   0.015 sec
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

    while(t--) {
        int n;
        scanf("%d", &n);

        printf("%d", n);

        for (int i = 1; i < n; ++i) {
            printf(" %d", i);
        }
        
        putchar('\n');
    }

    return 0;
}
