#include <cstdio>
#include <cstdint>
#include <algorithm>
using namespace std;

#define     grid(i,j)   (*(grid+n*i+j))

int8_t m, n;
int8_t x[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int8_t y[] = {0, 0, 1, -1, 1, 1, -1, -1};
bool *grid;

void flood_fill(int r, int c)
{
    if(r < 0 || r >= m || c < 0 || c >= n) return;
    if(!grid(r,c)) return;

    grid(r,c) = false;

    for(int i = 0; i < 8; ++i)
        flood_fill(r+x[i], c+y[i]);
}

int main()
{
    //freopen("in", "r", stdin);

    while(scanf("%hhd %hhd", &m, &n) && m != 0) {
        grid = new bool [m*n];
        fill(grid, grid+m*n, false);

        char ch;
        getchar();

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                ch = getchar();
                if(ch == '@') grid(i,j) = true;
            }
            getchar();
        }

        int cnt = 0;

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid(i, j)) ++cnt, flood_fill(i, j);

        printf("%d\n", cnt);

        delete [] grid;
    }

    return 0;
}
