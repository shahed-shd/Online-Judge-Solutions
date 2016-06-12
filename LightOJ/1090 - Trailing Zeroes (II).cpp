#include <cstdio>
#include <algorithm>
using namespace std;

typedef     long long       LL;

LL how_many_in_fact(int num, int p)
{
    if(num == 0) return 0;
    return (num/p) + how_many_in_fact(num/p, p);
}

LL how_many_in_num(int num, int p)
{
    if(num == 0 || num % p) return 0;
    return 1 + how_many_in_num(num/p, p);
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, r, p, q;
        scanf("%d %d %d %d", &n, &r, &p, &q);

        LL cnt2 = how_many_in_fact(n, 2) - how_many_in_fact(n-r, 2) - how_many_in_fact(r, 2);
        LL cnt5 = how_many_in_fact(n, 5) - how_many_in_fact(n-r, 5) - how_many_in_fact(r, 5);

        cnt2 += how_many_in_num(p, 2) * q;
        cnt5 += how_many_in_num(p, 5) * q;

        printf("Case %d: %lld\n", tc, min(cnt2, cnt5));
    }

    return 0;
}
