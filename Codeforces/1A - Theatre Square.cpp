#include <cstdio>
using namespace std;

int  main()
{
    //freopen("in", "r", stdin);

    long long n, m, a;

    while(scanf("%lld %lld %lld", &n, &m, &a) != EOF) {
        long long len, wid;

        len = n / a + ((n%a)? 1 : 0);
        wid = m / a + ((m%a)? 1 : 0);

        printf("%lld\n", len * wid);
    }

    return 0;
}
