// ==================================================
// Problem  :   346A - Alice and Bob
// Run time :   0.030 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int m, int n)
{
    while(n != 0) {
        int t = m % n;
        m = n;
        n = t;
    }

    return m;
}

int main()
{
    int n;

    while(~scanf("%d", &n)) {
        int tmp;
        scanf("%d", &tmp);

        int mx = tmp, g = tmp;

        for(int i = 1; i < n; ++i) {
            scanf("%d", &tmp);

            mx = max(mx, tmp);
            g = gcd(g, tmp);
        }

        int ans = mx / g - n;

        puts((ans & 1)? "Alice" : "Bob");
    }

    return 0;
}
