// ==================================================
// Problem  :   1029 - Matrix Summation
// Run time :   0.450 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

#define     offset(x)       (x & (-x))

typedef     long long       LL;

const int MAXN = 1024 + 3;

int n;
LL mat[MAXN][MAXN];

void fill_mat(int upto)
{
    for(int i = 0; i <= upto; ++i)
        fill(&mat[i][0], &mat[i][upto+1], 0);
}

void update(int x, int y, LL val)
{
    while(x <= n) {
        int yy = y;
        while(yy <= n) {
            mat[x][yy] += val;
            yy += offset(yy);
        }

        x += offset(x);
    }
}

LL query(int x, int y)
{
    LL sum = 0;

    while(x > 0) {
        int yy = y;
        while(yy > 0) {
            sum += mat[x][yy];
            yy -= offset(yy);
        }

        x -= offset(x);
    }

    return sum;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        fill_mat(n+1);

        char cmd[5];
        int x1, y1, x2, y2;
        LL val;

        while(true) {
            scanf("%s", cmd);

            if(cmd[0] == 'E') {
                putchar('\n');
                break;
            }
            else if(cmd[2] == 'T') {
                scanf("%d %d %lld", &x1, &y1, &val);
                ++x1, ++y1;
                LL tmp = query(x1, y1) - query(x1, y1-1) - query(x1-1, y1) + query(x1-1, y1-1);
                update(x1, y1, -tmp+val);
            }
            else {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                ++x1, ++y1, ++x2, ++y2;
                val = query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
                printf("%lld\n", val);
            }
        }
    }

    return 0;
}
