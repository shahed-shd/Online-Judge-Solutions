// ==================================================
// Problem  :   1216D - Swords
// Run time :   0.077 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;


typedef     long long       LL;


const int MAXN = 2e5 + 3;

int a[MAXN];


int gcd(int m, int n)
{
    while (n != 0) {
	    int t = m % n;
	    m = n;
	    n = t;
	}

    return m;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }

    int mx = *max_element(a, a+n);

    int z = mx - a[0];
    for(int i = 1; i < n; ++i) {
        z = gcd(z, mx - a[i]);
    }

    LL a_sum = accumulate(a, a+n, 0LL);
    LL y = (LL(mx) * n - a_sum) / z;

    printf("%lld %d\n", y, z);

    return 0;
}
