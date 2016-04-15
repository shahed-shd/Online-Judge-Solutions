#include <cstdio>
using namespace std;

typedef     long long   LL;

int main()
{
    LL n;

    while(scanf("%lld", &n), n >= 0)
        printf("%lld\n", n * (n+1) / 2 + 1);

    return 0;
}
