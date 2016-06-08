#include <cstdio>
#include <cmath>
using namespace std;

typedef     long long       LL;

LL gcd(LL m, LL n)
{
    while(n != 0) {
        LL t = m % n;
        m = n;
        n = t;
	}

    return m;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL Ax, Ay, Bx, By;
        scanf("%lld %lld %lld %lld", &Ax, &Ay, &Bx, &By);
        printf("Case %d: %lld\n", tc, 1+gcd(abs(Ax-Bx), abs(Ay-By)));
    }

    return 0;
}
