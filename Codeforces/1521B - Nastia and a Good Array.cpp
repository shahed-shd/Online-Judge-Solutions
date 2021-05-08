// ==================================================
// Problem  :   1521B - Nastia and a Good Array
// Run time :   0.140 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 3;
const int P = 1e9 + 7;

int a[MAXN];

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }

        printf("%d\n", n / 2);

        for (int i = 2; i <= n; i += 2) {
            printf("%d %d %d %d\n", i - 1, i, min(a[i - 1], a[i]), P);
        }
    }

    return 0;
}
