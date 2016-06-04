#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, d;
        scanf("%d %d", &n, &d);

        int tmp = 0, ans = 0;

        do {
            tmp = (tmp * 10 + d) % n;
            ++ans;
        } while(tmp);

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
