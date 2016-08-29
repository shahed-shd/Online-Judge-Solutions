// ==================================================
// Problem  :   1088 - Points in Segments
// Run time :   0.272 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 3;

int points[MAXN];

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, q;
        scanf("%d %d", &n, &q);

        for(int i = 0; i < n; ++i)
            scanf("%d", points+i);

        printf("Case %d:\n", tc);
        int a, b;

        while(q--) {
            scanf("%d %d", &a, &b);

            int* s = lower_bound(points, points+n, a);
            int* t = upper_bound(points, points+n, b);

            printf("%d\n", t-s);
        }
    }

    return 0;
}


// -------------------- Alternatively --------------------
// Run time :   0.272 sec.
/*
#include <cstdio>
using namespace std;

const int MAXN = 1e5 + 3;

int points[MAXN];

int bound_index(int s, int t, int val, bool flag)
{
    while(s <= t) {
        int mid = (s + t) >> 1;

        if(points[mid] == val) return mid;
        if(points[mid] < val) s = mid + 1;
        else t = mid - 1;
    }

    return (flag)? t : s;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, q;
        scanf("%d %d", &n, &q);

        for(int i = 0; i < n; ++i)
            scanf("%d", points+i);

        printf("Case %d:\n", tc);
        int a, b;

        while(q--) {
            scanf("%d %d", &a, &b);

            int s = bound_index(0, n-1, a, false);
            int t = bound_index(0, n-1, b, true);

            printf("%d\n", t-s+1);
        }
    }

    return 0;
}
*/
