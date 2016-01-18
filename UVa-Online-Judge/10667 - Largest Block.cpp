#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int s, b;

        scanf("%d %d", &s, &b);

        int table[s][s];
        fill(&table[0][0], &table[s][0], 1);

        int r1, c1, r2, c2;

        while(b--) {
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            --r1, --c1, --r2, --c2;

            for(int i = r1; i <= r2; ++i)
                for(int j = c1; j <= c2; ++j)
                    table[i][j] = 0;
        }

        for(int i = 1; i < s; ++i)
            for(int j = 0; j < s; ++j)
                if(table[i][j])
                    table[i][j] += table[i-1][j];

        int mx = 0, tmp, sum, j1;

        for(int i = 0; i < s; ++i) {
            for(int j = 0; j < s; ++j) {
                if(table[i][j]) {
                    sum = tmp = table[i][j];

                    j1 = j;
                    while(++j1 < s && table[i][j1] >= tmp)
                        sum += tmp;

                    j1 = j;
                    while(--j1 >= 0 && table[i][j1] >= tmp)
                        sum += tmp;

                    mx = max(mx, sum);
                }
            }
        }

        printf("%d\n", mx);
    }

    return 0;
}
