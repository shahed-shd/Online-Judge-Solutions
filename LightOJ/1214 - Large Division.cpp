#include <cstdio>
using namespace std;

typedef     long long       LL;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        char str[210];
        LL q;

        scanf("%s %lld", str, &q);

        if(q < 0) q = -q;

        LL dividend = 0;

        for(int i = (str[0] == '-'); str[i]; ++i) {
            dividend = dividend * 10 + (str[i] - '0');
            dividend = dividend % q;
        }

        printf("Case %d: %s\n", tc, ((dividend)? "not divisible" : "divisible"));
    }

    return 0;
}
