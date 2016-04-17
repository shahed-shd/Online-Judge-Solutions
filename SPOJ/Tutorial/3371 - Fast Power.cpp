#include <cstdio>
using namespace std;

typedef     long long   LL;

LL base, mod;

LL repeatedSqr(LL p)
{
    if(!p) return 1;

    if(p & 1) return (base * repeatedSqr(p-1)) % mod;
    else {
        LL tmp = repeatedSqr(p/2);
        return (tmp * tmp) % mod;
    }
}

int main()
{
    LL p;

    scanf("%Ld %Ld %Ld", &base, &p, &mod);

    base %= mod;

    printf("%Ld\n", repeatedSqr(p));

    return 0;
}
