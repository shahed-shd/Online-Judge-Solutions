// ==================================================
// Problem  :   1266 - Points in Rectangle
// Run time :   0.288 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;

#define     offset(x)       (x & (-x))

const int MAXN = 1000 + 3;

int tree[MAXN][MAXN];

void update(int x, int y, int val)
{
    while(x < MAXN) {
        int yy = y;

        while(yy < MAXN) {
            tree[x][yy] += val;
            yy += offset(yy);
        }

        x += offset(x);
    }
}

int query(int x, int y)
{
    int sum = 0;

    while(x > 0) {
        int yy = y;

        while(yy > 0) {
            sum += tree[x][yy];
            yy -= offset(yy);
        }

        x -= offset(x);
    }

    return sum;
}

inline int get(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int q;
        scanf("%d", &q);

        printf("Case %d:\n", tc);

        bitset<MAXN> isPointed[MAXN];
        int type, x1, y1, x2, y2;

        fill(&tree[0][0], &tree[MAXN][0], 0);

        while(q--) {
            scanf("%d", &type);

            if(type == 0) {
                scanf("%d %d", &x1, &y1);
                ++x1, ++y1;

                if(!isPointed[x1][y1]) {
                    isPointed[x1][y1] = true;
                    update(x1, y1, 1);
                }
            }
            else {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                ++x1, ++y1, ++x2, ++y2;

                printf("%d\n", get(x1, y1, x2, y2));
            }
        }
    }

    return 0;
}
