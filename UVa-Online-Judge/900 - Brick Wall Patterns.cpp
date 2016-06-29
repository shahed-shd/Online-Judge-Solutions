#include <cstdio>
using namespace std;

typedef     long long       LL;

int main()
{
    LL memo[51] = {0, 1, 2};

    for(int i = 3; i <= 50; ++i)
        memo[i] = memo[i-1] + memo[i-2];


    int n;

    while(scanf("%d", &n), n)
        printf("%lld\n", memo[n]);

    return 0;
}
