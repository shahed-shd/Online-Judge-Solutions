#include <cstdio>
using namespace std;

typedef     long long   LL;

LL m;
LL b_mod_m;

LL fn(LL b, LL p)
{
    if(p == 0) return 1;

    if(p & 1) return ((fn(b, p-1) % m) * b_mod_m) % m;
    else {
        LL temp = fn(b, p/2);
        temp %= m;
        return (temp * temp) % m;
    }
}

int main()
{
    LL b, p;

    while(scanf("%lld %lld %lld", &b, &p, &m) == 3) {
        b_mod_m = b % m;
        printf("%lld\n", fn(b, p));
    }

    return 0;
}
