#include <cstdio>
using namespace std;

int  main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int x1, y1, x2, y2, m, x, y;;

        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &m);

        printf("Case %d:\n", tc);

        while(m--) {
            scanf("%d %d", &x, &y);
            puts((x1 < x && x < x2 && y1 < y && y < y2)? "Yes" : "No");
        }
    }

    return 0;
}
