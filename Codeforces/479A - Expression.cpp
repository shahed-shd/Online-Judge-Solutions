// ==================================================
// Problem  :   479A - Expression
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;

    while(scanf("%d %d %d", &a, &b, &c) != EOF) {
        int mx = a+b+c;
        mx = max(mx, a+b*c);
        mx = max(mx, (a+b)*c);
        mx = max(mx, a*b+c);
        mx = max(mx, a*(b+c));
        mx = max(mx, a*b*c);

        printf("%d\n", mx);
    }

    return 0;
}
