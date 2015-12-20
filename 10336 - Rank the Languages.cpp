#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

#define     table(i,j)      (*(table+w*i+j))
typedef     pair<char, int>     ci;

const int8_t dr[] = {1, -1, 0, 0};
const int8_t dc[] = {0, 0, -1, 1};

int h, w;
char *table;
char fill_ch;

bool myComp(ci a, ci b)
{
    if(a.second == b.second)
        return (a.first < b.first);
    else
        return (a.second > b.second);
}

void flood_fill(int r, int c)
{
    if(r < 0 || r >= h || c < 0 || c >= w) return;
    if(table(r, c) != fill_ch) return;

    table(r, c) = ' ';

    for(int8_t i = 0; i < 4; ++i)
        flood_fill(r+dr[i], c+dc[i]);
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d\n", &h, &w);

        table = new char [h*w];

        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j)
                table(i, j) = getchar();
            getchar();
        }

        unordered_map<char, int> mp;

        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(table(i, j) != ' ') {
                    fill_ch = table(i, j);
                    ++mp[fill_ch];
                    flood_fill(i, j);
                }
            }
        }

        vector<ci> v;

        for(auto it = mp.begin(); it != mp.end(); ++it)
            v.push_back(make_pair(it->first, it->second));

        sort(v.begin(), v.end(), myComp);

        printf("World #%d\n", tc);

        for(auto& pr : v)
            printf("%c: %d\n", pr.first, pr.second);
    }

    return 0;
}
