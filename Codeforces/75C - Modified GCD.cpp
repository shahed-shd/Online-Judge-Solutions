// ==================================================
// Problem  :   75C - Modified GCD
// Run time :   1.840 sec.
// Language :   C++11
// ===================================================

#include <cstdio>
#include <algorithm>
#include <cmath>
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

int get_divisor(int low, int high, int g)
{
    if(g < low) return -1;

    int rt = sqrt(g);
    int ret = -1;

    for(int i = rt; i >= 1; --i) {
        if(g % i == 0) {
            int j = g / i;

            if(low <= i && i <= high) ret = max(ret, i);
            if(low <= j && j <= high) ret = max(ret, j);
        }
    }

    return ret;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int g = gcd(a, b);

    int n;
    scanf("%d", &n);

    int low, high;

    while(n--) {
        scanf("%d %d", &low, &high);
        printf("%d\n", get_divisor(low, high, g));
    }

    return 0;
}
