#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef     pair<char, int>     ci;
#define     table(i,j)      (*(table+col*i+j))

const int dr[] = {0, 0, -1, 1};
const int dc[] = {-1, 1, 0, 0};

int row, col;
char *table;

char fill_ch;
int cnt;

void flood_fill(int r, int c)
{
    if(r < 0 || r >= row || c < 0 || c >= col) return;
    if(table(r, c) != fill_ch) return;

    ++cnt;
    table(r, c) = '.';

    for(int i = 0; i < 4; ++i)
        flood_fill(r+dr[i], c+dc[i]);
}

int main()
{
    //freopen("in", "r", stdin);

    int tc = 0;

    while(scanf("%d %d", &row, &col), row != 0 || col != 0) {
        table = new char [row*col];
        getchar();

        for(int i = 0; i < row; ++i)
            scanf("%s\n", table+col*i);

        vector<ci> ans;

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(table(i, j) != '.') {
                    fill_ch = table(i, j);
                    cnt = 0;

                    flood_fill(i, j);
                    ans.push_back(ci(fill_ch, cnt));
                }
            }
        }

        sort(ans.begin(), ans.end(), [](ci a, ci b) { return ((a.second != b.second)? (a.second > b.second) : (a.first < b.first)); });

        printf("Problem %d:\n", ++tc);

        for(auto& pr : ans)
            printf("%c %d\n", pr.first, pr.second);

        delete [] table;
    }

    return 0;
}
