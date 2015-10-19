#include <cstdio>
using namespace std;

int findRes(int n)
{
    if(n == 0) return 0;

    int countNumbers = (n/3) * 2;
    if(n % 3 == 2) ++countNumbers;

    return countNumbers;
}

int main()
{
    int t, a, b;

    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &a, &b);

        printf("Case %d: %d\n", tc, findRes(b) - findRes(a-1));
    }

    return 0;
}
