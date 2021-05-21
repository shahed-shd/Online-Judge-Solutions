// ==================================================
// Problem  :   1525A - Potion-making
// Run time :   0.015 sec
// Language :   C++17
// ==================================================


#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int k;
        scanf("%d", &k);

        int g = gcd(k, 100 - k);

        printf("%d\n", k / g + (100 - k) / g);
    }

    return 0;
}
