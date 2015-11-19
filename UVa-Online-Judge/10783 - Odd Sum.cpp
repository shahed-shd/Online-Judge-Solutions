#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int a, b;
        scanf("%d %d", &a, &b);

        if(!(a%2)) ++a;
        if(!(a%2)) --b;

        int ans = 0, n = (b-a)/2 + 1;

        if(a <= b) ans = n*(a+n-1);

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
