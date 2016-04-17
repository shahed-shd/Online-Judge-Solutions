#include <cstdio>
#include <cmath>
using namespace std;

typedef     long long   LL;

int main()
{
    LL n;

    while(scanf("%lld", &n), n) {
        LL s = sqrt(n);

        if(s*s == n) puts("yes");
        else puts("no");
    }

    return 0;
}
