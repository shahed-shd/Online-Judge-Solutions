#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdint>
using namespace std;

#define     pic(i,j)    (*(pic+w*i+j))

int8_t w, h;
int8_t dr[] = {-1, 1, 0, 0};
int8_t dc[] = {0, 0, -1, 1};
char *pic;
int8_t cnt;

void ff(int8_t r, int8_t c)
{
    if(r < 0 || r >= h || c < 0 || c >= w) return;
    if(pic(r, c) != 'X') return;

    pic(r, c) = '*';

    for(int8_t i = 0; i < 4; ++i)
        ff(r+dr[i], c+dc[i]);
}

void flood_fill(int8_t r, int8_t c)
{
    if(r < 0 || r >= h || c < 0 || c >= w) return;
    if(pic(r, c) == '.') return;

    if(pic(r, c) == 'X')
        ++cnt, ff(r, c);

    pic(r, c) = '.';

    for(int8_t i = 0; i < 4; ++i)
        flood_fill(r+dr[i], c+dc[i]);
}

int main()
{
    //freopen("in", "r", stdin);

    size_t throwCount = 0;

    while(scanf("%hhd %hhd", &w, &h) && (w || h)) {
        pic = new char [w*h];

        getchar();
        char ch;

        for(int8_t i = 0; i < h; ++i) {
            for(int8_t j = 0; j < w; ++j) {
                ch = getchar();
                pic(i, j) = ch;
            }
            getchar();
        }

        vector<int8_t> ans;

        for(int8_t i = 0; i < h; ++i) {
            for(int8_t j = 0; j < w; ++j) {
                if(pic(i, j) == '*' || pic(i, j) == 'X') {
                    cnt = 0;
                    flood_fill(i, j);
                    ans.push_back(cnt);
                }
            }
        }

        sort(ans.begin(), ans.end());

        printf("Throw %zu\n", ++throwCount);

        size_t sz = ans.size();

        for(size_t i = 0; i < sz; ++i) {
            if(i) putchar(' ');
            printf("%hhd", ans[i]);
        }
        putchar('\n');
        putchar('\n');

        delete [] pic;
    }

    return 0;
}
